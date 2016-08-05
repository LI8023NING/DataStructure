/************************************
 ** Auth: 李宁
 ** Date: 2016/8/5
 ** Desc: 判断两个二叉树是否相等
 ************************************/
#include"SearchBinaryTree.h"

bool CompTree(SBTNode<int, int>* tree1, SBTNode<int, int>* tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;
	else if (tree1 == NULL || tree2 == NULL)
		return false;
	else
	{
		if (tree1->key == tree2->key)
			return true;
	}

	return (CompTree(tree1->_left, tree2->_left)&&CompTree(tree1->_right,tree2->_right))
		|| (CompTree(tree1->_left, tree2->_right)&&CompTree(tree1->_right, tree2->_left));
}


void Test()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int b[] = {1,2, 3, 4, 5, 6, 7, 8, 9, 0 };

	SBTree<int, int> s1;
	for (int i = 0; i < 10; ++i)
	{
		s1.Insert(a[i],i);
	}

	 
	SBTree<int, int> s2;
	for (int i = 0; i < 10; ++i)
	{
		s2.Insert(b[i], i);
	}

	bool flag = CompTree(s1._root,s2._root);
	cout << flag << endl;

}