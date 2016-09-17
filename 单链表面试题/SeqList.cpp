#include"Configer.h"

typedef int DataType;

//结构体 链表
typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
}ListNode;

//初始化链表
void InitList(ListNode** pHead)
{
	*pHead = nullptr;
}

//插入节点//尾插法
void Insert(ListNode** pHead,DataType x)
{
	ListNode* tial = *pHead;
	ListNode* pos;
	if (tial == nullptr)
	{
		*pHead = (ListNode*)malloc(sizeof(ListNode));
		(*pHead)->data = x;
		(*pHead)->next = nullptr;
	}
	else
	{
		pos = (ListNode*)malloc(sizeof(ListNode));
		if (pos == NULL)
		{
			printf("Error\n");
			return;
		}
		while (tial->next != NULL)
		{
			tial = tial->next;
		}
		pos->data = x;
		tial->next = pos;
		pos->next = NULL;
	}
}

//遍历单链表
void PrintList(ListNode* pHead)
{
	ListNode* cur = pHead;
	assert(pHead);
	while(cur)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("%s\n","NULL");
}

//翻转单链表
ListNode* Revers(ListNode* pHead)
{
	assert(pHead);

	ListNode* newhead = nullptr;
	ListNode* cur = pHead;

	while (cur)
	{
		ListNode* tmp = cur;
		cur = cur->next;
		tmp->next = newhead;
		newhead = tmp;
	}
	return newhead;
}

//删除节点
void Delete(ListNode* pHead,DataType x)
{
	ListNode *del = pHead;
	while (del)
	{
		if (del->data == x)
		{
			ListNode *de = del->next;
			del->next = de->next;
			del->data = de->data;
			free(de);
			break;
		}
		del = del->next;
	}
}

//寻找倒数K
ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
	if (pHead == nullptr || k == 0)
		return nullptr;

	ListNode* fast = pHead;
	ListNode* slow = pHead;

	for (int i = 0; i < k - 1; ++i)
	{
		fast = fast->next;
	}

	while (fast->next != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}


//从未到头打印单链表
void printListFromTailToHead(ListNode* head)
{
	//if (head == nullptr)
	//	return;
	//
	//printListFromTailToHead(head->next);
	//cout << head->data << "->";

	stack<DataType> node;
	ListNode* cur = head;
	while (cur)
	{
		node.push(cur->data);
		cur = cur->next;
	}

	while (!node.empty())
	{
		cout << node.top()<< "->";
		node.pop();
	}
	cout << endl;
}

//找链表中间节点
ListNode* FindMidNode(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* onestep = head;
	ListNode* twostep = head;

	while (twostep->next != nullptr)
	{
		if (twostep->next->next == nullptr)
		{
			return onestep;
			break;
		}

		onestep = onestep->next;
		twostep = twostep->next->next;
	}

	return onestep;
}

//合并有序单链表
ListNode* Merge(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	ListNode* newhead = NULL;
	ListNode* p1 = NULL;
	ListNode* p2 = NULL;
	if (head1->data < head2->data)
	{
		newhead = head1;
		p1 = head1->next;
		p2 = head2;
	}
	else
	{
		newhead = head2;
		p1 = head1;
		p2 = head2->next;
	}

	ListNode* cur = newhead;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			cur->next = p1;
			cur = p1;
			p1 = p1->next;
		}
		else
		{
			cur->next = p2;
			cur = p2;
			p2 = p2->next;
		}
	}

	if (p1 == NULL)
		cur->next = p2;
	if (p2 == NULL)
		cur->next = p1;

	return newhead;
}

ListNode* Merge_R(ListNode *head1, ListNode *head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	ListNode *newhead = NULL;
	if (head1->data < head2->data)
	{
		newhead = head1;
		newhead->next = Merge_R(head1->next, head2);
	}
	else
	{
		newhead = head2;
		newhead->next = Merge_R(head1,head2->next);
	}
	return newhead;
}

//数组第二大数
int SecondBigDsc(int *a, int size)
{
	//冒泡两次 2n
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				std::swap(a[j],a[j+1]);
			}
		}
		if (i == 1)
			break;
	}
	return a[size-2];
}

int SecondBigDesc(int *a, int size)
{
	//降序冒泡两次
	for (int i = 0; i < size - 1;++i)
	{
		for (int j = size-2; j >= i; j--)
		{
			if (a[j+1] > a[j])
				std::swap(a[j+1],a[j]);
		}
		if (i == 1)
			break;
	}
	return a[1];
}

//方法三
int FindSecondBig(int *a, int size)
{
	int fristBig = a[0];
	int secondBig = a[1];

	for (int i = 2; i < size; ++i)
	{
		if (a[i] > a[0])
			fristBig = a[0];
		else
		{
			if (a[i] > a[1])
				secondBig = a[i];
		}
	}
	return a[1];
}

void Test1()
{
	//ListNode* pHead;
	//InitList(&pHead);

	//Insert(&pHead, 1);
	//Insert(&pHead, 2);
	//Insert(&pHead, 3);
	//Insert(&pHead, 4);
	//Insert(&pHead, 5);
	//Insert(&pHead, 6);
	////Insert(&pHead, 7);
	//PrintList(pHead);

	//cout << FindMidNode(pHead)->data << endl;
	/*Delete(pHead,1);
	PrintList(pHead);*/

	//PrintList(Revers(pHead));

	//cout << FindKthToTail(pHead, 2)->data << endl;

	//printListFromTailToHead(pHead);
	//PrintList(pHead);

	//Delete(pHead,1);
	//PrintList(pHead);
	//Revers(pHead);//错误原来在此 这里翻转一次，下面有反转一次；
	//PrintList(Revers(pHead));
	int a[10] = {1,2,5,4,9,20,6,7,3,0};
	
	cout << SecondBigDsc(a, 10) << endl;
	cout << SecondBigDesc(a, 10) << endl;
	
	cout << FindSecondBig(a, 10) << endl;
}

void main()
{
	Test1();
}