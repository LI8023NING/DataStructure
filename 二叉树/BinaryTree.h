#pragma once
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

//���нڵ�ṹ
template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	//�ڵ���Ҫ��ʼ��(��ֵ)
	BinaryTreeNode(const T& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
	{}

	BinaryTreeNode()
		:_data(0)
		, _left(NULL)
		, _right(NULL)
	{}
};

//���Ľṹ
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	//�޲ι���
	BinaryTree()
		:_root(NULL)
	{}

	//����һ������ ����һ����
	BinaryTree(const T* a,size_t size)
	{
		size_t index = 0;//�����е��±ꣻ
		_root = _CreateTree(a,size,index);
	}

	//��������
	BinaryTree(const BinaryTreeNode<T>& x)
	{
		_root = _Copy(x);
	}

	BinaryTree<T>* _Copy(BinaryTreeNode<T>* root)
	{	
		if (root == NULL)
		{
			return NULL;
		}
		
		BinaryTreeNode<T>* newRoot = new BinaryTreeNode<T>(root->_data);
		newRoot->_left = _Copy(root->_left);
		newRoot->_right = _Copy(root->_right);

		return newRoot;
	}


	//��ֵ�����������
	BinaryTree<T>& operator=(const BinaryTree<T>& x)
	{
		if(this != &x)
		{
			BinaryTree<T> tmp(x);
			swap(_root,tmp._root);
		}
		return *this;
	}

	//���
	int Depth(BinaryTreeNode<T>* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		else
		{
			int leftlenth = Depth(root->_left);
			int rightlenth = Depth(root->_right);

			return leftlenth > rightlenth ? leftlenth + 1 : rightlenth + 1;
		}
	}

	//���ҽڵ�
	BinaryTreeNode<T>* Find(BinaryTreeNode<T>* root,const T& x)
	{
		if(root == NULL)
		{
			return NULL;
		}

		if(root->_data == x)
		{
			return root;
		}

		Find(root->_left,x);

		Find(root->_right,x);
	}

	//��С
	//int Size(BinaryTreeNode<T>* root,int& size)
	//{
	//	if(root == NULL)
	//	{
	//		return 0;
	//	}
	//	else
	//	{
	//	    ++size;
	//	}
	//	Size(root->_left,size);
	//	Size(root->_right,size);
	//	return size;
	//}

	//��С
	int GetNodeNum(BinaryTreeNode<T>* root)
	{
		if(root == NULL) //�ݹ����
		{
			return 0;
		}
		return GetNodeNum(root->_left) + GetNodeNum(root->_right) + 1;
	}


	//�������
	void InOrder(BinaryTreeNode<T>* root)
	{
		if(root != NULL)
		{
			InOrder(root->_left);
			cout<<root->_data<<"-";
			InOrder(root->_right);
		}
	}

	//�������
	void PostOrder(BinaryTreeNode<T>* root)
	{
		if(root != NULL)
		{
			PostOrder(root->_left);
			PostOrder(root->_right);
			cout<<root->_data<<"-";
		}
	}

	//�������
	void LevelOrder(BinaryTreeNode<T>* root)
	{
		queue<BinaryTreeNode<T>*> q;

		if (root == nullptr)
			return;

		q.push(root);
		while (!q.empty())
		{
			BinaryTreeNode<T>* node = q.front();
			cout << node->_data << " ";
			q.pop();

			if (node->_left != nullptr)
				q.push(node->_left);

			if (node->_right != nullptr)
				q.push(node->_right);
		}
	}
	//ǰ�����
	void PrveOrder(BinaryTreeNode<T>* root)
	{
		if(root != NULL)
		{
			cout<<root->_data<<"-";
			PrveOrder(root->_left);
			PrveOrder(root->_right);
		}
	}
	
	//���������K��Ľڵ����
	//�ݹ�ⷨ�� 
    //��1�����������Ϊ�ջ���k<1����0 
    //��2�������������Ϊ�ղ���k==1������1 
    //��3�������������Ϊ����k>1��������������k-1��Ľڵ������������k-1��ڵ����֮�� 
	int GetNodeNumKthLevel(BinaryTreeNode<T>* root, int k)
	{
		if(root == NULL || k < 1)
		{
			return 0;
		}
		if(k == 1) //������˵�� ROOT���ǿ�
		{
			return 1; //�ݹ��������
		}

		int leftNum = GetNodeNumKthLevel(root->_left,k-1);
		int rightNum = GetNodeNumKthLevel(root->_right,k-1);

		return (leftNum+rightNum);
	}

	//���������Ҷ�ӽڵ�ĸ���
	int GetLeafNodeNum(BinaryTreeNode<T>* root)
	{
		if(root == NULL)
		{
			return 0;
		}

		if(root->_left == NULL && root->_right == NULL)
		{
			return 1;
		}
		
		int leftNum = GetLeafNodeNum(root->_left);
		int rightNum = GetLeafNodeNum(root->_right);
		return leftNum+rightNum;
	}

	//�ǵݹ� ǰ�����
	void PrevOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s; //ջ���ȫ��ָ��

		BinaryTreeNode<T> *p = _root;
		while (p || !s.empty())
		{
			while (p != nullptr)  //��·һ�δ�ӡ���
			{
				cout << p->_data << " ";
				s.push(p);
				p = p->_left;
			}

			if (!s.empty())
			{
				p = s.top();
				s.pop();
				p = p->_right;
			}
		}
		cout << endl;
	}

	//�ǵݹ� �������
	void InOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s;
		BinaryTreeNode<T>* cur = _root; //curʼ��ָ��ͷ
		while (cur || !s.empty())
		{
			//����˵����curָ���������·����ջ
			while (cur)
			{
				s.push(cur); //��һ����ͷ��ջ��
				cur = cur->_left; //�������������ջ
			}

			//������� ���ڷ����� �ڵ��ұ�
			if(!s.empty())
			{
				cur = s.top();
				s.pop();
				cout << cur->_data << " ";
				cur = cur->_right; //���ұ�
			}
		}
	}

	//�ǵݹ飬�������
	void PostOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s;
		BinaryTreeNode<T>* cur = nullptr;
		BinaryTreeNode<T>* prevVisted = NULL;

		s.push(_root);
		while (!s.empty())
		{
			cur = s.top();
			if ((cur->_left == NULL && cur->_right == NULL) ||
				((prevVisted != NULL) && (prevVisted == cur->_left || prevVisted == cur->_right)))
			{
				cout << cur->_data << " ";  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
				s.pop();
				prevVisted = cur;
			}

			else
			{
				if (cur->_right != NULL)
					s.push(cur->_right);
				if (cur->_left != NULL)
					s.push(cur->_left);
			}
		}


	
		cout << endl;
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

	
	//������Զ�����ڵ��ľ���
#define max(a, b) ((a) > (b) ? (a) : (b))
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

	//���
	void _Destroy(BinaryTreeNode<T>*& root)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->_left == NULL || root->_right == NULL)
		{
			delete root;
			root = NULL;
			return;
		}

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	//�˶������ľ���
	void ToMirror(BinaryTreeNode<T>* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		//�������Һ���ָ��
		swap(root->_left,root->_right);

		//�ݹ���������ͬ���Ĳ���
		ToMirror(root->_left);
		ToMirror(root->_right);
	}

	//��֪����ǰ�������������ؽ�������
	//����������������
	Node* Construct(int* prevorder, int* inorder, int length)
	{
		if (prevorder == nullptr || inorder == nullptr || length <= 0)
			return nullptr;
		return _Construct(prevorder,prevorder + length - 1,inorder,inorder + length - 1);
	}

	Node* _Construct(int *startprev, int *endprev, int *startin, int *endin)
	{
		//1.ǰ�������һ��Ԫ���Ƕ�������ͷ
		int rootvalue = startprev[0];
		Node* newroot = new Node();
		newroot->_data = rootvalue;
		newroot->_left = newroot->_right = nullptr;

		//2.���ֻ��һ��Ԫ�أ�Ҳ�ǵݹ��������
		if (startprev == endprev)
		{
			if (startin == endin && *startin == *endin)
			{
				return newroot;
			}
		}

		//3.�ݹ齨��
		//����������Ҹ��ڵ�
		int* inroot = startin;
		while (inroot <= endin && *inroot != rootvalue)
			++inroot;
		int leftlength = inroot - startin;
		int* leftendprev = startprev + leftlength;
		if (leftlength > 0)
		{
			newroot->_left = _Construct(startprev + 1, leftendprev, startin, inroot - 1);
		}
		if (leftlength < endprev - startprev)
		{
			newroot->_right = _Construct(leftendprev+1,endprev,inroot+1,endin);
		}

		return newroot;
	}

protected:
	BinaryTreeNode<T>* _CreateTree(const T* a,size_t size,size_t& index)
	{
		if(a[index] != '#' && index < size)	
		{
			BinaryTreeNode<T>* root = new BinaryTreeNode<T>(a[index]);
			root->_left = _CreateTree(a,size,++index);//v  Ϊ��ħ��  �������� �ӼӲ����Էź��
			root->_right = _CreateTree(a,size,++index);	
            return root;
		}
		else
		{
			return NULL;
		}
	}

public:
	BinaryTreeNode<T>* _root;
};
