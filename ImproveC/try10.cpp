#include<iostream>
using namespace std;
#include<string>
#include<vector>

#include<algorithm>   //标准算法头文件


void myPrint(int val)
{
	cout << val << endl;
}

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};



void test1()
{
	vector<Person>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 230);
	Person p4("ddd", 50);
	Person p5("eee", 80);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
	{
		cout << "姓名：" << (*it).m_name << "  年龄：" << (*it).m_age << endl;
	}

}

//存放自定义数据类型 指针
void test2()
{
	vector<Person*>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 230);
	Person p4("ddd", 50);
	Person p5("eee", 80);

	v.push_back(&p1);//& 在这里是取地址
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << (*it)->m_name << "  年龄：" << (*it)->m_age << endl;
	}
}


int main()
{

	test1();

	test2();

	system("pause");

	return 0;

}
