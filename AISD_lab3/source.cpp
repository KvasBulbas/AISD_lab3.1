#include <iostream>
#include "SearchTree.h"
#include <ctime>

int main()
{
	srand(time(NULL));

	SearchTree obj1;
	for (int i = 0; i < 10; i++)
		obj1.addNode(rand() % 100 + 10);

	
	obj1.printTree();


}