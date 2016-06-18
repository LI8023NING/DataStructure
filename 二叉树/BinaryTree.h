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
			swap(_root,x._root);
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
		else if(root->_data == x)
		{
			return root;
		}
		else
		{
			BinaryTreeNode<T>* tem =Find(root->_left,x);

			if(tem)
			{
				return tem;
			}
			else 
			{
				return Find(root->_right,x);
			}
		}

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
		{
			return;
		}
		q.push(root);
		while (!q.empty())
		{
			BinaryTreeNode<T>* node = q.front();
	
			cout << node->_data << " ";
			q.pop();
			if (node->_left != nullptr)
			{
				q.push(node->_left);
			}

			if (node->_right != nullptr)
			{
				q.push(node->_right);
			}
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
		if (_root != NULL)
		{
			s.push(_root)  //头不空 头入栈
		}
		while (!s.empty())
		{
			BinaryTreeNode<T>* top = s.top();//取栈顶
			s.pop();                         //出栈
			cout << top->_data << " ";
			if (_root->_left)              //左右访问
			{
				s.push(_root->_left);
			}
			if (_root->_right)
			{
				s.push(_root->_right);
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
			while (!s.empty())
			{
				BinaryTreeNode<T>* top = s.top();
				s.pop();
				cout << top->_data << " ";
				cur = top->_right; //走右边
			}
		}
	}

	//非递归，后序遍历
	void PostOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s;
		BinaryTreeNode<T>* cur = _root;
		BinaryTreeNode<T>* prevVisted = NULL;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			BinaryTreeNode<T>* top = s.top();
			if (top->_right == NULL || top->_right = prevVisted)
			{
				cout << top->_data << " ";
				prevVisted = top;
				s.pop();
			}
			else
			{
				cur = top->_right;
			}
		}
		cout << endl;
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
