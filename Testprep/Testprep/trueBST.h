#pragma once
#include <stdio.h>
#include<stdlib.h>

template<class T> class searchTree;

template<class T> class treeNode
{
public:
	treeNode() : root(NULL) {}
	treeNode(T data, treeNode<T>* left,treeNode<T>* right)
		:data(data), leftPTR(left),rightPTR(right){}
	friend class searchTree<T>;


private:
	treeNode<T> * rightPTR;
	treeNode<T> * leftPTR;
	T data;
};

template<class T> class searchTree
{
public:
	searchTree() : root(NULL){}
	void add(T data);
	void del(T data);
	void inOrderShow();
	void preOrderShow();
	//void postOrderShow();
	treeNode<T>* minValueNode();
	int height() const;
	bool hasPathSum(int sum);
	void printPath();

private:
	treeNode<T>* root;
	void add(T data, treeNode<T>*& subTreeRoot);
	void inOrderShow(treeNode<T>* subTreeRoot)const;
	void preOrderShow(treeNode<T>* subTreeRoot)const;
	//void postOrderShow(treeNode<T>* subTreeRoot)const;
	treeNode<T>* minValueNode(treeNode*subTreeRoot);
	treeNode<T>* del(T data, treeNode<T>*& subTreeRoot);
};

