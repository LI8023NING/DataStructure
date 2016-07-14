/************************************
 ** Auth: 李宁
 ** Date: 2016/7/28
 ** Desc: 单链表
 ************************************/

#include"约瑟夫环.h"

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
	*pHead = (ListNode*)malloc(sizeof(ListNode));
	if (pHead == NULL)
	{
		printf("失败\n");
		return;
	}
	(*pHead)->next = NULL;//改变了指针的指向 总之 是对地址操作
}

//插入节点//尾插法
void Insert(ListNode* pHead, DataType x)
{
	ListNode* tial = pHead;
	ListNode* pos;
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

//遍历单链表
void PrintList(ListNode* pHead)
{
	ListNode* cur = pHead;
	assert(pHead);
	cur = cur->next;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("%s\n", "NULL");
}

//翻转单链表
ListNode* Revers(ListNode* pHead)
{
	ListNode* newhead = NULL;
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
void Delete(ListNode* pHead, DataType x)
{
	ListNode* cur = pHead;
	cur = cur->next;
	while (cur)
	{
		if (cur->data == x)
		{
			ListNode* p = cur->next;
			cur->data = p->data;
			cur->next = p->next;
			free(p);
			break;
		}
		cur = cur->next;
	}
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{

	if (pListHead == NULL || k < 0)
	{
		return NULL;
	}
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;
	for (int i = 0; i < k - 1; i++)
	{
		fast = fast->next;
	}
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}


//从未到头打印单链表
void printListFromTailToHead(ListNode* head)
{
	if (head == NULL)
	{
		return;
	}
	ListNode* newhead;
	newhead = NULL;
	ListNode* cur = head;
	while (cur)
	{
		ListNode* tmp = cur;
		cur = cur->next;
		tmp->next = newhead;
		newhead = tmp;
	}
	ListNode* p = newhead;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
}