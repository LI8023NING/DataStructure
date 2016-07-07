#pragma once

#include<queue>
#include"SearchBinaryTree.h"

bool Flag = false;
template<class K,class V>
bool SBTree<K, V>::_IsBlanceOfBinaryTree(SBTNode<K, V>* root)
{
	//空树也是完全二叉树 
	if (root == nullptr)
		return true;                

	queue<Node*> TreeNode;

	//首先根节点入队列 
	TreeNode.push(root);
	while (!TreeNode.empty())
	{
		Node* node = TreeNode.front();
		TreeNode.pop();

		if (node->_left)
		{
			if (!Flag)
				TreeNode.push(node->_left);
			else
				return false;
		}
		else
			Flag = false;

		if (node->_right)
		{
			if (!Flag)
				TreeNode.push(node->_right);
			else
				return false;
		}
		else
			Flag = true;
	}
	return true;
}

template<class K, class V>
bool SBTree<K, V>::IsBlanceOfBinaryTree()
{
	return _IsBlanceOfBinaryTree(_root);
}


void Test()
{
	//int a[] = { 6, 3, 2,5, 8, 7};
	int a[] = { 6, 3, 2, 8, 7 ,9};
	SBTree<int, int> s1;
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		s1.Insert(a[i], a[i]);
	}
	s1.InOrder(s1._root);
	if (s1.IsBlanceOfBinaryTree())
		cout << "是完全二叉树" << endl;
	else
		cout << "不是完全二叉树" << endl;


}