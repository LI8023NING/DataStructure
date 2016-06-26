#pragma once
#include<list>

bool flag1 = true;
bool flag2 = false;

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
	//�ǵݹ����
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


	//�ǵݹ���ҽڵ�
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


	//�������������ڵ�������
	//�����ڵ�������������
	//����һ������������
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

	//��������������һ������û���������������ص�
	//��Ϊ�и�ָ�룬ת��Ϊ���������ཻ
	SBTNode<K, V>* _FindLowestCommonAncestc1(Node* root, Node* one, Node* two)
	{
		if (root == nullptr)
			return nullptr;
		//���ҵ��������ڵ�ֱ�Ϊͷ�ڵ����������
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


	//���������ڷ������Ļ����Ͽ���Ч�����⣬�����ظ������ıȽ϶࣬�ý��
	//��Ҫ�����ռ�

	//�����ڵ�������е�·��
	bool GetNodeOfPath(Node* root, Node* pNode, list<Node*>& path) //��������·��
	{
		
		if (root == pNode)
		{
			path.push_back(root);
			flag1 = false;
			return true;
		}

		if (flag1)
		{
			path.push_back(root);
		}

		if (root->_left == nullptr && root->_right == nullptr && flag1)
		{
			path.pop_back();
			return false;
		}

	/*	if (flag2 && root != pNode)
		{
			path.pop_back();
		}*/

		bool flag3 = true;
		bool flag4 = true;

		if (root->_left != nullptr)
		{
			flag3 = GetNodeOfPath(root->_left, pNode, path);
		}

		if (root->_right != nullptr)
		{
			flag4 = GetNodeOfPath(root->_right, pNode, path);
		}

		if (!flag3 && !flag4)
		{
			path.pop_back();
		}
	}

	//�õ�����·���Ĺ����ڵ�
	Node* GetCommonNode
		(
		const list<Node*>& path1,
		const list<Node*>& path2
		)
	{
		list<Node*>::const_iterator iterator1 = path1.begin();
		list<Node*>::const_iterator iterator2 = path2.begin();

		Node* pLast = nullptr;
		while (iterator1 != path1.end() && iterator2 != path2.end())
		{
			if (*iterator1 == *iterator2)
				pLast = *iterator1;

			iterator1++;
			iterator2++;
		}

		return pLast;
	}

	//�õ������������
	Node* GetLowestCommonAncestc(Node* pnode1, Node* pnode2)
	{
		return _GetLowestCommonAncestc(_root, pnode1, pnode2);
	}

	Node* _GetLowestCommonAncestc(Node* root, Node* pnode1, Node* pnode2)
	{
		if (root == nullptr || pnode1 == nullptr || pnode2 == nullptr)
			return nullptr;

	
		//�õ�����·��
		list<Node*> path1;
		GetNodeOfPath(root,pnode1,path1);

		flag1 = true;
		list<Node*> path2;
		GetNodeOfPath(root,pnode2,path2);

		Node* res = GetCommonNode(path1,path2);

		return res;
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

	SBTNode<int, int>* num1 = s1.Find(2);
	SBTNode<int, int>* num2 = s1.Find(9);
	//SBTNode<int, int>* res = s1.FindLowestCommonAncestc1(num1, num2);
	SBTNode<int, int>* res = s1.GetLowestCommonAncestc(num1,num2);
	cout << res->value << endl;
}
