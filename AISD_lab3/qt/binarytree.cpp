#include "BinaryTree.h"
#include <iostream>
#include <vector>

void BinaryTree::clearTree(Node* subTreeRoot)
{
	if (subTreeRoot == nullptr)
		return;

	if (subTreeRoot->left)
		clearTree(subTreeRoot->left);
	if (subTreeRoot->right)
		clearTree(subTreeRoot->right);

	if (subTreeRoot == _root)
		_root = nullptr;

	delete subTreeRoot;
}

BinaryTree::~BinaryTree()
{
	if (_root)
		clearTree(_root);
}

void BinaryTree::clearTree()
{
	clearTree(_root);
}

BinaryTree::BinaryTree(const BinaryTree& tree)
{
	_root = new Node();
	_root->key = tree._root->key;
	_root->left = nullptr;
	_root->right = nullptr;


	if (tree._root->left)
		copyTree(_root->left, tree._root->left);
	if (tree._root->right)
		copyTree(_root->right, tree._root->right);
	//this->printTree();
}



bool BinaryTree::isEmpty() const
{
        return _root == nullptr;
}

BinaryTree::Node* BinaryTree::addNode(const int k)
{
	return addNode(_root, k);

}

BinaryTree::Node* BinaryTree::addNode(Node* nd, const int k)
{
	if (nd == nullptr)
		if (_root == nullptr)
		{
			_root = new Node(k);
			return _root;
		}
		else
			return nullptr;


	if (nd->left == nullptr)
	{
		nd->left = new Node(k);
		return nd->left;
	}

	if (nd->right == nullptr)
	{
		nd->right = new Node(k);
		return nd->right;
	}

	if (rand() % 2)
		return addNode(nd->left, k);
	else
		return addNode(nd->right, k);

}

int BinaryTree::getHeight() const
{
	return getHeight(_root);
}

int BinaryTree::getHeight(Node* nd) const
{
	if (nd == nullptr)
		return 0;

	if ((nd->left == nullptr) && (nd->right == nullptr))
		return 1;

	int leftHeight = 0, rightHeight = 0;

	if (nd->left)
		leftHeight = getHeight(nd->left);

	if (nd->right)
		rightHeight = getHeight(nd->right);

	int height;

	if (rightHeight > leftHeight)
		height = rightHeight;
	else
		height = leftHeight;

	return height + 1;
}

void BinaryTree::printTree()
{
	return printTree(_root);
}

void BinaryTree::printTree(Node* nd)
{
	if (nd == nullptr)
	{
		std::cerr << "Tree is empty";
		return;
	}

	int height = getHeight(nd);

	for (int level = 0; level < height; level++)
	{
		//std::cout << level << '\n';
		std::vector<Node*> currentLevel;
		currentLevel.push_back(_root);

		for (int i = 0; i < level; i++)
		{
			std::vector<Node*> nextLevel;
			nextLevel.reserve(currentLevel.size() * 2);

			for (Node* Node : currentLevel)
			{
				if (Node)
				{
					nextLevel.push_back(Node->left);
					nextLevel.push_back(Node->right);
				}
				else
				{
					nextLevel.push_back(nullptr);
					nextLevel.push_back(nullptr);
				}
			}

			currentLevel.swap(nextLevel);
		}

		for (int i = 0, tabs = 6; i < currentLevel.size(); i++, tabs--)
		{
			if (currentLevel[i])
				std::cout << currentLevel[i]->key << "  ";
			else
				std::cout << -1 << ' ';
        }
        std::cout << std::endl;
	}

}

BinaryTree::Node* BinaryTree::nlrSearch(const int k) const
{
	return nlrSearch(_root, k);
}

BinaryTree::Node* BinaryTree::nlrSearch(Node* nd, const int k) const
{
	if (nd)
	{
		if (nd->key == k)
			return nd;

		Node* leftChild = nlrSearch(nd->left, k);
		Node* rightChild = nlrSearch(nd->right, k);

		if (leftChild && leftChild->key == k)
			return leftChild;

		if (rightChild && rightChild->key == k)
			return rightChild;

		return nullptr;
	}

	return nullptr;
}

BinaryTree::Node* BinaryTree::findParent(Node* nd) const
{
	//std::cout << "child id: " << nd << '\n';
	if (nd == nullptr || _root == nd)
		return nullptr;

	std::vector<Node*> currLevel;
	currLevel.push_back(_root);

	while (currLevel.size())
	{

		std::vector<Node*> nextLevel;
		nextLevel.reserve(currLevel.size() * 2);

		for (Node* node : currLevel)
		{
			if (node->left)
			{
				//std::cout << "left: " << node->left->key << " id: " << node->left << " nd id: " << nd << '\n';
				if (node->left == nd)
				{
					//std::cout << "findParent: " << node << '\n';
					return node;
				}
				nextLevel.push_back(node->left);

			}

			if (node->right)
			{
				//std::cout << "rigth: " << node->right->key <<  " id: " << node->right << " nd id: " << nd <<  '\n';

				if (node->right == nd)
				{
					//std::cout << "findParent: " << node << '\n';
					return node;
				}

				nextLevel.push_back(node->right);

			}
		}
		currLevel.swap(nextLevel);
	}
	return nullptr;
}

BinaryTree::Node* BinaryTree::getFreeNode() const
{
	return getFreeNode(_root);
}

BinaryTree::Node* BinaryTree::getFreeNode(Node* nd) const
{
	if (nd == nullptr)
		throw "get free: wrong Node";

	/*std::cout << "newNode\n";
	std::cout << "\nnd key: " << nd->key << " nd id: " << nd << '\n';*/


	if (nd->left == nullptr && nd->right == nullptr)
		return nd;

	int leftHeight = getHeight(nd->left);
	int rightHeight = getHeight(nd->right);


	if ((leftHeight > rightHeight && rightHeight != 0) || leftHeight == 0)
	{
		//std::cout << "rightWeight\n";
		return getFreeNode(nd->right);
	}

	if ((leftHeight < rightHeight || rightHeight == 0))
	{
		//std::cout << "leftWeight\n";
		return getFreeNode(nd->left);
	}

	//std::cout << "rightHeight == leftHeight\n";


	int rightCount = getCountOfNode(nd->right);
	int leftCount = getCountOfNode(nd->left);



	if (rightHeight > leftCount)
	{
		//std::cout << "leftcount:" << leftCount << '\n';
		return getFreeNode(nd->left);
	}

	//std::cout << "rightCount:" << rightCount << '\n';
	return getFreeNode(nd->right);
}

int BinaryTree::getCountOfNode() const
{
	return getCountOfNode(_root);
}

int BinaryTree::getCountOfNode(Node* nd) const
{
	int count = 0;

	if (nd)
	{

		count++;
		count += getCountOfNode(nd->left);
		count += getCountOfNode(nd->right);
	}
	else
		return 0;

	return count;
}

bool BinaryTree::deleteNodeByKey(const int k)
{
	return deleteNodeByKey(_root, k);
}

bool BinaryTree::deleteNodeByKey(Node* nd, const int k)
{
	Node* forDelete = nlrSearch(nd, k);
	//std::cout << "forDelete id: " << forDelete << '\n';
	Node* parent = findParent(forDelete);
	//std::cout << "forDelete: " << forDelete->key << '\n';
	//std::cout << "parent: " << parent << '\n'; //<< " for delete: " << forDelete->key << '\n';
	return deleteNode(forDelete, parent);

}

bool BinaryTree::deleteNode(Node* forDelete, Node* parent)
{
	if (forDelete == nullptr)
		return false;

	if (forDelete->left == nullptr && forDelete->right == nullptr)
	{
		if (parent && parent->left == forDelete)
			parent->left = nullptr;

		if (parent && parent->right == forDelete)
			parent->right = nullptr;

		if (parent == nullptr)
		{
			_root = nullptr;
		}

		delete forDelete;
		return true;
	}

	if (forDelete->left == nullptr && forDelete->right != nullptr)
	{
		//std::cout << "right: \n";
		if (parent && parent->left == forDelete)
		{
			//std::cout << "parent left: \n";
			parent->left = forDelete->right;
		}
		if (parent && parent->right == forDelete)
		{
			//std::cout << "parent right: \n";
			parent->right = forDelete->right;
		}
		if (parent == nullptr)
		{
			Node* replacingNode = getFreeNode(_root);
			_root = _root->right;
			forDelete->right = nullptr;
			forDelete->left = nullptr;
			forDelete->right = nullptr;
		}
		delete forDelete;
		return true;

	}

	if (forDelete->left != nullptr && forDelete->right == nullptr)
	{
		if (parent && parent->left == forDelete)
			parent->left = forDelete->left;

		if (parent && parent->right == forDelete)
			parent->right = forDelete->left;

		if (parent == nullptr)
		{
			_root = _root->left;
			forDelete->left = nullptr;
			forDelete->left = nullptr;
			forDelete->right = nullptr;
		}
		delete forDelete;
		return true;
	}

	if (forDelete->left && forDelete->right)
	{
		if (parent)
		{
			if (parent->left == forDelete)
			{
				//std::cout << "left: we found a child \n";
				Node* replacingNode = getFreeNode(parent);

				//std::cout << "replacing node is found: id: " << replacingNode << " key: " << replacingNode->key << '\n';
				Node* parentOfReplacingNode = findParent(replacingNode);

				if (parentOfReplacingNode == forDelete)//если заменяемый == родитель замены
				{
					parent->left = replacingNode;
					if (forDelete->left == replacingNode)
					{
						replacingNode->left = nullptr;
						replacingNode->right = forDelete->right;
					}
					else
					{
						replacingNode->right = nullptr;
						replacingNode->left = forDelete->left;
					}

				}
				else
				{
					parent->left = replacingNode;
					replacingNode->right = forDelete->right;
					replacingNode->left = forDelete->left;

					if (parentOfReplacingNode->left == replacingNode)
						parentOfReplacingNode->left = nullptr;
					else
						parentOfReplacingNode->right = nullptr;
				}
				//std::cout << "replacing is ended \n";
				/*std::cout << "try to print after replcing: \n";
				this->printTree();*/
			}

			if (parent->right == forDelete)
			{
				//std::cout << "right: we found a child \n";
				Node* replacingNode = getFreeNode(parent);
				//std::cout << "we found a free node: " << replacingNode->key << "\n";
				Node* parentOfReplacingNode = findParent(replacingNode);

				if (parentOfReplacingNode == forDelete)//если заменяемый == родитель замены
				{
					parent->right = replacingNode;
					if (forDelete->left == replacingNode)
					{
						replacingNode->left = nullptr;
						replacingNode->right = forDelete->right;
					}
					else
					{
						replacingNode->right = nullptr;
						replacingNode->left = forDelete->left;
					}
				}
				else
				{
					parent->right = replacingNode;
					replacingNode->right = forDelete->right;
					replacingNode->left = forDelete->left;

					if (parentOfReplacingNode->left == replacingNode)
						parentOfReplacingNode->left = nullptr;
					else
						parentOfReplacingNode->right = nullptr;
				}

				//std::cout << "replacing is ended \n";
				/*std::cout << "try to print after replcing: \n";

				this->printTree();*/
			}
		}
		else
		{
			Node* replacingNode = getFreeNode(_root);
			Node* parentOfReplacingNode = findParent(replacingNode);

			if (parentOfReplacingNode == _root)
			{
				if (_root->left == replacingNode)
					_root->left = nullptr;
				else
					_root->right = nullptr;
				replacingNode->left = _root->left;
				replacingNode->right = _root->right;
				_root = replacingNode;
				forDelete->left = nullptr;
				forDelete->right = nullptr;
			}
			else
			{
				if (parentOfReplacingNode->left == replacingNode)
					parentOfReplacingNode->left = nullptr;
				else
					parentOfReplacingNode->right = nullptr;
				replacingNode->left = _root->left;
				replacingNode->right = _root->right;
				this->_root = replacingNode;
				forDelete->left = nullptr;
				forDelete->right = nullptr;
				//this->printTree();
			}
		}
		delete forDelete;
		/*std::cout << "try to print after delete a node: \n";
		this->printTree();*/
		return true;
	}

	return false;
}


BinaryTree& BinaryTree::operator=(const BinaryTree& outTree)
{
	if (&outTree == this)
		return *this;

	if (this->_root)
		clearTree(this->_root);

	copyTree(this->_root, outTree._root);
}

void BinaryTree::copyTree(Node*& inTree, Node* outTree)
{
	if (outTree == nullptr || outTree == inTree)
		return;

	inTree = new Node;
	inTree->key = outTree->key;
	inTree->left = nullptr;
	inTree->right = nullptr;

	if (outTree->left)
		copyTree(inTree->left, outTree->left);

	if (outTree->right)
		copyTree(inTree->right, outTree->right);


}

std::vector<int> BinaryTree::getTreeAsVector() const
{
	return getTreeAsVector(_root);
}

std::vector<int> BinaryTree::getTreeAsVector(Node* nd) const
{
	if (nd == nullptr)
		return std::vector<int>();

	std::vector<int> keys;
	keys.push_back(nd->key);

	std::vector<Node*> currLevel;
	currLevel.push_back(nd);

	while (currLevel.size())
	{
		std::vector<Node*> nextLevel;
		nextLevel.reserve(currLevel.size() * 2);

		for (Node* node : currLevel)
		{
			if (node->left)
			{
				nextLevel.push_back(node->left);
				keys.push_back(node->left->key);
			}

			if (node->right)
			{
				nextLevel.push_back(node->right);
				keys.push_back(node->right->key);
			}
		}
		currLevel.swap(nextLevel);
	}

	return keys;
}


BinaryTree::Node* BinaryTree::getRoot() const
{
	return _root;
}

bool BinaryTree::deleteNode(Node* forDelete)
{
	Node* parent = findParent(forDelete);
	return deleteNode(forDelete, parent);

}

std::vector<BinaryTree::Node *> BinaryTree::getNodes()
{
    return getNodes(_root);
}

std::vector<BinaryTree::Node*> BinaryTree::getNodes(Node* nd)
{
    if (nd == nullptr)
        return std::vector<Node*>();

    std::vector<Node*> nodes;
    nodes.push_back(nd);

    std::vector<Node*> currLevel;
    currLevel.push_back(nd);

    while (currLevel.size())
    {
        std::vector<Node*> nextLevel;
        nextLevel.reserve(currLevel.size() * 2);

        for (Node* node : currLevel)
        {
            if (node->left)
            {
                nextLevel.push_back(node->left);
                nodes.push_back(node->left);
            }

            if (node->right)
            {
                nextLevel.push_back(node->right);
                nodes.push_back(node->right);
            }
        }
        currLevel.swap(nextLevel);
    }

    return nodes;
}
