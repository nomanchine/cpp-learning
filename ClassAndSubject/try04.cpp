#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "Person的有参构造函数调用" << endl;
	}

	//拷贝构造函数
	Person(const Person &p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_age = p.m_age;
	}



	~Person()
	{
		cout << "Person调用析构函数"<<endl;
	}

	int m_age;
};

void test01()
{
	//括号法
	Person p;//无参构造函数调用
	Person p1(10);//有参构造
	Person p2(p1);//拷贝构造
	//注意事项1：调用默认构造函数时候，不要加（），Person p();像极了函数声明。

	//2、显示法
	Person p3;
	Person p4 = Person(10);
	Person p5 = Person(p4);

	Person(10);//匿名对象     特点：当前执行结束后，系统会立即回收掉匿名对象
	//注意事项2：不要利用拷贝函数构造 初始化匿名对象
	//如：Person （p3）  会出现语法报错        编译器会以为  Person (p3) == Person p3;  对象声明

	cout << "aaa" << endl;

	//3\隐式转换法
	Person p6(10);//相当于Person p6 = Person(10);


	//1、 使用一个已经创建完毕的对象来初始化一个新对象

	//2、值传递的方式给函数参数传值

	//3、 以值方式返回局部对象



}

int main()
{

	test01();

	system("pause");
	return 0;
}

