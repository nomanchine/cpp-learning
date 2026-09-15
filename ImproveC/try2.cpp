#include<iostream>
using namespace std;
#include<string>


int swap(int a, int b)
{
	return a + b;
}


template<class T>
int Myswap(T a,T b)
{
	return a + b;
}




void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	Myswap(a, b);
	swap(a, c);
	Myswap<int>(a, c);

}