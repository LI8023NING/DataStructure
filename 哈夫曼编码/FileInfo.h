#pragma once

#include<string>
#include<iostream>
using namespace std;

typedef long long LongType;
struct FileInfo
{
	unsigned char _ch;       //×Ö·û
	LongType _count;         //×Ö·û³öÏÖ´ÎÊý
	string _code;            //×Ö·û¶ÔÓ¦µÄ¹þ·òÂü±àÂë 

	FileInfo(unsigned char ch = 0)
		:_ch(ch)
		,_count(0)
	{}



	FileInfo operator+(const FileInfo& x)
	{
		FileInfo tmp;
		tmp._count = this->_count + x._count;
		return tmp;
	}

	bool operator !=(const FileInfo& x) const
	{
		return this->_count != x._count;
	}
};

bool operator<(const FileInfo info1,const FileInfo info2)
{
	return info1._count < info2._count;
}


