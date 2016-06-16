#pragma once

template<class K, class V>
struct SBTNode
{
	K key;
	V value;

	SBTNode<K, V> *_left;
	SBTNode<K, V> *_right;
	SBTNode<K, V>* _parent;

	SBTNode(const K& key, const V& value)
		:key(key)
		, value(value)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}

};

template<class K, class V>
class SBTree
{
	typedef SBTNode<K, V> Node;
public:
	SBTree()
		:_root(nullptr)
	{}

	~SBTree()
	{}

public:
	//非递归插入
	bool Insert(const K& key, const V& value)
	{
		return _Insert(key, value);
	}

	bool _Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new SBTNode<K, V>(key, value);
			_root->_parent = nullptr;
			return true;
		}

		SBTNode<K, V> *parent = nullptr; //指向cur 的前驱
		SBTNode<K, V> *cur = _root;
		while (cur)
		{
			if (cur->key > key)  //插左边
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		if (parent->key < key)
		{
			SBTNode<K, V> *node = new SBTNode<K, V>(key, value);
			parent->_right = node;
			node->_parent = parent;
			return true;
		}

		else if (parent->key > key)
		{
			SBTNode<K, V> *node = new SBTNode<K, V>(key, value);
			parent->_left = node;
			node->_parent = parent;
			return true;
		}
		else
		{
			return false;
		}
	}


	//非递归查找节点
	SBTNode<K, V>* Find(const K& key)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}

		SBTNode<K, V> *cur = _root;
		while (cur)
		{
			if (cur->key == key)
			{
				return cur;
			}
			else if (cur->key > key)
			{
				cur = cur->_left;
			}
			else if (cur->key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return nullptr;
			}
		}
		return nullptr;
	}


	//假设题设两个节点在树中
	//两个节点的最近公共祖先
	//方法一：搜索二叉树
	SBTNode<K, V>* _FindLowestCommonAncestc(Node* root, Node* one, Node* two)
	{
		if (root == nullptr)
			return nullptr;

		Node* cur = root;
		if (one->value > cur->value && two->value > cur->value)
		{
			_FindLowestCommonAncestc(cur->_right,one,two);
		}

		else if (one->value < cur->value && two->value < cur->value)
		{
			_FindLowestCommonAncestc(cur->_left, one, two);
		}
		else
		{
			return cur;
		}
	}

	SBTNode<K, V>* FindLowestCommonAncestc(Node* one, Node* two)
	{
		return _FindLowestCommonAncestc(_root,one,two);
	}

	//方法二：假如是一般树，没有搜索二叉树的特点
	//因为有父指针，转化为两个链表相交
	SBTNode<K, V>* _FindLowestCommonAncestc1(Node* root, Node* one, Node* two)
	{
		if (root == nullptr)
			return nullptr;
		//以找到的两个节点分别为头节点的两个链表
		SBTNode<K, V>* Head1 = one;
		SBTNode<K, V>* Head2 = two;

		int length1 = 1;
		int length2 = 1;
		while (Head1 != root)
		{
			length1++;
			Head1 = Head1->_parent;
		}

		while (Head2 != root)
		{
			length2++;
			Head2 = Head2->_parent;
		}

		for (int i = 0; i < abs(length1 - length2); ++i)
		{
			if (length1 > length2)
				one = one->_parent;
			else if (length1 < length2)
				two = two->_parent;
			else
				break;
		}

		while (one != two)
		{
			one = one->_parent;
			two = two->_parent;
		}
		
		return one;
	}

	SBTNode<K, V>* FindLowestCommonAncestc1(Node* one, Node* two)
	{
		return _FindLowestCommonAncestc1(_root, one, two);
	}

public:
	SBTNode<K, V> *_root;
};


void Test()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	SBTree<int, int> s1;
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		s1.Insert(a[i], a[i]);
	}

	SBTNode<int, int>* num1 = s1.Find(3);
	SBTNode<int, int>* num2 = s1.Find(9);
	SBTNode<int, int>* res = s1.FindLowestCommonAncestc1(num1, num2);
	cout << res->value << endl;
}
