#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
	
	//1、通过成员函数重载+号
	//Person operator+(Person &p)
	//{
	//	Person temp;
	//	temp.m_A = p.m_A + this->m_A;
	//	temp.m_B = p.m_B + this->m_B;
	//	return temp;
	//}
	int m_A;
	int m_B;
};
//2、全局函数重载+
Person operator+(Person &p1,Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
class Person1
{
public:
	friend ostream& operator<<(ostream& cout, Person1& p);
	Person1(int a,int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//成员函数实现不了，因为p.operator<<(cout)     p<<cout不是我们想要的结果
	//不会利用成员函数重载<<运算符，因为无法实现cout在左侧
private:
	int m_A;
	int m_B;
};
//只能利用全局函数重载左移运算符
ostream& operator<<(ostream &cout,Person1 &p)//本质  operator<<(cout,p)  简化cout<<p;
{
	cout << "m_A  = " << p.m_A << "  m_B = " << p.m_B;
	return cout;
}
void test01()
{
	Person p1;
	Person p2;
	p1.m_A = 10;
	p1.m_B = 10;
	p2.m_A = 10;
	p2.m_B = 10;
	Person p3 = p1 + p2;
	cout << p3.m_A << p3.m_B << endl;
}
void test02()
{
	Person1 p4(10, 10);
	cout << p4;
}
int main()
{
	
	test01();
	test02();
	return 0;
}