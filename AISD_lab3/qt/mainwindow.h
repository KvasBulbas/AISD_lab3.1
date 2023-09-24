#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <iostream>
#include "binarytree.h"
#include "SearchTree.h"
#include <QMainWindow>
#include<QListWidget>
#include<QLineEdit>
#include <QPushButton>
#include <QGraphicsScene>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clicked_addNode();
    void on_clicked_deleteNode();
    void on_clicked_searchNode();
    void onTreeUpdate();
    void onLvNodeListCurrentRowChanged(int currentRow);

private:
    int nodeRadius = 40;
    void displayError(QString const& msg);
    Ui::MainWindow *ui;
    SearchTree tree;
    BinaryTree::Node* selectedNode = tree.getRoot();
    QGraphicsScene *m_scene = nullptr;

    void printTree();

    void printEllipse(BinaryTree::Node* nd, int posX, int posY);

    int getRange(BinaryTree::Node* nd);




};
#endif // MAINWINDOW_H
