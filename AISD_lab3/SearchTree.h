#pragma once
#include "BinaryTree.h"

class SearchTree:public BinaryTree
{
public:
	SearchTree();
	~SearchTree();

	Node* addNode(const int k) override;
	Node* addNode(Node* nd, const int k) override;

	Node* getMin();
	Node* getMin(Node* nd);

	Node* getMax();
	Node* getMax(Node* nd);
	
};

