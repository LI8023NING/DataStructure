#pragma once

//�ڵ�ṹ
template <class K,class V>
struct DoubleListNode
{
	typedef DoubleListNode<K, V> Node;
	K key;
	V value;

	Node* prev;
	Node* next;

	DoubleListNode(const K key,const V value)
		:key(key)
		, value(value)
		, prev(nullptr)
		, next(nullptr)
	{}
};

template<class K,class V>
class DoubleList
{
	typedef DoubleListNode<K, V> Node;
public:
	DoubleList()
		:head(nullptr)
		,tail(nullptr)
	{}

	~DoubleList()
	{}
	
	//β��
	bool PushBack(const K key,const V value);

	//ͷ��
	bool PushFrount(const K key, const V value);

	//βɾ
	bool PopBack();

	//ɾ�ڵ�
	bool Remove(const K& key);

	//��ӡ
	void Print();

	//����ӡ����
	void PrintDoubleListReversing();

	void _Printf(Node* head);

private:
	Node* head;  //����ͷָ��
	Node* tail;  //����βָ��
};

template<class K,class V>
bool DoubleList<K, V>::PushBack(const K key, const V value)
{
	if (head == nullptr)
	{
		head = new Node(key,value);
		tail = head;
		return true;
	}

	Node* cur = new Node(key,value);
	tail->next = cur;
	cur->prev = tail;
	tail = tail->next;

	return true;
}

template<class K, class V>
bool DoubleList<K,V>::PushFrount(const K key, const V value)
{
	if (head == nullptr)
	{
		head = new Node(key, value);
		tail = head;
		return true;
	}

	Node* cur = new Node(key,value);

	cur->next = head;
	head->prev = cur;
	head = head->prev;
	return true;
}

template<class K, class V>
bool DoubleList<K, V>::PopBack()
{
	if (head == nullptr)
	{
		return false;
	}

	Node* del = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete del;
}

template<class K, class V>
bool DoubleList<K, V>::Remove(const K& key)
{
	if (head == nullptr)
		return false;
	
	Node* cur = head;
	while (cur != tail)
	{
		if (cur->key == key)
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			delete cur;
			return true;
		}
		cur = cur->next;
	}
}

template<class K, class V>
void DoubleList<K, V>::Print()
{
	Node* cur = head;
	while (cur)
	{
		cout << cur->key <<"  "<< cur->value <<endl;
		cur = cur->next;
	}
	cout << endl;
}

template<class K, class V>
void DoubleList<K,V>::PrintDoubleListReversing()
{
	_Printf(head);
}

template<class K, class V>
void DoubleList<K, V>::_Printf(Node* head)
{
	if (head != nullptr)
	{
		if (head->next != nullptr)

		{
			_Printf(head->next);//�����ƺ��Ӵ��ж� �����Ժ󣬽����жϵĵط�����ִ��
		}
		cout << head->key <<"   "<< head->value << endl;
	}
}

void Test()
{
	DoubleList<int, string> s1;
	s1.PushBack(1, "�Ұ���");
	s1.PushBack(2, "�㰮��");
	s1.PushBack(3, "������");
	s1.PushFrount(4,"��");
	s1.PushFrount(5, "����");
	s1.PushFrount(6, "������");
	s1.Print();
	s1.PrintDoubleListReversing();
	s1.PopBack();
	s1.Remove(5);
	s1.Print();
}