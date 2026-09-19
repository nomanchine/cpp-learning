#include<iostream>
using namespace std;
#include<string>
#include<set>


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


void printSet(set<int>&s)
{
	if(s.empty())
	{
		cout << "该容器为空" << endl;
	}
	else
	{
		//cout << "该容器不为空" << endl;
		//cout << "该容器大小为：" << s.size() << endl;
		for (set<int>::iterator it = s.begin();it != s.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
}

void test1()
{
	set<int> s1;
	s1.insert(200);
	s1.insert(20);
	s1.insert(2100);
	s1.insert(30);
	s1.insert(20);

	set<int> s2;
	s2.insert(201);
	s2.insert(200);
	s2.insert(210);
	s2.insert(30);
	s2.insert(20);
	s2.insert(20);
	s2.insert(20);

	set<int>::iterator it;
	it = s1.find(2000);
	if(it!=s1.end())
	{
		cout << "找到了" << *it << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	cout << "s1容器里面有多少个20？" << "   回答：" << s1.count(20) << endl;

	cout << "交换前：" << endl;
	printSet(s2);
	printSet(s1);

	cout << "交换后：" << endl;
	s1.swap(s2);
	printSet(s2);
	printSet(s1);

	s1.erase(s1.begin());
	printSet(s1);

	s1.clear();
	s2.erase(s2.begin(), s2.end());
	printSet(s2);
	printSet(s1);
}

void test2()
{
	set<int> s1;
	pair<set<int>::iterator,bool> its = s1.insert(10);
	if(its.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}


	multiset<int> m1;
	m1.insert(10);
	m1.insert(10);
	m1.insert(100);
	m1.insert(100);
	m1.insert(100);

	for (multiset<int>::iterator it = m1.begin();it != m1.end();it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test3()
{
	Person p1("孙悟空", 999);
	Person p2("八戒", 777);

	pair<Person, Person> p(p1, p2);

	cout << "姓名：" << p.first.m_name << "  年龄：" << p.second.m_age << endl;

	pair<Person, Person> pi = make_pair(p1, p2);
	cout << "姓名：" << pi.second.m_name << "  年龄：" << pi.first.m_age << endl;
}

class Compare
{
public:
	bool operator ()(int val1,int val2) const
	{
		return val1 > val2;
	}
};

void test4()
{
	set<int,Compare>s1;

	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(60);
	s1.insert(70);
	s1.insert(40);

	for(set<int,Compare>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;


}

class MyCompare
{
public:
	bool operator()(Person p1,Person p2) const
	{
		return p1.m_age > p2.m_age;
	}
};

void test5()
{
	set<Person,MyCompare>s;
	Person p1("Tom", 20);
	Person p2("Jery", 30);
	Person p3("Tony", 19);
	Person p4("Lucy", 49);
	Person p5("Ben", 39);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	for (set<Person, Compare>::iterator it = s.begin();it != s.end();it++)
	{
		cout << "姓名：" << (*it).m_name << " 年龄：" << it->m_age << endl;
	}
	cout << endl;



}

int main()
{

	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	system("pause");
	return 0;
}