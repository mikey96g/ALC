#pragma once
class BTreeNode
{
	friend class BTree;
public:
	BTreeNode(int);

private:
	BTreeNode * left;
	int data;
	BTreeNode * right;
};

class BTree
{
public:
	BTree();
	void add(int toAdd);
	int height();
private:

	void height(BTreeNode *subTreeRoot);
	void add(BTreeNode *toAdd, BTreeNode *addHere);
	BTreeNode * root;
};