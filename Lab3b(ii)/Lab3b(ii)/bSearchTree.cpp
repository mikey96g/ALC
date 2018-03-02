#include "bSearchTree.h"
#include <cstdlib>
#include <iostream>
/***************************************************************************************
*	Usage: modified
*	Title: Absolute C++ (5th Edition) - Linked Data Structures, Pages:804-806
*	Author: Savitch, W
*	Date: 01/03/2018
***************************************************************************************/
void searchTree::add(char toAdd)
{
	add(toAdd, root);
}

bool searchTree::inTree(char item) const
{
	
	return inTree(item,root);
}

void searchTree::inorderShow() const
{
	inorderShow(root);
}



bool searchTree::inTree(char item, BTreeNode* subTreeRoot) const
{
	if (subTreeRoot == NULL)
	{
		return false;
	}
	else if (subTreeRoot->data == item)
		return true;
	else if (item < subTreeRoot->data)
		return inTree(item, subTreeRoot->leftPtr);
	else
		return inTree(item, subTreeRoot->rightPtr);
	
}

void searchTree::add(char item, BTreeNode *& subTreeRoot)
{
	if (subTreeRoot == NULL)
		subTreeRoot = new BTreeNode(item, NULL, NULL);
	else if (item < subTreeRoot->data)
		add(item, subTreeRoot->leftPtr);
	else
		add(item, subTreeRoot->rightPtr);
}

void searchTree::inorderShow(BTreeNode * subTreeRoot) const
{
	if(subTreeRoot != NULL)
	{
		inorderShow(subTreeRoot->leftPtr);
		std::cout << subTreeRoot->data << "";
		inorderShow(subTreeRoot->rightPtr);
	}
}

int main()
{

	searchTree bTree;

	bTree.add('r');
	bTree.add('q');
	bTree.add('d');
	bTree.add('h');
	bTree.add('a');


	bTree.inorderShow();
	std::cout << "\n";

	if (bTree.inTree('a'))
	{
		std::cout << "The value is in the tree";
	}
	else
		std::cout << "Value is not found";
	std::cout << "\n";

	system("pause");
}