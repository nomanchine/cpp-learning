#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<functional>
#include<algorithm>

//1.内建函数对象    算数仿函数

//negate  一元仿函数  取反仿函数
void test1()
{
	negate<int> n;
	cout << n(50) << endl;
}
//plus  二元仿函数  加法
void test2()
{
	plus<int>p;

	cout << p(10, 30) << endl;
}

//2.内建函数对象     关系仿函数
//大于   greater
void test3()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);

	sort(v.begin(), v.end(), greater<int>());
	for(vector<int>::iterator it = v.begin();it !=v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test4()
{
	//3.内建函数对象        逻辑仿函数
	//逻辑非   logical_not
	vector<bool>v;

	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(true);

	for (vector<bool>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//利用逻辑非  将容器v 搬运到  容器2v2中，并执行取反操作
	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
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