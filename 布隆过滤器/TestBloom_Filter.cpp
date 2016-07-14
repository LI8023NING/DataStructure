#pragma once

#include"Bloom_Filter.h"

void Test()
{
	Bloom_Filter<> bloom_filter(100);
	bloom_filter._Set("lining");
	cout << bloom_filter._IsIn("lining") << endl;
	cout << bloom_filter._IsIn("zhangning") << endl;
}

int main()
{
	Test();
	return 0;
}