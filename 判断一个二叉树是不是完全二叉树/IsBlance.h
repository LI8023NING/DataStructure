#pragma once

#include<queue>
#include"SearchBinaryTree.h"

template<class K,class V>
bool SBTree<K, V>::_IsBlanceOfBinaryTree(SBTNode<K, V>* root)
{

}

template<class K, class V>
bool SBTree<K, V>::IsBlanceOfBinaryTree()
{
	return _IsBlanceOfBinaryTree(_root);
}


void Test()
{
	int a[] = { 6, 3, 2, 5, 8, 7, 9 };
	SBTree<int, int> s1;
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		s1.Insert(a[i], a[i]);
	}
	s1.InOrder(s1._root);
}