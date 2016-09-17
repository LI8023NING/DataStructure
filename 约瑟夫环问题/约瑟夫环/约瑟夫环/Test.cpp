 #include"SeqList.h"

/*
**˼·��
**1.������N���ڵ����ͷ�ڵ��ѭ������
**2.ȷ����һ�������˵�λ��
**3.һֱ��������ɾ���ڵ� ֪������Ϊ��
*/

//nΪ������ k��ʾ��һ����ʼ��������  m��������ߺ�����
void JosephRing(int n,int k,int m)
{
	//1.����ѭ������
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

	//2.��һ����ʼ���������Ѷ�
	ListNode* people = NULL;
	while (k--)
	{
		people = head;
		head = head->next;
	}

	ListNode* r = NULL;
	while (n--) //nÿ��һ�� ��һ����
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
	JosephRing(10,2,3); //10���ˣ���2��ʼ����������3���ˣ�ɱ��
	return 0;
}