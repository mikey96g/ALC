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
bool BTree::hasPathSum(int sum)
{
	return hasPathSum(root , sum);
}

void BTree::printPaths()
{
	int path[1000];
	printPathsRecur(root, path, 0);
}

void BTree::printArray(int ints[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << ints[i] << " ";
	}
	std::cout << "\n";
}



/***************************************************************************************
*	Usage: modified
*	Title: Root to leaf path sum equal to a given number
*	Author: Geeks for Geeks
*	Date: 03/03/2018
*   Availability: https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
***************************************************************************************/
bool BTree::hasPathSum(BTreeNode * node, int sum)
{
	if (node == NULL)
	{
		return (sum == 0);
	}
	else
	{
		bool  ans = 0;
		int subSum = sum - node->data;
		if (subSum == 0 && node->leftPtr == NULL && node->rightPtr == NULL)
		{
			return 1;
		}

		if (node->leftPtr)
		{
			ans = ans || hasPathSum(node->leftPtr, subSum);
		}
		if (node->rightPtr) 
		{
			ans = ans || hasPathSum(node->rightPtr, subSum);
		}
		return ans;
	}
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
/***************************************************************************************
*	Usage: modified
*	Title: Root to leaf path sum equal to a given number
*	Author: Geeks for Geeks
*	Date: 03/03/2018
*   Availability: https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
***************************************************************************************/
void BTree::printPathsRecur(BTreeNode * node, int path[], int pathLen)
{
	if(node == NULL)
	{
		return;
	}

	path[pathLen] = node->data;
	pathLen++;

	if(node->leftPtr==NULL && node->rightPtr==NULL)
	{
		printArray(path, pathLen);
	}
	else
	{
		printPathsRecur(node->leftPtr, path, pathLen);
		printPathsRecur(node->rightPtr, path, pathLen);

	}
}

int main()
{
	BTree bTree;

	int sum = 3;

	bTree.add(2);
	bTree.add(5);
	bTree.add(9);
	bTree.add(1);
	bTree.add(12);

	std::cout << bTree.height() << "\n";

	if (bTree.hasPathSum(sum))
	{
		std::cout << "There is a root to leaf path with: " << sum;
	}
	else
	{
		std::cout << "No root to leaf path with: " << sum;
	}
	std::cout << "\n";
	bTree.printPaths();



	system("pause");
	return 0;
}

