#include <iostream>
#include "SearchTree.h"
#include <ctime>

int main()
{
	srand(time(NULL));

	SearchTree obj1;
	
	/*for (int j = 0; j < 20; j++)
	{
		obj1.addNode(105);
		for (int i = 0; i < 15; i++)
			obj1.addNode(rand() % 200 + 10);

		obj1.printTree();



		std::vector<int> vec = obj1.getTreeAsVector();

		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << "\nkey: " << vec[i] << '\n';
			obj1.deleteNodeByKey(vec[i]);
			obj1.printTree();

			if (obj1.nlrSearch(vec[i]) != nullptr )
			{
				std::cout << "\n node not deleted\n";
				break;
			}
			if (!obj1.checkTree())
			{
				std::cout << "\nwrong key\n";
				break;
			}

		}
		obj1.clearTree();

	}*/

	
	
	obj1.addNode(105);
	for (int i = 0; i < 15; i++)
		obj1.addNode(rand() % 200 + 10);

	obj1.printTree();


	SearchTree obj2 = obj1;
	

	obj2.printTree();

}