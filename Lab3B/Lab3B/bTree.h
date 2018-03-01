#pragma once
#include <cstdlib>

class BTreeNode
{
	friend class BTree;
public:
	BTreeNode(int data, BTreeNode* left, BTreeNode* right)
		:data(data), leftPtr(left), rightPtr(right) {};


private:
	BTreeNode * leftPtr;
	BTreeNode * rightPtr;
	int data;

};

class BTree
{
public:
	BTree():root(NULL);
	void add(int toAdd);
	int height();
private:

	void height(BTreeNode *subTreeRoot);
	void add(int item, BTreeNode*& subTreeRoot);
	BTreeNode * root;
};