#include "BinaryTreeTester.h"
#include <cassert>
#include <iostream>
#include <vector>

BinaryTreeTester::BinaryTreeTester(const bool useConsoleOutput)
    : m_useConsoleOutput(useConsoleOutput)
{}

void BinaryTreeTester::test(const int size)
{
    m_maxSize = size;
    addAndCount();
    destructor();
    clear();
    deleteNodeByKey();
    height();
    assign();
    
}

BinaryTree* BinaryTreeTester::allocateTree()
{
    return new BinaryTree;
}

void BinaryTreeTester::deallocateTree(BinaryTree* tree)
{
    delete tree;
}

void BinaryTreeTester::addAndCount()
{
    BinaryTree* tree = allocateTree();
    check_addAndCount(tree, 0);

    for (int i = 0; i < m_maxSize; ++i) {
        tree->addNode(i);
        check_addAndCount(tree, i + 1);
    }

    deallocateTree(tree);

    std::cout << "BinaryTreeTester::addAndCount ended. Press any key to continue..." << std::endl;
    getchar();
}

void BinaryTreeTester::check_addAndCount(const BinaryTree* tree, const int size)
{
    assert(tree->getCountOfNode() == size);
}

void BinaryTreeTester::destructor()
{
    const int runsCount = 200;
    for (int i = 0; i < runsCount; i++)
    {
        BinaryTree* tree = allocateTree();
        for (int i = 0; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        deallocateTree(tree);
    }
    std::cout << "BinaryTreeTester::destructor ended. Press any key to continue..." << std::endl;
    getchar();

}


void BinaryTreeTester::clear()
{
    BinaryTree* tree = allocateTree();
    for (int i = 0; i < 200; i++)
    {
        for (int i = 0; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        tree->clearTree();
        check_clear(tree, 0);
    }
    deallocateTree(tree);
    std::cout << "BinaryTreeTester::clear ended. Press any key to continue..." << std::endl;
    getchar();
}

void BinaryTreeTester::check_clear(const BinaryTree* tree, const int size)
{
    assert(tree->getCountOfNode() == size);
}

void BinaryTreeTester::height()
{
    height_trivialCases();


    std::cout << "BinaryTreeTester::height ended. Press any key to continue..." << std::endl;
    getchar();
}


void BinaryTreeTester::check_height(const BinaryTree& tree, const int height)
{
    assert(tree.getHeight() == height);
}

void BinaryTreeTester::height_trivialCases()
{
    BinaryTree tree;
    check_height(tree, 0);
    tree.addNode(0);
    check_height(tree, 1);
}


void BinaryTreeTester::deleteNodeByKey()
{

    BinaryTree* tree = allocateTree();

    for (int i = 0; i < m_maxSize; i++)
    {
        tree->addNode(i);
    }

    

    for (int i = 0, j = m_maxSize - 1; i < m_maxSize; i++, j--)
    {
        assert(tree->nlrSearch(i) != nullptr);
        //std::cout << "number: " << i << '\n';
        //tree->printTree();*/
        tree->deleteNodeByKey(i);
        /*tree->printTree();
        std::cout << "\nsize: " << tree->getCountOfNode() << " true size: " << j << '\n';*/

        

        check_deleteNodeByKey(tree, j);
        /*if (tree->getCountOfNode() != j)
            break;*/

        assert(tree->nlrSearch(i) == nullptr);
    }
    deallocateTree(tree);

    std::cout << "BinaryTreeTester::deleteNodeByKey ended. Press any key to continue..." << std::endl;
    getchar();

}

void BinaryTreeTester::check_deleteNodeByKey(const BinaryTree* tree, const int size)
{

    assert(tree->getCountOfNode() == size);
}

void BinaryTreeTester::assign()
{

    BinaryTree tree1;

    tree1.addNode(105);
    for (int i = 0; i < m_maxSize; i++)
        tree1.addNode(rand() % 200 + 10);

    BinaryTree tree2 = tree1;

    check_assign(tree1, tree2);

    std::vector<int> tree1Nodes = tree1.getTreeAsVector();
    std::vector<int> tree2Nodes = tree2.getTreeAsVector();

    assert(tree1Nodes.size() == tree2Nodes.size());
    for (int i = 0; i < tree1Nodes.size(); i++)
        assert(tree1Nodes[i] == tree2Nodes[i]);

    tree1.clearTree();
    tree2.clearTree();

    tree1.addNode(105);
    for (int i = 0; i < m_maxSize; i++)
        tree1.addNode(rand() % 200 + 10);

    tree2 = tree1;

    tree1.printTree();
    tree2.printTree();

    check_assign(tree1, tree2);

    std::cout << "BinaryTreeTester::assign ended. Press any key to continue..." << std::endl;
    getchar();

}

void BinaryTreeTester::check_assign(const BinaryTree& tree1, const BinaryTree& tree2)
{
    assert(tree1.getHeight() == tree2.getHeight());
    assert(tree1.getCountOfNode() == tree2.getCountOfNode());
    BinaryTree::Node* root1 = tree1.getRoot();
    BinaryTree::Node* root2 = tree1.getRoot();
    check_assignOfNode(root1, root2);

}

void BinaryTreeTester::check_assignOfNode(const BinaryTree::Node* node1, const BinaryTree::Node* node2)
{
    assert(node1->key == node2->key);

    if (node1->left && node2->left)
        check_assignOfNode(node1->left, node2->left);
    if (node1->right && node2->right)
        check_assignOfNode(node1->right, node2->right);

}
