#include "trueBST.h"
#include <iostream>

void BTree::add(int toAdd)
{
	add(toAdd, root);
}



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
*    Usage: modified
*    Title: Find the node with minimum value in a Binary Search Tree
*    Author: GeegsforGeeks
*    Date: 9/02/2018
*    Availability: https://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/
***************************************************************************************/
int BTree::minValue()
{
	return minValue(root);
}

/***************************************************************************************
*    Usage: modified
*    Title: A program to check if a binary tree is BST or not
*    Author: Abhinesh Garhwal
*    Date: 9/02/2018
*    Availability: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
***************************************************************************************/
int BTree::isBST()
{
	return isBST(root);
}

int BTree::findMax()
{
	return findMax(root);
}

int BTree::isBSTut()
{
	return isBSTut2(root);
}




int BTree::minValue(BTreeNode * node)
{
	BTreeNode * current = node;
	while (current->leftPtr != NULL)
	{
		current = current->leftPtr;
	}
	return(current->data);
	return 0;
}

int BTree::isBST(BTreeNode * node)
{
	if (node == NULL)
		return(true);

	if (node->leftPtr != NULL && findMax(node->leftPtr) > node->data)
		return(false);

	if (node->rightPtr!=NULL && minValue(node->rightPtr) < node->data)

	if (!isBST(node->leftPtr) || !isBST(node->rightPtr))
		return(false);

		
	return (true);
}

int BTree::findMax(BTreeNode * node)
{
	BTreeNode * current = node;
	while (current->rightPtr != NULL)
	{
		current = current->rightPtr;
	}
	return(current->data);
	return 0;
}

int BTree::isBSTut(BTreeNode * node, int min, int max)
{
	if (node == NULL)
		return 1;

	if (node->data < min || node->data >max) {
		return 0;
	}
	else {
		return
			isBSTut(node->leftPtr, min, node->data - 1) && // Allow only distinct values
			isBSTut(node->rightPtr, node->data + 1, max); // Allow only distinct values
	}

}

int BTree::isBSTut2(BTreeNode * node)
{
	return (isBSTut(node,INT_MIN, INT_MAX));
}

int main()
{
	BTree tree;

	tree.add(2);
	tree.add(7);
	tree.add(3);
	tree.add(6);
	tree.add(5);

	std::cout << "The minimum values is: " << tree.minValue() << "\n";
	std::cout << "The maximum values is: " << tree.findMax() << "\n";

	tree.isBST();
	std::cout << tree.isBST() <<"\n";
	std::cout << tree.isBSTut() << "\n";
	system("pause");

}
