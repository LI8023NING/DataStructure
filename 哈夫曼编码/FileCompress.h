#pragma once
#include"FileInfo.h"
#include"StructOfHuffaMan.h"
#include<assert.h>


//文件压缩类
class FileCompress
{
public:
	FileCompress()
	{
		for (int i = 0; i < 256; ++i)
		{
			_infos[i]._ch = i;
		}
	}

	~FileCompress()
	{}

public:
	void _GenerateHuffmanCode(HuffmanTreeNode<FileInfo>* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_GenerateHuffmanCode(root->_left);
		_GenerateHuffmanCode(root->_right);

		//当前节点为叶子节点为空  才生成哈夫曼编码
		if (root->_left == nullptr && root->_right == nullptr)
		{
			HuffmanTreeNode<FileInfo>* cur = root;
			HuffmanTreeNode<FileInfo>* parent = cur->_parent;
			string& code = _infos[cur->_weight._ch]._code;

			while (parent)
			{
				if (parent->_left == cur)
				{
					code += '1';
				}
				else if (parent->_right == cur)
				{
					code += '0';
				}
				cur = parent;
				parent = cur->_parent;
			}
			reverse(code.begin(), code.end());
		}
	}

public:
	//文件压缩
	bool Compress(const char* filename)
	{
		//1.打开一个文件，统计文件字符出现的次数
		//2.生成对应的哈弗曼编码
		//3.压缩文件
		//4.写配置文件，方便解压缩

		assert(filename);
		FILE *fOut = fopen(filename, "rb");
		assert(fOut);

		//统计文件字符出现的次数
		unsigned char ch = fgetc(fOut);
		while (!feof(fOut))  //文件结束
		{
			_infos[ch]._count++;
			ch = fgetc(fOut);
		}

		HuffmanTree<FileInfo> ht;
		FileInfo invalid;
		ht.CreateTree(_infos, 256, invalid);

		//哈夫曼编码
		_GenerateHuffmanCode(ht.GetRoot());

		string compressFile = filename;
		compressFile += ".huf";

		//压缩后的文件名 后缀为《输入文件名+.huf》
		FILE *finCompress = fopen(compressFile.c_str(), "wb"); //获取string中的C字符串
		assert(finCompress);

		fseek(fOut, 0, SEEK_SET);//将文件指针移到开头
		char cha = fgetc(fOut);
		unsigned char inch = 0;
		int index = 0;  //一个字节的八位
		while (!feof(fOut))
		{
			string& code = _infos[(unsigned char)cha]._code;

			for (size_t i = 0; i < code.size(); ++i)
			{
				inch <<= 1;     //低位向高位进
				if (code[i] == '1')
				{
					inch |= 1;
				}

				if (++index == 8)
				{
					fputc(inch, finCompress); //够8位，装进文件
					index = 0;   //重新一轮开始
					inch = 0;
				}
			}
			cha = fgetc(fOut);
		}

		fclose(fOut);

		//如果index = 0 说明 上边8位刚好存满 不等 下一个自己又出来了
		if (index != 0)   //处理最后一个字符不够的问题
		{
			inch <<= (8 - index); //最高位必须装上 后边的浪费掉
			fputc(inch, finCompress);
		}

		fclose(finCompress);

		//日志文件 解压缩用
		string logFile = filename;
		logFile += ".log";
		
		FILE *Log = fopen(logFile.c_str(), "wb");
		assert(Log);

		string chInfo;

		char str[128] = {0}; //没空间 不可以

		for (size_t i = 1; i < 256; ++i)
		{
			if (_infos[i]._count > 0)
			{
				chInfo += _infos[i]._ch;
				chInfo += ',';
				chInfo += _itoa(_infos[i]._count,str,10);
				chInfo += '\n';
				fputs(chInfo.c_str(), Log);
				chInfo.clear();
			}
		}

		fclose(Log);
	
		return true;
	}

public:
	bool _ReadLine(FILE *fOutLogFile, string& line)
	{
		char ch = fgetc(fOutLogFile);
		if (feof(fOutLogFile))
			return false;
		else
		{
			if (ch == '\n')
			{
				line += ch;
				ch = fgetc(fOutLogFile);
			}

			while (ch != '\n')
			{
				line += ch;
				ch = fgetc(fOutLogFile);
			}
			return true;
		}
	}

	//重构文件
	void _RestoreFiles(HuffmanTreeNode<FileInfo> *root, const char* Fileneme,long long size)
	{
		assert(root);

		//原压缩文件
		string name = Fileneme;
		name += ".huf";
		
		FILE* Out = fopen(name.c_str(),"rb");
		assert(Out);
		
		string restorefilename = Fileneme;
		restorefilename += ".over";
		FILE *over = fopen(restorefilename.c_str(),"wb");
		assert(over);

		int pos = 8;
		long long poss = size;

		unsigned char chz = fgetc(Out);
		while (poss>0)
		{
			HuffmanTreeNode<FileInfo>* cur = nullptr;
			cur = root;
			while (cur->_left != nullptr || cur->_right != nullptr)
			{
				pos--;
				unsigned char temp = chz >> pos;
				int ch = 1 & temp;
				if (ch == 0)
				{
					cur = cur->_right;
				}

				else if (ch == 1)
				{
					cur = cur->_left;
				}

				if (pos == 0)
				{
					chz = fgetc(Out);
					pos = 8;
				}
			}
			fputc(cur->_weight._ch, over);

			poss--;
		}

		fclose(Out);
		fclose(over);
	}

	
	void UnCompress(const char* Fileneme)//解压缩
	{
		//1.打开日志文件
		//2.根据信息还原哈夫曼树
		//3.还原信息；
		string UnCompressneme = Fileneme;
		UnCompressneme += ".log";
		FILE *fOutLogFile = fopen(UnCompressneme.c_str(), "rb");
		assert(fOutLogFile);

		string line;
		while (_ReadLine(fOutLogFile, line))
		{
			unsigned char ch = line[0];
			_infos[ch]._count = atoi(line.substr(2).c_str());
			line.clear();
		} 

		HuffmanTree<FileInfo> f;
		FileInfo invalid;
		f.CreateTree(_infos, 256, invalid);

		//根据重建的哈夫曼树 还原文件；
		long long size = f.GetRoot()->_weight._count;
		_RestoreFiles(f.GetRoot(), Fileneme,size);
	}
protected:
	FileInfo _infos[256];
};