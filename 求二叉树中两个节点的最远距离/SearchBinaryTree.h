#pragma once

#define max(a, b) ((a) > (b) ? (a) : (b))

template<class K,class V>
struct SBTNode
{
	K key;
	V value;

	SBTNode<K, V> *_left;
	SBTNode<K, V> *_right;
	size_t right_height;
	size_t left_height;

	SBTNode(const K& key, const V& value)
		:key(key)
		, value(value)
		, _left(nullptr)
		, _right(nullptr)
		, left_height(0)
		, right_height(0)
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
	//�ǵݹ����
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

		SBTNode<K, V> *parent = nullptr; //ָ��cur ��ǰ��
		SBTNode<K, V> *cur = _root;
		while (cur)
		{
			if (cur->key > key)  //�����
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

	//�������
	void InOrder(SBTNode<K, V>* root)
	{
		if (root == nullptr)
		{
			return; //�ݹ��������
		}

		SBTNode<K, V> *cur = root;
		InOrder(cur->_left);
		cout << cur->key << " ";
		InOrder(cur->_right);
	}

	//���ڵ���Զ����
	int find_max_len(Node *t)
	{
		if (t == NULL)
		{
			return 0;
		}

		int left_max_len = find_max_len(t->_left);
		int right_max_len = find_max_len(t->_right);

		if (t->_left) {
			t->left_height = 1 + max(t->_left->left_height, t->_left->right_height);

		}
		if (t->_right) {
			t->right_height = 1 + max(t->_right->left_height, t->_right->right_height);

		}

		int max_len = max(left_max_len, right_max_len);
		max_len = max(max_len, t->left_height + t->right_height);

		return max_len;
	}

public:
	SBTNode<K, V> *_root;
};


void Test()
{
	int a[] = {5,3,4,1,7,8,2,6,0,9};
	SBTree<int, int> s1;
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		s1.Insert(a[i],a[i]);
	}
	
	s1.InOrder(s1._root);
	cout << endl;
	cout<<s1.find_max_len(s1._root)<<endl;
	
}
