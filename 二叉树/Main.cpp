#include"BinaryTree.h"

void Test()
{
	BinaryTreeNode<int>* _root = NULL;
	int a[7] = {1,2,'#','#',3,'#','#'};
	BinaryTree<int> s1(a,10);
	cout<<"�������"<<endl;
	s1.PrveOrder(s1._root);
	cout<<endl;
	cout<<"�������"<<endl;
	s1.InOrder(s1._root);
	cout<<endl;
	cout<<"�������"<<endl;
	s1.PostOrder(s1._root);
	cout<<endl;
	cout<<"�������"<<endl;
	s1.LevelOrder(s1._root);
	cout<<endl;
	int size = 0;
	//cout<<"Size:"<<s1.Size(s1._root,size)<<endl;
	cout<<"Depth:"<<s1.Depth(s1._root)<<endl;
	
	cout<<"Find:"<<s1.Find(s1._root,1)<<endl;
	cout<<"��С��"<<s1.GetNodeNum(s1._root)<<endl;

	cout<<"��K��Ľڵ�����"<<s1.GetNodeNumKthLevel(s1._root,2)<<endl;
	cout<<"Ҷ�ӽڵ�����"<<s1.GetLeafNodeNum(s1._root)<<endl;
}

void Test1()
{
	int prev[7] = {10,6,4,8,14,12,16};
	int in[7] = {4,6,8,10,12,14,16};
	BinaryTree<int> s1;
	BinaryTreeNode<int>* p = s1.Construct(prev,in,7);
	s1.LevelOrder(p);
}

int main()
{
	//Test();
	Test1();
	return 0;
}