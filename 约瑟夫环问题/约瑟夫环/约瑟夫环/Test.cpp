 #include"SeqList.h"

/*
**思路：
**1.建立有N个节点的无头节点的循环链表
**2.确定第一个报数人的位置
**3.一直在链表中删除节点 知道链表为空
*/

//n为总人数 k表示第一个开始报数的人  m代表出列者喊的数
void JosephRing(int n,int k,int m)
{
	//1.建立循环链表
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 1;
	head->next = head;

	ListNode* cur = head;
	for (int i = 2; i <= n; ++i)
	{
		ListNode* insert = (ListNode*)malloc(sizeof(ListNode));
		insert->data = i;
		insert->next = cur->next;
		cur->next = insert;
		cur = insert;
	}

	//2.第一个开始报数的人已定
	ListNode* people = NULL;
	while (k--)
	{
		people = head;
		head = head->next;
	}

	ListNode* r = NULL;
	while (n--) //n每减一次 少一个人
	{
		for (int i = 1; i < m; ++i,r = people, people = people->next)
		{
			;
		}

		r->next = people->next;
		printf("%d ->",people->data);
		free(people);
		people = r->next;
	}
}

int main()
{
	JosephRing(10,2,3); //10个人，从2开始报数，数到3的人，杀掉
	return 0;
}