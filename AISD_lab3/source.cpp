#include <iostream>
#include "SearchTree.h"
#include <ctime>

int main()
{
	srand(time(NULL));

	SearchTree obj1;
	/*for (int i = 0; i < 15; i++)
		obj1.addNode(rand() % 200 + 10);*/

	obj1.addNode(50);
	obj1.addNode(60);
	obj1.addNode(70);
	obj1.addNode(55);
	
	obj1.printTree();

	int a;
	std::cin >> a;

	obj1.deleteNodeByKey(a);

	obj1.printTree();



	/*SearchTree obj2;
	
	obj2 = obj1;

	obj2.printTree();*/

}