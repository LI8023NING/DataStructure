#pragma once
#include"FileInfo.h"
#include"StructOfHuffaMan.h"
#include<assert.h>


//�ļ�ѹ����
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

		//��ǰ�ڵ�ΪҶ�ӽڵ�Ϊ��  �����ɹ���������
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
	//�ļ�ѹ��
	bool Compress(const char* filename)
	{
		//1.��һ���ļ���ͳ���ļ��ַ����ֵĴ���
		//2.���ɶ�Ӧ�Ĺ���������
		//3.ѹ���ļ�
		//4.д�����ļ��������ѹ��

		assert(filename);
		FILE *fOut = fopen(filename, "rb");
		assert(fOut);

		//ͳ���ļ��ַ����ֵĴ���
		unsigned char ch = fgetc(fOut);
		while (!feof(fOut))  //�ļ�����
		{
			_infos[ch]._count++;
			ch = fgetc(fOut);
		}

		HuffmanTree<FileInfo> ht;
		FileInfo invalid;
		ht.CreateTree(_infos, 256, invalid);

		//����������
		_GenerateHuffmanCode(ht.GetRoot());

		string compressFile = filename;
		compressFile += ".huf";

		//ѹ������ļ��� ��׺Ϊ�������ļ���+.huf��
		FILE *finCompress = fopen(compressFile.c_str(), "wb"); //��ȡstring�е�C�ַ���
		assert(finCompress);

		fseek(fOut, 0, SEEK_SET);//���ļ�ָ���Ƶ���ͷ
		char cha = fgetc(fOut);
		unsigned char inch = 0;
		int index = 0;  //һ���ֽڵİ�λ
		while (!feof(fOut))
		{
			string& code = _infos[(unsigned char)cha]._code;

			for (size_t i = 0; i < code.size(); ++i)
			{
				inch <<= 1;     //��λ���λ��
				if (code[i] == '1')
				{
					inch |= 1;
				}

				if (++index == 8)
				{
					fputc(inch, finCompress); //��8λ��װ���ļ�
					index = 0;   //����һ�ֿ�ʼ
					inch = 0;
				}
			}
			cha = fgetc(fOut);
		}

		fclose(fOut);

		//���index = 0 ˵�� �ϱ�8λ�պô��� ���� ��һ���Լ��ֳ�����
		if (index != 0)   //�������һ���ַ�����������
		{
			inch <<= (8 - index); //���λ����װ�� ��ߵ��˷ѵ�
			fputc(inch, finCompress);
		}

		fclose(finCompress);

		//��־�ļ� ��ѹ����
		string logFile = filename;
		logFile += ".log";
		
		FILE *Log = fopen(logFile.c_str(), "wb");
		assert(Log);

		string chInfo;

		char str[128] = {0}; //û�ռ� ������

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

	//�ع��ļ�
	void _RestoreFiles(HuffmanTreeNode<FileInfo> *root, const char* Fileneme,long long size)
	{
		assert(root);

		//ԭѹ���ļ�
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

	
	void UnCompress(const char* Fileneme)//��ѹ��
	{
		//1.����־�ļ�
		//2.������Ϣ��ԭ��������
		//3.��ԭ��Ϣ��
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

		//�����ؽ��Ĺ������� ��ԭ�ļ���
		long long size = f.GetRoot()->_weight._count;
		_RestoreFiles(f.GetRoot(), Fileneme,size);
	}
protected:
	FileInfo _infos[256];
};