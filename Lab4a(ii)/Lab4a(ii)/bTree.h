#pragma once
#include <cstdlib>

/***************************************************************************************
*	Usage: modified
*	Title: Absolute C++ (5th Edition) - Linked Data Structures, Pages:804-806
*	Author: Savitch, W
*	Date: 01/03/2018
***************************************************************************************/
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
	int height();
	bool hasPathSum(int sum);
	void printPaths();
	void printArray(int ints[], int length);

private:
	bool hasPathSum(BTreeNode * node, int sum);
	int height(BTreeNode *h);
	void add(int item, BTreeNode*& subTreeRoot);
	void printPathsRecur(BTreeNode* node, int path[], int pathLen);
	BTreeNode * root;
};