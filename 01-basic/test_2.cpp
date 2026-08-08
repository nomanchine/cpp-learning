#include<iostream>
using namespace std;

int* fun1()
{
	//利用new关键字将数据开辟到堆区
	int* p = new int(10);
	return p;
}


int main()
{
	int* p = fun1();
	cout << *p << endl;
	delete p;//利用delete释放对取数据

	//这个时候cout<< *p <<endl;会出现报错，释放的空间不可访问

	int* arr = new int[10];
	for(int i=0;i<10;i++)
	{
		arr[i] = i + 100;
	}
	for(int i=0;i<10;i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}