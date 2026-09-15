#include<iostream>
using namespace std;
#include<string>

//通过全局函数 打印Person信息

//提前让编译器知道Person类的存在
template<class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2>p)
{
	cout << "姓名：" << p.m_name << "   年龄：" << p.m_age << endl;
}

template<class T1,class T2>
class Person
{
	//全局函数 类内实现
	friend void printPerson(Person<T1,T2>p)
	{
		cout << "姓名：" << p.m_name << "   年龄：" << p.m_age << endl;
	}

	//全局函数 类外实现
	//加空模板参数列表
	//如果全局函数是 类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2>p);

public:
	//成员函数类内声明
	Person(T1 name, T2 age);

	
	T1 m_name;
	T2 m_age;
};

template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->m_name = name;
	this->m_age = age;
}



//1、全局函数在类内实现
void test01()
{
	Person<string, int>p("Tom", 220);

	printPerson(p);
}

//2、全局函数在类外实现
void test02()
{
	Person<string, int>p("Jerry", 22);

	printPerson2(p);
}

int main()
{
	test01();
	test02();
	return 0;
}