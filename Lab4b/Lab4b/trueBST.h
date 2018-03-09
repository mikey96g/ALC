#pragma once
#include <stdio.h>
#include<stdlib.h>

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
	BTree() :root(NULL) {};
	void add(int toAdd);
	int minValue();
	int isBST();
	int findMax();
	int isBSTut();

private:
	void add(int item, BTreeNode*& subTreeRoot);
	int minValue(BTreeNode * node);
	int isBST(BTreeNode * node);
	int findMax(BTreeNode * node);
	int isBSTut(BTreeNode * node, int min, int max);
	BTreeNode * root;
};