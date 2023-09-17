#include <iostream>
#include "SearchTree.h"
#include <ctime>

int main()
{
	srand(time(NULL));

	SearchTree obj1;
	for (int i = 0; i < 15; i++)
		obj1.addNode(rand() % 200 + 10);

	
	obj1.printTree();
	std::cout << (obj1.getMax())->key << '\n';

	std::cout << (obj1.getMin())->key << '\n';


}