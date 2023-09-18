#pragma once
#include "BinaryTree.h"

class BinaryTreeTester
{
public:
    BinaryTreeTester(const bool useConsoleOutput);

    ~BinaryTreeTester() = default;

    virtual void test(const int size);

protected:
    virtual BinaryTree* allocateTree();
    virtual void check_addAndCount(const BinaryTree* tree, const int size);

    virtual void check_clear(const BinaryTree* tree, const int size);
    virtual void check_assign(const BinaryTree& tree1, const BinaryTree& tree2);
    virtual void check_assignOfNode(const BinaryTree::Node* node1, const BinaryTree::Node* node2);
    virtual void check_height(const BinaryTree& tree, const int size);
    virtual void check_deleteNodeByKey(const BinaryTree* tree, const int size);



private:
    virtual void deleteNodeByKey();
    void deallocateTree(BinaryTree* tree);
    void addAndCount();
    void destructor();
    void clear();
    virtual void assign();
    void height();
    void height_trivialCases();


protected:
    int m_maxSize;
    bool m_useConsoleOutput;


};

