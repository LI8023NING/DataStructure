#pragma once

#include<iostream>
using namespace std;

//标记左右是否线索
enum PointerTag
{
	THREAD,  //0
	LINK     //1
};

//线索二叉树的节点结构
template<class T>
struct BinaryTreeNodeThd
{
	// 数据
	//左孩子
	//右孩子
	//左右线索标志
	T _data;
	BinaryTreeNodeThd<T> *_left;
	BinaryTreeNodeThd<T> *_right;
	PointerTag _leftTag;
	PointerTag _rightTag;

	//初始化
	BinaryTreeNodeThd(const T& data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
		, _leftTag(LINK)  //LINK说明后边有连接 
		, _rightTag(LINK) //THERD说明是认为加上的连接
	{}
};

//线索二叉树
template<class T>
class BinaryTreeThd
{
public:
	//构造线索二叉树（数组）
	BinaryTreeThd(T *array, size_t size);
	
	//析构
	~BinaryTreeThd()
	{}

	//中序线索二叉树
	void InOrdThreading();

	//中序遍历
	void InOderThd();

	//前序线索二叉树
	void PrevOrderThreading();

	//前序遍历
	void PrevOrderThd();

	//后序线索二叉树
	void PostOrderThreading();

	//后序遍历
	void PostOrderThd();

protected:

	//中序线索
	void _InOrderThreading(BinaryTreeNodeThd<T>* cur, BinaryTreeNodeThd<T>*& prev)
	{
		if (cur == NULL) //根为空
		{
			return;
		}

		_InOrderThreading(cur->_left,prev); //唯一作用就是cur往左走

		//左边空的话，进行线索  
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		//右为空 线索 
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}

		prev = cur;

		_InOrderThreading(cur->_right, prev);
	}

	//前序线索
	void _PrevOrderThreading(BinaryTreeNodeThd<T>* cur, BinaryTreeNodeThd<T>*& prev)
	{
		if (cur == NULL)
			return;

		if (cur->_left == NULL)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}

		prev = cur;

		if (cur->_leftTag == LINK)
			_PrevOrderThreading(cur->_left, prev);

		if (cur->_rightTag == LINK)
			_PrevOrderThreading(cur->_right, prev);
	}

	//后序线索
	void _PostOrderThreading(BinaryTreeNodeThd<T>* cur,BinaryTreeNodeThd<T>* prev)
	{
		if (cur == NULL)
		{
			return;
		}

		_PostOrderThreading(cur->_left, prev);
		_PostOrderThreading(cur->_right, prev);

		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}

		prev = cur;
	}

protected:
	BinaryTreeNodeThd<T>* _CreateTree(const T *array,size_t size,size_t& index)
	{
		BinaryTreeNodeThd<T> *root = nullptr;
		if (index < size && array[index] != '#')
		{
			root = new BinaryTreeNodeThd<T>(array[index]);
			root->_left = _CreateTree(array,size,++index);
			root->_right = _CreateTree(array,size,++index);
		}
		else
		{
			return NULL;
		}
		
		return root;
	}
protected:
	BinaryTreeNodeThd<T> *_root;
};

//创建树
template<class T>
BinaryTreeThd<T>::BinaryTreeThd(T *array, size_t size)
{
	size_t index = 0;
	_root = _CreateTree(array, size, index);
}

//中序遍历
template<class T>
void BinaryTreeThd<T>::InOderThd()
{
	BinaryTreeNodeThd<T> *cur = _root;
	while (cur)
	{
		//中序遍历，需要找最左边的节点
		while (cur && cur->_leftTag == LINK) //后边有连接才往下走
		{
			cur = cur->_left;
		}

		cout << cur->_data << "  "; //最左节点

		//访问线索到的后继节点
		while (cur->_rightTag == THREAD)
		{
			cur = cur->_right;
			cout << cur->_data << "  ";
		}

		//转到右边数
		cur = cur->_right;
	}
}

//前序遍历
void PrevOrderThd()
{
	BinaryTreeNodeThd<T>* cur = _root;
	while (cur)
	{
		while (cur && cur->_leftTag == LINK)
		{
			cout << cur->_data << " ";
			cur = cur->_left;
		}
		cout << cur->_data << " ";

		cur = cur->_right;

		/*	while(cur && cur->_rightTag == THREAD)
		{
		cur = cur->_right;
		cout<<cur->_data<<" ";
		}

		if(cur->_leftTag == LINK)
		cur = cur->_left;
		else
		cur = cur->_right;*/
	}

	cout << endl;
}

//中序线索
template<class T>
void BinaryTreeThd<T>::InOrdThreading()
{
	BinaryTreeNodeThd<T> *prev = NULL;
	_InOrderThreading(_root,prev);
}
