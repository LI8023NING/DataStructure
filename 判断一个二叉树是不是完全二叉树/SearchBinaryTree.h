#pragma once

template<class K,class V>
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

	bool _IsBlanceOfBinaryTree(Node* root);
	bool IsBlanceOfBinaryTree();

	//非递归插入
	bool Insert(const K& key,const V& value)
	{
		return _Insert(key,value);
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

	SBTNode<K, V>* Find_R(const K& key)
	{
		return _Find_R(_root,key);
	}

	//递归查找
	Node* _Find_R(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		Node* cur = root;
		if (cur->key == key)
		{
			return cur;
		}

		else if (cur->key > key)
		{
			_Find_R(cur->_left,key);
		}
		else if (cur->key < key)
		{
			_Find_R(cur->_right,key);
		}
		else
		{
			return nullptr;
		}
	}

	//中序遍历
	void InOrder(SBTNode<K, V>* root)
	{
		if (root == nullptr)
		{
			return; //递归结束出口
		}

		SBTNode<K, V> *cur = root;
		InOrder(cur->_left);
		cout << cur->key << " ";
		InOrder(cur->_right);
	}


public:
	SBTNode<K, V> *_root;
};

