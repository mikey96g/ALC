#include "trueBST.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
void searchTree<T>::add(T data)
{
	add(data, root);
}

template<class T>
void searchTree<T>::del(T data)
{
	del(data, root);
}

template<class T>
void searchTree<T>::inOrderShow()
{
	inOrderShow(root);
}

template<class T>
void searchTree<T>::preOrderShow()
{
	preOrderShow(root);
}

template<class T>
void searchTree<T>::postOrderShow()
{
	postOrderShow(root);
}

template<class T>
treeNode<T>* searchTree<T>::minValueNode()
{
	minValueNode(root);
}

template<class T>
int searchTree<T>::height() const
{
	return 0;
}

template<class T>
bool searchTree<T>::hasPathSum(int sum)
{
	return false;
}

template<class T>
void searchTree<T>::printPath()
{
}

template<class T>
void searchTree<T>::add(T data, treeNode<T>*& subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		subTreeRoot = new TreeNode<T>(data, NULL, NULL);
	}
	else if (data < subTreeRoot->data)
	{
		add(data, subTreeRoot->leftPTR);
	}
	else// 
		add(data, subTreeRoot->rightPTR);
}

template<class T>
void searchTree<T>::inOrderShow(treeNode<T>* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		// In-order traversal of the tree
		inOrderShow(subTreeRoot->leftPTR);
		cout << subTreeRoot->data << " ";
		inOrderShow(subTreeRoot->rightPTR);
	}
}

template<class T>
void searchTree<T>::preOrderShow(treeNode<T>* subTreeRoot) const
{
	
	inOrderShow(subTreeRoot-> rightPTR);
	cout << subTreeRoot->data << " ";
	inOrderShow(subTreeRoot->leftPTR);

}

template<class T>
void searchTree<T>::postOrderShow(treeNode<T>* subTreeRoot) const
{
	
	inOrderShow(subTreeRoot->leftPTR);
	inOrderShow(subTreeRoot->rightPTR);
	cout << subTreeRoot->data << " ";
}

template<class T>
treeNode<T>* searchTree<T>::minValueNode(treeNode * subTreeRoot)
{
	treeNode<T>* current = node;
	while (current->leftPTR != NULL)
	{
		current = current->leftPTR;
	}
	return current;
}

template<class T>
treeNode<T>* searchTree<T>::del(T data, TreeNode<T>* &subTreeRoot)
{

	if (subTreeRoot == NULL)
	{
		return subTreeRoot;
	}

	if (data < subTreeRoot-> NULL)
	{
		subTreeRoot->leftPTR = del(data, subTreeRoot->leftPTR);
	}
	else if (data > subTreeRoot)
	{
		subTreeRoot->rightPTR = del(data, subTreeRoot->rightPTR);
	}
	else
	{
		if(subTreeRoot->leftPTR == NULL)
		{
			treeNode<T> *temp = subTreeRoot->rightPTR;
			free(subTreeRoot);
			return temp;
		}
		else if(subTreeRoot->rightPTR == NULL)
		{
			treeNode<T>* temp = subTreeRoot->leftPTR;
			free(subTreeRoot);
			return temp;
		}
		treeNode<T> * temp = minValueNode(subTreeRoot->rightPTR);
		subTreeRoot->data = temp->data;
		subTreeRoot->rightPTR = del(temp->data, subTreeRoot->rightPTR);
	}

	return subTreeRoot;
}

int main()
{
	searchTree<int> bsTree;
	bsTree.add(45);
	bsTree.add(5);
	bsTree.add(15);
	bsTree.add(31);
	bsTree.add(11);

	bsTree.inOrderShow();
	cout << endl;
	bsTree.del(31);
	bsTree.inOrderShow();
	cout << endl;

	bsTree.add(31);
	bsTree.add(11);


	system("pause");
	return 0;
}