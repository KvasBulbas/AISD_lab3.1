#pragma once
#include "BinaryTree.h"

class SearchTree:public BinaryTree
{
public:
	SearchTree();
	~SearchTree();

	Node* addNode(const int k) override;
	Node* addNode(Node* nd, const int k) override;

	Node* getMin() const;
	Node* getMin(Node* nd) const;

	Node* getMax() const;
	Node* getMax(Node* nd) const;

	Node* nlrSearch(const int k) const override;
	Node* nlrSearch(Node* nd, const int k) const override;

	bool deleteNodeByKey(const int k) override;
	bool deleteNodeByKey(Node* nd, const int k) override;


	
};

