#include "SearchTree.h"
#include "SearchTreeTester.h"
#include <cassert>



SearchTreeTester::SearchTreeTester(const bool useConsoleOutput)
    : BinaryTreeTester(useConsoleOutput)
{}


void SearchTreeTester::check_addAndCount(const BinaryTree* tree, const int size)
{
    BinaryTreeTester::check_addAndCount(tree, size);
    assert(isSearchTree(tree));
    
}

void SearchTreeTester::check_deleteNodeByKey(const BinaryTree* tree, const int size)
{
    BinaryTreeTester::check_deleteNodeByKey(tree, size);


    assert(isSearchTree(tree));
    
}

void SearchTreeTester::check_clear(const BinaryTree* tree, const int size)
{
    BinaryTreeTester::check_clear(tree, size);
    assert(isSearchTree(tree));
}


SearchTree* SearchTreeTester::allocateTree()
{
    return new SearchTree;
}

void SearchTreeTester::deallocateTree(SearchTree* tree)
{
    tree->clearTree();
}


void SearchTreeTester::check_assign(const BinaryTree& tree1, const BinaryTree& tree2)
{
    assert(tree1.getHeight() == tree2.getHeight());
    assert(tree1.getCountOfNode() == tree2.getCountOfNode());
    BinaryTree::Node* root1 = tree1.getRoot();
    BinaryTree::Node* root2 = tree1.getRoot();

    
    assert(isSearchTree(&tree1));
    assert(isSearchTree(&tree2));

    check_assignOfNode(root1, root2);

}


void SearchTreeTester::assign()
{
    SearchTree tree1;

    tree1.addNode(105);
    for (int i = 0; i < m_maxSize; i++)
        tree1.addNode(rand() % 200 + 10);

    SearchTree tree2 = tree1;

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

    check_assign(tree1, tree2);

    std::cout << "BinaryTreeTester::assign ended. Press any key to continue..." << std::endl;
    getchar();
    
}


void SearchTreeTester::deleteNodeByKey()
{
    SearchTree* tree = allocateTree();

    tree->addNode(105);
    for (int i = 0; i < m_maxSize; i++)
        tree->addNode(rand() % 200 + 10);

    tree->printTree();

    std::vector<int> vec = tree->getTreeAsVector();

    for (int i = 0, j = vec.size() - 1; i < vec.size(); i++, j--)
    {
        std::cout << "\nkey: " << vec[i] << '\n';
        tree->deleteNodeByKey(vec[i]);
        tree->printTree();

        assert(tree->nlrSearch(vec[i]) == nullptr);

        check_deleteNodeByKey(tree, j);

    }
    deallocateTree(tree);

    std::cout << "BinaryTreeTester::deleteNodeByKey ended. Press any key to continue..." << std::endl;
    getchar();
}
