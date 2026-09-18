#include<iostream>
using namespace std;
#include<string>
#include<vector>


void myPrint(vector<int>&v)
{
	if (v.empty())
	{
		cout << "该容器为空" << endl;
		return;
	}

	else
	{
		for (vector<int>::iterator it = v.begin();it != v.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
}





void test1()
{
	vector<int> v1;

	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	v2 = vector(v1.begin(), v1.end());       //将v[begin(),end()]区间中的元素拷贝给本身

	myPrint(v1);
	
	myPrint(v2);

	vector<int> v3(2, 3);                  //构造函数将n个elem拷贝给本身

	myPrint(v3);

	v3 = vector(v2);                        //拷贝构造函数
	myPrint(v3);

	vector<int> v4;
	v4.assign(8, 5);                        //将n个elem拷贝赋值给本身。
	myPrint(v4);


	vector<int> v5;
	v5.assign(v1.begin(), v1.end());
	myPrint(v5);


	vector<int> v6;
	myPrint(v6);
	

	cout << v1.capacity() << endl;
	cout << v1.size() << endl;

	v1.reserve(4);
	v2.reserve(20);

	myPrint(v1);

	myPrint(v2);

	v3.resize(5, 6);
	v4.resize(10, 5);

	myPrint(v3);
	
	myPrint(v4);


	v1.insert(v1.begin() + 3, 555);

	v2.insert(v2.begin() + 5, 6, 666);

	myPrint(v1);
	myPrint(v2);

	v3.erase(v3.begin() + 1);
	v4.erase(v4.begin() + 2, v4.end()-2);

	myPrint(v3);

	myPrint(v4);

	v5.clear();
	myPrint(v5);



}


void test2()
{
	vector<int> v1;
	for (int i = 10;i > 0;i--)
	{
		v1.push_back(i);
	}

	//两种遍历
	//1、operator[]
	for(int i = 0;i<v1.size();i++)
	{
		cout << v1[i];
	}
	cout << endl;
	//2、at
	for (int i = 0;i < v1.size(); i++)
	{
		cout << v1.at(i);
	}
	cout << endl;

	cout << v1.front() << endl;
	cout << v1.back() << endl;
}

void test3()
{
	vector<int> v1;
	for (int i = 10;i > 0;i--)
	{
		v1.push_back(i);
	}

	myPrint(v1);

	vector<int> v2;

	for (int i = 0;i < 10;i++)
	{
		v2.push_back(i);
	}

	myPrint(v2);

	v1.swap(v2);
	myPrint(v1);
	myPrint(v2);


	//2、实际用途
	//巧用swap可以收缩内存空间
	vector<int> v3;

	for (int i = 0;i < 100000;i++)
	{
		v3.push_back(i);
	}
	cout << "v3的容量" << v3.capacity() << endl;
	cout << "v3的大小" << v3.size() << endl;

	v3.resize(3);
	cout << "v3的容量" << v3.capacity() << endl;
	cout << "v3的大小" << v3.size() << endl;


	//巧用swap收缩内存
	vector<int>(v3).swap(v3);   //也可以写vector<int> v4(v3);只是v4作为一个匿名对象，没有给它起名字；而且这句代码执行完后这个匿名对象会被销毁
	cout << "v3的容量" << v3.capacity() << endl;
	cout << "v3的大小" << v3.size() << endl;
}


void test4()
{
	vector<int>v1;
	vector<int>v;
	int* p = NULL;
	int num = 0;

	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);

		if(p!=&v[0])
		{
			p =& v[0];
			num++;
		}
	}
	cout << num << endl;

	v1.reserve(100000);
	* p = NULL;
	 num = 0;
	for (int i = 0;i < 100000;i++)
	{
		v1.push_back(i);

		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;

	

}

int main()
{

	test1();

	test2();

	test3();
	test4();

	system("pause");

	return 0;

}
