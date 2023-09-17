#pragma once
#include<vector>

class BinaryTree
{
public:
	struct Node;
	BinaryTree() = default;
	virtual ~BinaryTree();
	BinaryTree(const BinaryTree& tree);

	void clearTree();
	void clearTree(Node* subTreeRoot);

	bool isEmpty() const;

	Node* addNode(int k);
	Node* addNode(Node* nd, int k);

	int getHeight() const;
	int getHeight(Node* nd) const;

	void printTree();
	void printTree(Node* nd);

	Node* nlrSearch(const int k) const;
	Node* nlrSearch(Node* nd, const int k) const;

	Node* findParent(Node* nd) const;

	Node* getFreeNode() const;
	Node* getFreeNode(Node* nd) const;

	int getCountOfNode() const;
	int getCountOfNode(Node* nd) const;

	bool deleteNodeByKey(const int k);
	bool deleteNodeByKey(Node* nd, const int k);

	bool deleteNode(Node* nd, Node* parent);

	BinaryTree& operator = (const BinaryTree& outTree);
	void copyTree(Node*& inTree, Node* outTree);

	Node* getRoot() const;

	std::vector<int> getTreeAsVector() const;
	std::vector<int> getTreeAsVector(Node* subTreeRoot) const;

protected:
	Node* _root = nullptr;
};


struct BinaryTree::Node
{
	int key = 0;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int k = 0, Node* l = nullptr, Node* r = nullptr)
	{
		key = k;
		left = l;
		right = r;
	}

	~Node() {};
};



