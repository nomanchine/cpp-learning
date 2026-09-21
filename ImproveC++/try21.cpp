#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

void myprint(int val)
{
	cout << val << " ";
}

class Myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class myprint1
{
public:
	int operator()(int a)
	{
		return a;
	}
};

int Myprint1(int val)
{
	return val;
}

void test1()
{
	vector<int>v;

	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myprint);  //普通函数，不需要加（）
	cout << endl;
	for_each(v.begin(), v.end(), Myprint());   //函数对象，需要加（）
	cout << endl;

	vector<int> v1;

	v1.resize(v.size());

	transform(v.begin(), v.end(), v1.begin(), Myprint1);
	for_each(v1.begin(), v1.end(), myprint);
	
}

class Greater
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	bool operator==(const Person &p) const
	{
		return p.m_age == this->m_age && p.m_name == this->m_name;
	}

	string m_name;
	int m_age;
};

class Greater30
{
public:
	bool operator()(const Person &p) const
	{
		return p.m_age>30;
	}
};

void test2()
{
	vector<int>v;

	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 10);


	if(it==v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}

	vector<int>::iterator it1 = find_if(v.begin(), v.end(), Greater());
	if (it1 == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << *it1 << endl;
	}
	Person p1("Tom", 33);
	Person p2("Jery", 23);
	Person p3("Peder", 13);
	Person p4("Park", 36);

	vector<Person>v2;
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	vector<Person>::iterator it2 = find_if(v2.begin(), v2.end(),Greater30());
	if (it2 == v2.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了大于30岁的人" << (*it2).m_name << endl;
	}


}

void test3()
{
	vector<int>v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(7);
	v.push_back(8);
	v.push_back(5);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}

	int cot = count(v.begin(), v.end(), 5);
	cout << "5出现的次数为:" << cot << endl;

	Person p1("Tom", 33);
	Person p2("Jery", 23);
	Person p6("Lucy", 24);
	Person p3("Peder", 13);
	Person p7("Lucy", 22);
	Person p4("Park", 36);
	Person p5("Lucy", 22);

	Person p8("Lucy", 22);

	vector<Person>v2;
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	v2.push_back(p6);
	v2.push_back(p7);

	int cot2 = count(v2.begin(), v2.end(), p8);
	cout << "Lucy出现的次数为:" << cot2 << endl;
}

void test4()
{
	vector<int>v;

	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}

	bool ret = binary_search(v.begin(), v.end(), 8);

	if(ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}

class Greater_30
{
public:
	bool operator()(const int &val)const
	{
		return val > 30;
	}
};

void test5()
{

	vector<int>v;
	v.push_back(35);
	v.push_back(24);
	v.push_back(25);
	v.push_back(36);
	v.push_back(57);
	v.push_back(17);
	v.push_back(28);
	v.push_back(25);
	v.push_back(85);
	v.push_back(45);

	int cot = count_if(v.begin(), v.end(), Greater_30());

	cout << "大于30的个数为" << cot << endl;



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