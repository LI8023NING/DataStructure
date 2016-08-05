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

	//�ݹ����
	bool Insert_R(const K& key, const V& value)
	{
		return _Insert_R(_root,key,value);
	}

	bool _Insert_R(Node* root, const K& key, const V& value)
	{
		if (root == nullptr)
		{
			root = new Node(key, value);
			return true;
		}

		if (root->key > key)
		{
			return _Insert_R(root->_left, key, value);
		}
		else if (root->key < key)
		{
			return _Insert_R(root->_right,key,value);
		}
		else
		{
			cout << key << "����" << endl;
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

	
	SBTNode<K, V>* Find_R(const K& key)
	{
		return _Find_R(_root,key);
	}

	//�ݹ����
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

	//�ǵݹ�ɾ���ڵ�
	bool Remove(const K& key)
	{
		//1.rootΪ��
		if (_root == nullptr)
		{
			return false;
		}

		else if (_root->_left == nullptr && _root->_right == nullptr)
		{
			delete _root;
			_root = nullptr;
			return true;
		}

		Node* parent = nullptr;
		Node* del = _root;
		
		//1.����Ҫɾ����
		while (del)
		{
			if (del->key > key)
			{
				parent = del;
				del = del->_left;
			}
			else if (del->key < key)
			{
				parent = del;
				del = del->_right;
			}
			else
			{
				//2.��û�д����������ҵ�����
				break;
			}
		}

		//3.����ɾ�ڵ�
		if (del)
		{
			//1.����Ϊ�գ��������滻
			if (del->_left == nullptr)
			{
				if (del == _root)
				{
					_root = del->_right;
				}
				else
				{
					if (del == parent->_left)
						parent->_right = del->_right;
					else
						parent->_left = del->_right;
				}
			}

			//2.����Ϊ�գ��������滻
			else if (del->_right == nullptr)
			{
				if (del == _root)
				{
					_root = del->_left;
				}
				else
				{
					if (del == parent->_left)
						parent->_left = del->_left;
					else
						parent->_right = del->_left;
				}
			}

			//3.������������Ϊ�յ����
			else
			{
				Node* subRight = del->_right;
				Node* firstInder = del->_right;
				//���ұ߽ڵ���������ĵ�һ���ڵ�
				while (firstInder->_left)
				{
					parent = firstInder;
					firstInder = firstInder->_left;
				}

				//����
				swap(firstInder->key,del->key);
				swap(firstInder->value,del->value);

				if (firstInder = parent->_left)
					parent->_left = firstInder->_right;
				else
					parent->_right = firstInder->_right;

				del = firstInder;
			}
			delete del;
		}
		else
		{
			cout << "û�������" << endl;
			return false;
		}
	}

	//�ݹ�ɾ���ڵ�
	bool Remove_R(const K& key)
	{
		return _Remove_R(_root,key);
	}

	bool _Remove_R(Node*& root, const K& key)
	{
		if (root == nullptr)
			return false;
		if (root->key > key)
		{
			return _Remove_R(root->_left,key);
		}
		else if (root->key < key)
		{
			return _Remove_R(root->_right,key);
		}
		else
		{
			Node* del = root;
			if (root->_left == nullptr)
			{
				root = root->_right;
				delete del;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
				delete del;
			}
			else
			{
				Node* firstInder = root->_right;
				while (firstInder->_left)
				{
					firstInder = firstInder->_left;
				}

				swap(del->key,firstInder->key);
				swap(del->value, firstInder->value);

				_Remove_R(firstInder,key);
			}
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


public:
	SBTNode<K, V> *_root;
};

