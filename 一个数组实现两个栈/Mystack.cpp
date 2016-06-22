#include<iostream>
using namespace std;

template<typename Comparable>
class DoubleStack
{
public:
	DoubleStack( int m = 10 ) 
		: max( m ) 
	{
		V = new Comparable[max];
		leftTop = -1;
		rightTop = max;
	}

 bool push( int i, Comparable x )
 {
	if ( i == 0 )
	{
		if( leftTop < rightTop - 1 )
		{
			V[ ++ leftTop ] = x;
			return true;
		}
		else
			return false;
	 }
	else
	{
		if ( rightTop > leftTop + 1 )
		{
			V[ -- rightTop ] = x;
			return true;
		}
		else
			return false;
	}
 }

 Comparable pop( int i )
 {
	if ( i == 0 )
		return V[ leftTop -- ];
	else
		return V[ rightTop ++ ];
 }


 bool isEmpty( int i ) 
 {
	if ( i == 0 )
		return leftTop == -1;
	else
		return rightTop == max;
 }

 bool isFull( int i )
 {
	if ( i == 0 )
		return leftTop + 1 == rightTop;
	else
		return rightTop - 1 == leftTop;
 }

 ~DoubleStack() 
 { 
	 delete V;
 }

private:
	Comparable *V;
	int max;
	int leftTop;
	int rightTop;
};


void Test()
{
	DoubleStack<int> s(15);
	s.push(0,1);
	s.push(1,1);
	s.push(1,1);
	s.push(1,1);
	s.push(1,1);
	s.push(1,1);
	s.push(1,1);
	s.push(1,1);
	s.push(1,1);

}

int main()
{
	Test();
	return 0;
}