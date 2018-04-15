#traversal
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

#delete
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

#minimum
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
	
#add	
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