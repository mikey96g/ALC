#pragma once
#include <cstdlib>

class BTreeNode
{
	friend class searchTree;
public:
	BTreeNode(char data, BTreeNode* left, BTreeNode* right)
		:data(data), leftPtr(left), rightPtr(right) {};


private:
	BTreeNode * leftPtr;
	BTreeNode * rightPtr;
	char data;

};

/***************************************************************************************
*	Usage: modified
*	Title: Absolute C++ (5th Edition) - Linked Data Structures, Pages:804-806
*	Author: Savitch, W
*	Date: 01/03/2018
***************************************************************************************/
class searchTree
{
public:
	searchTree() :root(NULL) {};
	void add(char toAdd);
	bool inTree(char data) const;
	void inorderShow() const;

private:

	bool inTree(char item, BTreeNode* subTreeRoot) const;
	void add(char item, BTreeNode*& subTreeRoot);
	void inorderShow(BTreeNode* subTreeRoot) const;
	BTreeNode * root;
};