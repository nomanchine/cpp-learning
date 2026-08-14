#include<iostream>
using namespace std;
#include<string>

class Animal
{
public:
	int m_age;
};
//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类（虚父类）
class Sheep : virtual public Animal{};
class Tuo : virtual public Animal{};
class SheepTuo :public Sheep , public Tuo{};



void test01()
{
	SheepTuo st;
	st.Sheep::m_age = 100;
	st.Tuo::m_age = 200;
	cout << "st.Sheep::m_age = " << st.Sheep::m_age<< endl;
	cout << "st.Tuo::m_age = " << st.Tuo::m_age << endl;
	cout << "st.m_age =" << st.m_age << endl;
}

int main()
{
	
	test01();
	//test02();
	return 0;
}