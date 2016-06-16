#pragma once

template<class K, class V>
struct SBTNode
{
	K key;
	V value;

	SBTNode<K, V> *_left;
	SBTNode<K, V> *_right;

	SBTNode(const K& key, const V& value)
		:key(key)
		, value(value)
		, _left(nullptr)
		, _right(nullptr)
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
			return true;
		}

		else if (parent->key > key)
		{
			SBTNode<K, V> *node = new SBTNode<K, V>(key, value);
			parent->_left = node;
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

	SBTNode<int, int>* num1 = s1.Find(0);
	SBTNode<int, int>* num2 = s1.Find(2);
	SBTNode<int, int>* res = s1.FindLowestCommonAncestc(num1, num2);
	cout << res->value << endl;
}
