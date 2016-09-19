#include"BinaryTree.h"

void Test()
{
	BinaryTreeNode<int>* _root = NULL;
	int a[11] = { 1, 2, 3, '#', '#','#',4,'#',5,'#','#'};
	BinaryTree<int> s1(a,11);
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
	cout << endl;
	cout << "�ǵݹ�ǰ�����" << endl;
	s1.PrevOrder_NonR();
	cout << endl;
	cout <<"�ǵݹ�������"<< endl;
	s1.PostOrder_NonR();
	cout<<endl;
	int size = 0;
	//cout<<"Size:"<<s1.Size(s1._root,size)<<endl;
	cout<<"Depth:"<<s1.Depth(s1._root)<<endl;
	
	cout<<"Find:"<<s1.Find(s1._root,7)<<endl;
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
	Test();
	//Test1();
	return 0;
}