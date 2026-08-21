#include<iostream>
using namespace std;
#include<string>

class AbstractCalculate
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
class AddCalculate:public AbstractCalculate
{
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}
};
class SubCalculate :public AbstractCalculate
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
class MulCalculate :public AbstractCalculate
{
public:
	int getResult()
	{
		return m_num1 * m_num2;
	}
};

void test01()
{
	AbstractCalculate* abs;
	abs = new AddCalculate;
	abs->m_num1 = 100;
	abs->m_num2 = 100;
	abs->getResult();
	cout << "结果是" << abs->getResult() << endl;
}




int main()
{
	
	test01();
	//test02();
	return 0;
}