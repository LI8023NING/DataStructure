#pragma once
#include<stack>
#include<queue>

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

	//��  //������ͬ
	int longestPath(Node* root)
	{
		int left_len, right_len, max_len;
		longestPathUtil(root, left_len, right_len, max_len);
		return max_len;
	}

	void longestPathUtil(Node* root, int& left_len, int& right_len, int& max_len)
	{
		if (root == NULL)
		{
			left_len = 0;
			right_len = 0;
			max_len = 0;
			return;
		}

		int left_len1, right_len1, left_len2, right_len2;
		longestPathUtil(root->left, left_len1, right_len1, max_len);
		longestPathUtil(root->right, left_len2, right_len2, max_len);

		left_len = 1 + max(left_len1, right_len1);
		right_len = 1 + max(left_len2, right_len2);
		max_len = max(left_len + right_len - 1, max_len);
	}

	//������ȱ���
	//��˿��Խ�����ջ�����ݽṹ�����ڶ�ջ�Ǻ���ȳ���˳��
	//�ɴ˿����Ƚ�������ѹջ��Ȼ���ٶ�������ѹջ��
	//����һ�������������ʹ�����ջ���ϣ����ĳ����������������������������֮ǰ��������
	void depthFirstSearch(Node* root)
	{
		stack<Node*> TreeNode;
		TreeNode.push(root);        //���ڵ���ջ
		Node* node = nullptr;
		while (!TreeNode.empty())
		{
			node = TreeNode.top();
			cout << node->key << " "; //����
			TreeNode.pop();

			if (node->_right)         //����������ջ
				TreeNode.push(node->_right);

			if (node->_left)          //����������ջ
				TreeNode.push(node->_left);
		}
	}

	//�����������
	//�ǴӸ��ڵ㿪ʼ���������Ŀ�ȱ������Ľڵ㡣������нڵ�������ʣ����㷨��ֹ��
	//���Ʋ����������Ҫ��������
	//������ȱ���
	void breadthFirstSearch(Node* root)
	{
		if (root == nullptr)
			return;

		queue<Node*> TreeNode;
		Node* node = nullptr;

		TreeNode.push(root);
		while (!TreeNode.empty())
		{
			node = TreeNode.front();
			cout << node->key << " ";
			TreeNode.pop();

			if (node->_left)             //�������ң�һ������ӣ��ڴ�ͷ���ӣ�һ������
				TreeNode.push(node->_left);
			if (node->_right)
				TreeNode.push(node->_right);
		}
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
	s1.depthFirstSearch(s1._root);
	cout << endl;
	s1.breadthFirstSearch(s1._root);
	
}
