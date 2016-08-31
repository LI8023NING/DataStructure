#pragma once

//每一个节点的结构
struct node
{
	int key;  //关键字，在桶中统计桶中数据量，在数据节点中就是节点的数据
	struct node *next;
};

//声明：
void PrintBucketSort(node** bucket, int bucket_size);
int f(int x);

void BucketSort(int* a, int size,int bucket_size)
{
	assert(a);
	
	//给桶申请空间
	node** bucket = new node*[bucket_size*sizeof(node)]; 

	//初始化
	for (int i = 0; i < bucket_size; ++i)
	{
		bucket[i] = new node[sizeof(node)]; //每一个桶
		bucket[i]->key = 0;
		bucket[i]->next = nullptr;
	}

	for (int j = 0; j < size; ++j)
	{
		node* sub_node = new node[sizeof(node)]; //桶下的每一个节点
		sub_node->key = a[j];
		sub_node->next = nullptr;

		//计算这数据在哪个桶中
		int num = f(a[j]);

		//让一个指针指向这个桶号的头
		node* sub_head = bucket[num];

		//开始插入
		if (sub_head->next == nullptr)
		{
			bucket[num]->next = sub_node;
			bucket[num]->key++;
		}
		//该桶号不为空，那么插入排序
		else
		{
			while (sub_head->next != nullptr && sub_node->key >= sub_head->next->key)
			{
				sub_head = sub_head->next;
			}

			sub_node->next = sub_head->next;
			sub_head->next = sub_node;
			bucket[num]->key++;
		}
	}
	//打印
	PrintBucketSort(bucket, bucket_size);
}

//映射函数
int f(int x)
{
	return (x / 10);
}

//打印
void PrintBucketSort(node** bucket, int bucket_size)
{
	//多少桶链(桶号)
	for (int i = 0; i < bucket_size; ++i)
	{
		node* cur = bucket[i]->next;
		while (cur)
		{
			cout << cur->key << " ";
			cur = cur->next;
		}
	}
	cout << endl;
}

void Test7()
{
	int a[10] = { 49, 38, 35, 97, 76, 73, 27, 49, 34, 78 };
	cout << "桶排序" << endl;
	BucketSort(a, 10, 10);  //桶数据最大才97，所以需要10个桶
}