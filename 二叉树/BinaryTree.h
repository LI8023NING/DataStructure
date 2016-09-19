#pragma once
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

//树中节点结构
template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	//节点需要初始化(赋值)
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

//树的结构
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	//无参构造
	BinaryTree()
		:_root(NULL)
	{}

	//传来一个数组 构造一棵树
	BinaryTree(const T* a,size_t size)
	{
		size_t index = 0;//数组中的下标；
		_root = _CreateTree(a,size,index);
	}

	//拷贝构造
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


	//赋值运算符的重载
	BinaryTree<T>& operator=(const BinaryTree<T>& x)
	{
		if(this != &x)
		{
			BinaryTree<T> tmp(x);
			swap(_root,tmp._root);
		}
		return *this;
	}

	//深度
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

	//查找节点
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

	//大小
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

	//大小
	int GetNodeNum(BinaryTreeNode<T>* root)
	{
		if(root == NULL) //递归出口
		{
			return 0;
		}
		return GetNodeNum(root->_left) + GetNodeNum(root->_right) + 1;
	}


	//中序遍历
	void InOrder(BinaryTreeNode<T>* root)
	{
		if(root != NULL)
		{
			InOrder(root->_left);
			cout<<root->_data<<"-";
			InOrder(root->_right);
		}
	}

	//后序遍历
	void PostOrder(BinaryTreeNode<T>* root)
	{
		if(root != NULL)
		{
			PostOrder(root->_left);
			PostOrder(root->_right);
			cout<<root->_data<<"-";
		}
	}

	//层序遍历
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
	//前序遍历
	void PrveOrder(BinaryTreeNode<T>* root)
	{
		if(root != NULL)
		{
			cout<<root->_data<<"-";
			PrveOrder(root->_left);
			PrveOrder(root->_right);
		}
	}
	
	//求二叉树第K层的节点个数
	//递归解法： 
    //（1）如果二叉树为空或者k<1返回0 
    //（2）如果二叉树不为空并且k==1，返回1 
    //（3）如果二叉树不为空且k>1，返回左子树中k-1层的节点个数与右子树k-1层节点个数之和 
	int GetNodeNumKthLevel(BinaryTreeNode<T>* root, int k)
	{
		if(root == NULL || k < 1)
		{
			return 0;
		}
		if(k == 1) //能下来说明 ROOT不是空
		{
			return 1; //递归结束条件
		}

		int leftNum = GetNodeNumKthLevel(root->_left,k-1);
		int rightNum = GetNodeNumKthLevel(root->_right,k-1);

		return (leftNum+rightNum);
	}

	//求二叉树中叶子节点的个数
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

	//非递归 前序遍历
	void PrevOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s; //栈里边全是指针

		BinaryTreeNode<T> *p = _root;
		while (p || !s.empty())
		{
			while (p != nullptr)  //左路一次打印完成
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

	//非递归 中序遍历
	void InOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s;
		BinaryTreeNode<T>* cur = _root; //cur始终指向头
		while (cur || !s.empty())
		{
			//就是说，将cur指向的所有左路都入栈
			while (cur)
			{
				s.push(cur); //第一次是头入栈；
				cur = cur->_left; //所有左边依次入栈
			}

			//中序遍历 现在访问左 在到右边
			if(!s.empty())
			{
				cur = s.top();
				s.pop();
				cout << cur->_data << " ";
				cur = cur->_right; //走右边
			}
		}
	}

	//非递归，后序遍历
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
				cout << cur->_data << " ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
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

	//深度优先遍历
	//因此可以借助堆栈的数据结构，由于堆栈是后进先出的顺序，
	//由此可以先将右子树压栈，然后再对左子树压栈，
	//这样一来，左子树结点就存在了栈顶上，因此某结点的左子树能在它的右子树遍历之前被遍历。
	void depthFirstSearch(Node* root)
	{
		stack<Node*> TreeNode;
		TreeNode.push(root);        //根节点入栈
		Node* node = nullptr;
		while (!TreeNode.empty())
		{
			node = TreeNode.top();
			cout << node->key << " "; //访问
			TreeNode.pop();

			if (node->_right)         //右子树先入栈
				TreeNode.push(node->_right);

			if (node->_left)          //左子树再入栈
				TreeNode.push(node->_left);
		}
	}

	//广度优先搜索
	//是从根节点开始，沿着树的宽度遍历树的节点。如果所有节点均被访问，则算法中止。
	//类似层序遍历，需要借助队列
	//广度优先遍历
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

			if (node->_left)             //先左再右，一次性入队，在从头出队，一层层遍历
				TreeNode.push(node->_left);
			if (node->_right)
				TreeNode.push(node->_right);
		}
	}

	
	//树中最远两个节点间的距离
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

	//清除
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

	//此二叉树的镜像
	void ToMirror(BinaryTreeNode<T>* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		//交换左右孩子指针
		swap(root->_left,root->_right);

		//递归左右子树同样的操作
		ToMirror(root->_left);
		ToMirror(root->_right);
	}

	//已知树的前序和中序遍历，重建二叉树
	//传来的是两个数组
	Node* Construct(int* prevorder, int* inorder, int length)
	{
		if (prevorder == nullptr || inorder == nullptr || length <= 0)
			return nullptr;
		return _Construct(prevorder,prevorder + length - 1,inorder,inorder + length - 1);
	}

	Node* _Construct(int *startprev, int *endprev, int *startin, int *endin)
	{
		//1.前序遍历第一个元素是二叉树的头
		int rootvalue = startprev[0];
		Node* newroot = new Node();
		newroot->_data = rootvalue;
		newroot->_left = newroot->_right = nullptr;

		//2.如果只有一个元素；也是递归结束条件
		if (startprev == endprev)
		{
			if (startin == endin && *startin == *endin)
			{
				return newroot;
			}
		}

		//3.递归建树
		//中序遍历中找根节点
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
			root->_left = _CreateTree(a,size,++index);//v  为神魔啊  有问题呢 加加不可以放后边
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
