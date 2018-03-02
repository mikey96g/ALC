#include "Header.h"
#include <stdlib.h>
#include <iostream>

int main()
{
	SearchTree<int> intTree;

	intTree.add(3);
	intTree.add(6);
	intTree.add(15);

	intTree.inOrderShow();
	std::cout << "\n";

	if (intTree.inTree(3))
	{
		std::cout << "The value is in the tree";
	}
	else
		std::cout << "The value is not in the tree";

	std::cout << "\n";

	SearchTree<char> charTree;
	charTree.add('f');
	charTree.add('a');
	charTree.add('d');

	charTree.inOrderShow();
	std::cout << "\n";

	if (charTree.inTree('f'))
	{
		std::cout << "The value is in the tree";
	}
	else
		std::cout << "The value is not in the tree";
	std::cout << "\n";

	system("pause");

}