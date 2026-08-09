#include<iostream>
using namespace std;
#include<string>

class Circle
{
public:

	int m_r;

	double Chouchang()
	{
		return 2 * 3.14 * m_r;
	}
};

int main()
{
	Circle c1;

	c1.m_r = 2;


	cout << "园的周长是" << c1.Chouchang() << endl;

	system("pause");
	return 0;
}