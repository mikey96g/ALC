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

