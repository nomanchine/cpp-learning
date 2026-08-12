#include<iostream>
using namespace std;
#include<string>


class Person
{
public:
	//Person()
	//{
	//	cout << "Person的默认函数调用" << endl;
	//}

	//1、如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
	Person(int age,int height)
	{
		m_age = age;

		m_Height = new int(height);
	}

	~Person()
	{
		//将堆区开辟的数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}


	//2、如果用户定义拷贝构造函数，C++不会再提供其他构造函数
	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person &p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//m_Height = p.m_Height;         不写拷贝，编译器默认实现这行代码
		
		//深拷贝
		m_Height = new int(*p.m_Height);
	}


	int m_age;//年龄
	int* m_Height;//身高
};

void test01()
{
	//Person();        会报错
	Person a(10,160);
	Person a1(a);
	cout <<"a的年龄" << a.m_age << endl;
	cout << "a1的年龄" << a1.m_age << endl;     //浅拷贝

	cout << "a的身高" << *a.m_Height << endl;
	cout << "a1的身高" << *a1.m_Height << endl;
}

int main()
{
	
	test01();

	return 0;
}