#include<iostream>
using namespace std;
#include<string>
#include<vector>

#include<algorithm>   //标准算法头文件




void myPrint(int val)
{
	cout << val << endl;
}

void test1()
{
	//创建vector容器
	vector<int> v;

	//插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();//起始迭代器
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置

	cout << typeid(v.begin()).name() << endl;
	
	//第一种遍历方式
	while(itBegin != itEnd)
	{
		cout << *itBegin << endl;//解引用迭代器，拿到迭代器指向的元素。
		itBegin++;
	}

	//第二种遍历方式
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout << *it << endl;
	}

	//第三种遍历方式  利用STl提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);



}