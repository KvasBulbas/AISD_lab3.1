#pragma once
#include "BinaryTreeTester.h"
#include "BinaryTree.h"
#include <iostream>

class SearchTreeTester : public BinaryTreeTester
{
public:
    SearchTreeTester(const bool useConsoleOutput);
    ~SearchTreeTester() = default;


private:


protected:
    
    SearchTree* allocateTree() override;
	

    void check_addAndCount(const BinaryTree* tree, const int size) override;
    void check_deleteNodeByKey(const BinaryTree* tree, const int size) override;
    void check_clear(const BinaryTree* tree, const int size) override;
	void check_assign(const BinaryTree& tree1, const BinaryTree& tree2) override;


private:
	void addAndCount();
	void deallocateTree(SearchTree* tree);
	void assign() override;
	void deleteNodeByKey() override;


	bool isSearchTree(const BinaryTree* tree)
	{

		BinaryTree::Node* nd = tree->getRoot();
		if (nd)
		{
			if (nd->left)
			{
				if (nd->key < nd->left->key)
				{
					std::cout << "\nwrong right key: " << nd->key << '\n';
					return false;
				}
				return nd->left;
			}

			if (nd->right)
			{
				if (nd->key > nd->right->key)
				{
					std::cout << "\nwrong right key: " << nd->key << '\n';
					return false;
				}
				return nd->right;
			}
		}
		return true;


	}



};

