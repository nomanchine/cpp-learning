#include<iostream>
using namespace std;
#include<string>

class Myint
{
	friend ostream& operator<<(ostream& cout, const Myint& myint);
public:
	Myint()
	{
		m_num = 0;
	}

	//重载前置--运算符  
	// 返回引用，返回当前对象本身，避免产生临时对象
	Myint& operator--()
	{
		//先--
		m_num--;
		cout << this << endl;   //打印地址
		cout << &m_num << endl;
		//再返回
		return *this;
	}
	//重载后置--运算符
	//void operator--(int)   int代表占位参数，可以用于区分前置和后置递减
	Myint operator--(int)
	{
		//先  记录当时结果
		Myint temp = *this;
		//后 递减
		m_num--; 
		//最后将记录返回
		return temp;
		//不能返回引用，temp这里是一个局部对象，当前函数执行完后，temp就被释放了
	}

private:
	int m_num;
};

ostream& operator<<(ostream &cout,const Myint  &myint)
{
	cout << myint.m_num;
	return cout;
}

void test01()
{
	Myint myint;
	cout <<-- myint<<endl ;
}

void test02()
{
	Myint myint;
	cout << myint -- << endl;
	cout << myint << endl;
}


int main()
{
	
	test01();
	test02();
	return 0;
}