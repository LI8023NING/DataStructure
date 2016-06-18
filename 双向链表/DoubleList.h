#pragma once

//节点结构
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
	
	//尾插
	bool PushBack(const K key,const V value);

	//头插
	bool PushFrount(const K key, const V value);

	//尾删
	bool PopBack();

	//删节点
	bool Remove(const K& key);

	//打印
	void Print();

	//反打印链表
	void PrintDoubleListReversing();

	void _Printf(Node* head);

private:
	Node* head;  //链表头指针
	Node* tail;  //链表尾指针
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
			_Printf(head->next);//函数似乎从此中断 回来以后，接着中断的地方继续执行
		}
		cout << head->key <<"   "<< head->value << endl;
	}
}

void Test()
{
	DoubleList<int, string> s1;
	s1.PushBack(1, "我爱你");
	s1.PushBack(2, "你爱我");
	s1.PushBack(3, "她爱我");
	s1.PushFrount(4,"哈");
	s1.PushFrount(5, "哈哈");
	s1.PushFrount(6, "哈哈哈");
	s1.Print();
	s1.PrintDoubleListReversing();
	s1.PopBack();
	s1.Remove(5);
	s1.Print();
}