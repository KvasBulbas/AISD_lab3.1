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
	
	if (nd->key == k)
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

BinaryTree::Node* SearchTree::getMin() const
{
	return getMin(_root);
}

BinaryTree::Node* SearchTree::getMin(Node* nd) const
{
	if (nd == nullptr)
		return nullptr;

	if (nd->left)
		return getMin(nd->left);
	else
		return nd;

}


BinaryTree::Node* SearchTree::getMax() const
{
	return getMax(_root);
}

BinaryTree::Node* SearchTree::getMax(Node* nd) const
{
	if (nd == nullptr)
		return nullptr;

	if (nd->right)
		return getMax(nd->right);
	else
		return nd;
}


BinaryTree::Node* SearchTree::nlrSearch(const int k) const
{
	return nlrSearch(_root, k);
}


BinaryTree::Node* SearchTree::nlrSearch(Node* nd, const int k) const
{
	if (nd == nullptr)
		return nullptr;

	if (k == nd->key)
		return nd;

	if (k < nd->key)
		return nlrSearch(nd->left, k);
	else
		return nlrSearch(nd->right, k);

}

bool SearchTree::deleteNodeByKey(const int k)
{
	return deleteNodeByKey(_root, k);
}

bool SearchTree::deleteNodeByKey(Node* nd, const int k)//доделать
{
	Node* toDelete = nlrSearch(nd, k);
	if (nd == nullptr || toDelete == nullptr)
		return false;
	

	Node* parent = findParent(toDelete);

	if (toDelete->left == nullptr && toDelete->right == nullptr)
	{
		if (parent)
			if (parent->left == toDelete)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		else
			_root = nullptr;

		delete toDelete;

		return true;
	}

	if (toDelete->left != nullptr && toDelete->right == nullptr)
	{
		if (parent)
			if (parent->left == toDelete)
				parent->left = toDelete->left;
			else
				parent->right = toDelete->left;
		else
			_root = _root->left;


		delete toDelete;

		return true;
	}

	if (toDelete->left == nullptr && toDelete->right != nullptr)
	{
		if (parent)
			if (parent->left == toDelete)
				parent->left = toDelete->right;
			else
				parent->right = toDelete->right;
		else
			_root = _root->right;

		delete toDelete;

		return true;
	}

	if (toDelete->left != nullptr && toDelete->right != nullptr)
	{
		Node* replacingNode = getMax(toDelete->left);
		Node* replacingNodeParent = findParent(replacingNode);
		if (parent)
			if (parent->left == toDelete)
				parent->left = replacingNode;
			else
				parent->right = replacingNode;
		else
		{
			
			_root = replacingNode;

		}
		
		if (replacingNode == toDelete->left)
			replacingNode->right = toDelete->right;
		else
		{
			replacingNodeParent->right = replacingNode->left;	
			replacingNode->right = toDelete->right;
			replacingNode->left = toDelete->left;
		}
		delete toDelete;

		return true;
	}
}



bool SearchTree::checkTree()
{
	return checkTree(_root);
}

bool SearchTree::checkTree(Node* nd)
{
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