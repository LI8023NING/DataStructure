/************************************
 ** Auth: ����
 ** Date: 2016/7/28
 ** Desc: ������
 ************************************/

#include"Լɪ��.h"

typedef int DataType;

//�ṹ�� ����
typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
}ListNode;

//��ʼ������
void InitList(ListNode** pHead)
{
	*pHead = (ListNode*)malloc(sizeof(ListNode));
	if (pHead == NULL)
	{
		printf("ʧ��\n");
		return;
	}
	(*pHead)->next = NULL;//�ı���ָ���ָ�� ��֮ �ǶԵ�ַ����
}

//����ڵ�//β�巨
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

//����������
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

//��ת������
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

//ɾ���ڵ�
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


//��δ��ͷ��ӡ������
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