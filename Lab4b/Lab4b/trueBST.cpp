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

int BTree::minValue()
{
	return minValue(root);
}

int BTree::isBST()
{
	return isBST(root);
}

int BTree::findMax()
{
	return findMax(root);
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
	/*if (node == NULL)
		return(true);

	if(node->leftPtr!=NULL && findMax())*/
		
	return 0;
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


	system("pause");

}
