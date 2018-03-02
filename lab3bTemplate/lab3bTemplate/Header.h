#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdlib.h>


template<class T>
class SearchTree;
/***************************************************************************************
*	Usage: modified
*	Title: Absolute C++ (5th Edition) - Linked Data Structures, Pages:804-806
*	Author: Savitch, W
*	Date: 02/03/2018
***************************************************************************************/
template<class T>
class TreeNode
{

	public :
		TreeNode() : root(NULL) {}
	TreeNode(T data, TreeNode<T>* left, TreeNode<T>* right)
		: data(data), leftPtr(left), rightPtr(right){}
	     friend class SearchTree<T>;
private:
	T data;
	TreeNode<T> *leftPtr;
	TreeNode<T> *rightPtr;
};

template<class T>
class SearchTree 
{
public:
	SearchTree() :root(NULL) {}
	void add(T toAdd);
	bool inTree(T item) const;
	void inOrderShow() const;
private:
	void add(T toAdd, TreeNode<T>*& subTreeRoot);
	bool inTree(T item, TreeNode<T>* subTreeRoot)const;
	void inOrderShow(TreeNode<T>* subTreeRoot) const;
	TreeNode<T> *root;

};

#endif

template<class T>
inline void SearchTree<T>::add(T toAdd)
{
	add(toAdd, root);
}

template<class T>
inline bool SearchTree<T>::inTree(T item) const
{
	return inTree(item, root);
}

template<class T>
inline void SearchTree<T>::inOrderShow() const
{
	inOrderShow(root);
}

template<class T>
inline void SearchTree<T>::add(T toAdd, TreeNode<T>*& subTreeRoot)
{
	if (subTreeRoot == NULL)
		subTreeRoot = new TreeNode<T>(toAdd, NULL, NULL);
	else if (toAdd < subTreeRoot->data)
		add(toAdd, subTreeRoot->leftPtr);
	else// item>= subTreeRoot->data
		add(toAdd, subTreeRoot->rightPtr);
	
}

template<class T>
inline bool SearchTree<T>::inTree(T item, TreeNode<T>* subTreeRoot) const
{

	if (subTreeRoot == NULL)
	{
		return false;
	}
	else if (subTreeRoot->data == item)
	{
		return true;
	}
	else if (item < subTreeRoot->data)
	{
		return inTree(item, subTreeRoot->leftPtr);
	}
	else
	{
		return inTree(item, subTreeRoot->rightPtr);
	}
}

template<class T>
inline void SearchTree<T>::inOrderShow(TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		// In-order traversal of the tree
		inOrderShow(subTreeRoot->leftPtr);
		std::cout << subTreeRoot->data << " ";
		inOrderShow(subTreeRoot->rightPtr);
	}
}
