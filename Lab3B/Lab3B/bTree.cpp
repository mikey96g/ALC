#include "bTree.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

void BTree::add(int toAdd)
{
	add(toAdd, root);
}

int BTree::height()
{
	return height(root);
}
/***************************************************************************************
*    Usage: modified
*    Title: Find binary tree height
*    Date: 01/03/2018
*	 Availability: https://stackoverflow.com/questions/15994538/find-binary-tree-height
***************************************************************************************/

int BTree::height(BTreeNode * h)
{
	if (h == NULL)
	{
		return -1;
	}
	int left = height(h->leftPtr);
	int right = height(h->rightPtr);

	return 1 + std::max(left, right);
	
}
/***************************************************************************************
*	Usage: modified
*	Title: Absolute C++ (5th Edition) - Linked Data Structures, Pages:804-806
*	Author: Savitch, W
*	Date: 01/03/2018
***************************************************************************************/
void BTree::add(int item, BTreeNode *& subTreeRoot)
{
	if (subTreeRoot == NULL)
		subTreeRoot = new BTreeNode(item, NULL, NULL);
	else if (item < subTreeRoot->data)
		add(item, subTreeRoot->leftPtr);
	else
		add(item, subTreeRoot->rightPtr);
}

int main()
{
	BTree bTree;

	bTree.add(2);
	bTree.add(5);
	bTree.add(9);
	bTree.add(1);
	bTree.add(12);

	std::cout << bTree.height() << "\n";
	system("pause");
}

