#include<iostream>
using namespace std;
#include<string>


void Myswap(int a, int b)
{
	cout << "调用普通函数" << endl;
}


template<class T>
void Myswap(T a,T b)
{
	cout << "调用模板" << endl;
}
template<class T>
void Myswap(T a, T b,T c)//函数模板也可以发生重载
{
	cout << "调用模板" << endl;
}



void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	char d = 'd';
	Myswap(a, b);//如果函数模板和普通函数都可以实现，优先调用普通函数
	Myswap(d, c);//如果函数模板可以产生更好的匹配，优先调用函数模板
	Myswap<>(a, b);//可以通过空模板参数列表来强制调用函数模板

}


int main()
{
	
	test01();
	//test02();
	return 0;
}