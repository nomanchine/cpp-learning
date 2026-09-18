#include<iostream>
using namespace std;
#include<string>

template<typename T1,class T2 = int>
class Person
{
public:
	Person(T1 name,T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void showPerson()
	{
		cout << "姓名： " << m_name << "   年龄： " << m_age << endl;
	}
	T1 m_name;
	T2 m_age;
};


class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<typename T>
class Myclas
{
public:
	T obj;
	//类模板中成员函数
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};



void test01()
{
	//1. 类模板没有自动类型推导的使用方式
	//Person p1("孙悟空", 999);
	Person<string,int> p1("孙悟空",999);
	p1.showPerson();
}

void test02()
{
	//2. 类模板在模板参数列表中可以有默认参数
	//在声明Person模板时，可以给T2设置数据类型
	Person<string> p2("猪八戒", 888);
	p2.showPerson();
}

void test03()
{
	Myclas<Person1>m;
	m.func1();
	Myclas<Person2>n;
	n.func2();
}

//类模板实例化的对象，向函数传参的方式

//1. 指定传入的类型-- - 直接显示对象的数据类型

void test04()
{
	Person<string, int>p("孙悟空", 999);
	p.showPerson();
}


//2. 参数模板化-- - 将对象中的参数变为模板进行传递
template<class T1, class T2>
void showPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的数据类型：" << typeid(T1).name() << endl;
	cout << "T2的数据类型：" << typeid(T2).name() << endl;
}

void test05()
{
	Person<string, int>p("猪八戒", 999);
	showPerson2(p);
}


//3. 整个类模板化-- - 将这个对象类型 模板化进行传递
template<class T>
void showPerson3(T& p)
{
	p.showPerson();
}
void test06()
{

	Person<string, int>p("唐僧", 29);
	showPerson3(p);
}

template<class T>
class Base
{
	T m;
};

//class Son : public Base//错误，必须要知道父类中的T类型，才能给子类继承
class Son : public Base<int>
{

};

//如果想灵活指定出父类中T的类型，子类也需要变为类模板
template<class T1,class T2>
class Son2 : public Base<T2>
{
	T1 obj;
};

void test07()
{
	Son2<int, char>S2;//int传给T1，char传给T2，T2又传给父类中的m
}

int main()
{
	
	//test01();
	//test02();
	test03();
	test04();
	test05();
	test06();
	return 0;
}