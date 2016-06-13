/*
*1.说明：哈夫曼树结点结构 哈夫曼树结构 接口
*2.作者：李宁
*/

#pragma once

//哈夫曼数节点结构
template<class T>
class HuffmanTreeNode
{
public:
	typedef HuffmanTreeNode<T> HTN;
public:
	//构造函数
	HuffmanTreeNode(const T& x)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _weight(x)
	{}

	bool operator<(const HuffmanTreeNode<T>* node)
	{
		return _weight < node->_weight;
	}

	~HuffmanTreeNode()
	{
		//处理节点的清理工作
	}

public:
	HTN* _left;
	HTN* _right;
	HTN* _parent;
	T _weight;
};



//哈夫曼树结构
template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> HTN;
	typedef HuffmanTree<T> HT;
public:

	//无参构造函数
	HuffmanTree()
		:_root(nullptr)
	{}

	~HuffmanTree()
	{}
public:
	void CreateTree(T *a, size_t size, const T& invalid)
	{
		assert(a);
		Heap<HuffmanTreeNode<T>*> s1;  //草 终于发现问题  在这里   （堆里放的是指针，类型一定要对）

		//找两个最小的元素
		for (size_t i = 0; i < size; ++i)
		{
			if (a[i] != invalid)
			{
			HuffmanTreeNode<T>* node = new HuffmanTreeNode<T>(a[i]);
				s1.Push(node);
			}
		}

		while (s1.Size() > 1)
		{
			HuffmanTreeNode<T>* left = s1.Top();
			s1.Pop();
			HuffmanTreeNode<T>* right = s1.Top();
			s1.Pop();


			HuffmanTreeNode<T>* parent = new HuffmanTreeNode<T>(left->_weight + right->_weight);

		
			parent->_left = left;
			parent->_right = right;

			left->_parent = parent;
			right->_parent = parent;

			s1.Push(parent);
		}
		_root = s1.Top();
		s1.Pop();
	}

	HuffmanTreeNode<T>* GetRoot()
	{
		return _root;
	}

public:
	HTN* _root;
};
