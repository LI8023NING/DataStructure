/*
*1.˵���������������ṹ ���������ṹ �ӿ�
*2.���ߣ�����
*/

#pragma once

//���������ڵ�ṹ
template<class T>
class HuffmanTreeNode
{
public:
	typedef HuffmanTreeNode<T> HTN;
public:
	//���캯��
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
		//����ڵ��������
	}

public:
	HTN* _left;
	HTN* _right;
	HTN* _parent;
	T _weight;
};



//���������ṹ
template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> HTN;
	typedef HuffmanTree<T> HT;
public:

	//�޲ι��캯��
	HuffmanTree()
		:_root(nullptr)
	{}

	~HuffmanTree()
	{}
public:
	void CreateTree(T *a, size_t size, const T& invalid)
	{
		assert(a);
		Heap<HuffmanTreeNode<T>*> s1;  //�� ���ڷ�������  ������   ������ŵ���ָ�룬����һ��Ҫ�ԣ�

		//��������С��Ԫ��
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
