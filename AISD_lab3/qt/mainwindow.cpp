#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include "GraphicsRectItem.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->nodeKey->setValidator(new QIntValidator {INT_MIN, INT_MAX});
    ui->nodeKey->setText("0");

    ui->button_deleteNode->setEnabled(false);

    ui->graphicsView->setScene(m_scene);




    //m_scene->addEllipse(0, 0, 40, 40);
    //m_scene->addEllipse(50, 50, 40, 40);
    //m_scene->addEllipse(-50, 50, 40, 40);


    QObject::connect(ui->button_addNode, &QPushButton::clicked, this, &MainWindow::on_clicked_addNode);
    QObject::connect(ui->button_deleteNode, &QPushButton::clicked, this, &MainWindow::on_clicked_deleteNode);
    QObject::connect(ui->button_searchNode, &QPushButton::clicked, this, &MainWindow::on_clicked_searchNode);
    QObject::connect(ui->nodeList, &QListWidget::currentRowChanged, this, &MainWindow::onLvNodeListCurrentRowChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clicked_addNode()
{
    bool ok;
    int key = ui->nodeKey->text().toInt(&ok);

    if(ok)
    {
        tree.addNode(key);
        ui->button_deleteNode->setEnabled(true);
        onTreeUpdate();
    }
    else
    {
        displayError(QString {"invalid key value: must be an integer"});
    }

}


void MainWindow::on_clicked_deleteNode()
{
    auto selectedNodeParent = tree.findParent(selectedNode);
    tree.deleteNode(selectedNode);
    selectedNode = selectedNodeParent;

    if (tree.isEmpty())
    {
         ui->button_deleteNode->setEnabled(false);
    }



    onTreeUpdate();
}

void MainWindow::on_clicked_searchNode()
{

    bool ok;
    int key = ui->nodeKey->text().toInt(&ok);


    if(ok)
    {
         auto node = tree.getNodes();

         for (int i = 0; i < node.size(); i++)
         {
             if(node[i] == tree.nlrSearch(key))
             {
                ui->nodeList->setCurrentRow(i);
                 return;
             }
         }
         displayError(QString {"node with this key not exist"});

    }
    else
    {
         displayError(QString {"invalid key value: must be an integer"});
    }


}

void MainWindow::onLvNodeListCurrentRowChanged(int currentRow)
{
    auto const nodes = tree.getNodes();

    if (currentRow >= 0 && currentRow < nodes.size())
    {
        selectedNode = nodes[currentRow];
    }
}


void MainWindow::onTreeUpdate()
{
    tree.printTree();

    ui->nodeList->clear();

    for (auto node: tree.getNodes())
    {
        ui->nodeList->addItem( "id: " + QString::number((uintptr_t) node) + " key = " + QString::number(node->key));
    }

    selectedNode = tree.getRoot();
    ui->nodeList->setCurrentRow(0);

    m_scene->clear();
    if(tree.getRoot())
        printTree();

}

void MainWindow::displayError(QString const& msg)
{
    QMessageBox::warning(this, "error", msg);

}



void MainWindow::printTree()
{
    int posX = 0;
    int posY = 0;
    printEllipse(tree.getRoot(), posX, posY);
}

void MainWindow::printEllipse(BinaryTree::Node* nd, int posX, int posY)
{
    int range = getRange(nd);

    GraphicsRectItem *sceneNode = new GraphicsRectItem(QString::number(nd->key));
    sceneNode->setPos(posX, posY);
    sceneNode->setBackgroundColor(Qt::green);


;

    m_scene->addItem(sceneNode);

    if(nd->left)
    {
        m_scene->addLine(posX + 4 , posY + 10,  posX + 4 - range, posY + 50 + 10)->setZValue(-1);//рисуем линию до левой ноды

        std::cout << "range: " <<  range << std::endl;
        printEllipse(nd->left, posX - range, posY + 50 );

    }
    if(nd->right)
    {
        m_scene->addLine(posX + 4 , posY + 10,  posX + 4 + range, posY + 50 + 10)->setZValue(-1);
        std::cout << "range: " <<  range << std::endl;
        printEllipse(nd->right, posX + range, posY + 50);//рисуем линию до правой ноды

    }

}


int MainWindow::getRange(BinaryTree::Node* nd)
{
    int minrange = 10;

    int range = minrange + nodeRadius/2;
    int width = 2 * nodeRadius + 2 * minrange;



    for(int i = 0; i < tree.getHeight(nd) - 2; i++ )//ширина дерева в зависимости от высоты
    {
        width = 2 * width;
        range = width/2 - nodeRadius;
    }


    return range;
}




