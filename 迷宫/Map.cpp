/*迷宫上课代码中 第入口是3 是因为 入口的左边不通 、因为是负的了
//跳转至右边 ，右边上下不通，又是先左，正好又回到入口了 这个时候
//入口的左右都死了 只有到循环的最后 附上三。。。。*/


#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//获取迷宫数字
void GetMazeMap(int* a,int row,int col)
{
	FILE* fOut = fopen("Map.txt","r"); //只读的方式打开
	assert(fOut);
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col;)
		{
			char ch = fgetc(fOut); 
			if(ch == '0' || ch == '1')
			{
				a[i*col + j] = ch - '0';//将所有的字符 转换为数字 col由外部传来
				j++;
			}
		}
	}
	fclose(fOut);
}

//打印迷宫
void PrintMaze(int* a,int row,int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout<<a[i*col + j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

struct pos//入口
{
	int row;
	int col;
};

//检查迷宫是否有入口
bool CheckIsAccess(int* a, int rowSize, int colSize, pos cur)
{
	if(cur.row < rowSize && cur.col < colSize
		&&cur.row >= 0 && cur.col >= 0
		&& a[cur.row * colSize + cur.col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//寻找迷宫路径
//stack是一个栈 pos是一个结构体类型 这是模板 stack<pos> 又是一个类型
stack<pos> GetMazePath(int* a, int rowSize, int colSize, pos entry)
{
	stack<pos> paths;
	pos cur = entry; //入口坐标付给 cur；
	paths.push(entry); //入口坐标入栈

	while(!paths.empty())  //如果栈不为空
	{
		pos cur = paths.top();//cur 指向栈顶坐标；
		pos next = cur;

		if(next.row == rowSize - 1)
		{
			return paths;
		}
		
 /************************************************
 //每个左边的上下左右均判断，如果通路 坐标入栈，如果
 //不同就放弃
 //
 //***********************************************/
		//坐标左
		next = cur;
		if(next.col == entry.col && next.row == entry.row)
		{
			a[next.row * colSize + next.col] = 2;
		}
		next.col--; //此处可能将列减成负的了 之后判断
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			paths.push(next);
			continue;
		}

		// 右
		next = cur;
		next.col++;
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			cur = next;
			paths.push(next);
			continue;
		}

		// 上
		next.row--;
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			paths.push(next);
			continue;
		}

		// 下
		next = cur;
		next.row++;
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			paths.push(next);
			continue;
		}

		pos top = paths.top();
		a[top.row* colSize + top.col] = 3;
		paths.pop();
	}

	cout<<"没有"<<endl;
	return paths;
}


void Test()
{
	int a[10][10] = {};
	GetMazeMap((int*)a, 10, 10);
	PrintMaze((int*)a, 10, 10);

	pos entry = {2,0};  //入口是 第三行 第零列
	GetMazePath((int*)a,10,10,entry);
	PrintMaze((int*)a, 10, 10);
}

int main()
{
	Test();
	return 0;
}