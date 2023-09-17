#pragma once
#include "BinaryTree.h"

class SearchTree:public BinaryTree
{
public:
	SearchTree();
	~SearchTree();
	Node* addNode(const int k) override;
	Node* addNode(Node* nd, const int k) override;
	

	
};

