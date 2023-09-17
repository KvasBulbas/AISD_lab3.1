#include "SearchTree.h"
#include <iostream>

SearchTree::SearchTree()
{

}

SearchTree::~SearchTree()
{
	BinaryTree::clearTree();
}

BinaryTree::Node* SearchTree::addNode(const int k)
{
	return addNode(_root, k);
}

BinaryTree::Node* SearchTree::addNode(Node* nd, const int k)
{
	if (nd == nullptr)
		if (_root == nullptr)
		{
			_root = new Node(k);
			return _root;
		}
		else
			return nullptr;
	
	if (k < nd->key)
	{
		if (nd->left)
			return addNode(nd->left, k);
		else
		{
			nd->left = new Node(k);
			return nd->left;
		}
	}
	else
		if (nd->right)
			return addNode(nd->right, k);
		else
		{
			nd->right = new Node(k);
			return nd->right;
		}

}
