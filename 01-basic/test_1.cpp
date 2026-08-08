#include<iostream>
using namespace std;

int* fun()
{
	int a = 10;
	return &a;
}
int* fun1()
{
	//利用new关键字将数据开辟到堆区
	int* p = new int(10);
	return p;
}


int main()
{
	int* p = fun();

	cout << *p << endl;//第一次可以打印正确数据

	cout << *p << endl;//第二次不再保留

    int* p = fun1();
	cout << *p << endl;//手动释放堆区前，一直可以正确打印


	system("pause");
	return 0;
}