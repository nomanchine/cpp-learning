#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}

	string m_name;
	int m_age;
};


template<class T>
int Mysum(T a,T b)
{
	return a + b;
}

template<> int Mysum(Person &a, Person &b)//为这些特定的类型提供具体的模板
{
	return a.m_age + b.m_age;
}



void test01()
{
	int a = 10;
	int b = 20;
	Mysum(a, b);
	Person p1("Tom", 16);
	Person p2("Tom", 16);
	Mysum(p1, p2);//模板的通用并不是万能的
}


int main()
{
	
	test01();
	//test02();
	return 0;
}