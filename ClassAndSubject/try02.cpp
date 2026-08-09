#include<iostream>
using namespace std;
#include<string>

class Cube
{
public:

	int getH()
	{
		return m_H;
	}
	void setH(int h)
	{
		m_H = h;
	}
	int getL()
	{
		return m_L;
	}
	void setL(int l)
	{
		m_L = l;
	}
	int getW()
	{
		return m_W;
	}
	void setW(int w)
	{
		m_W = w;
	}
	int dadculateS()
	{
		int s = 2 * m_W * m_L + 2 * m_W * m_H + 2 * m_L * m_H;
		return s;
	}
	int dadculateV()
	{
		int v = m_W * m_H * m_L;
		return v;
	}

	void isSame(Cube &c2)
	{
		if (m_H ==c2.getH() && m_L ==c2.getL() && m_W == c2.getW())
		{
			cout << "c1和c2两个立方体相同" << endl;
		}
		else
		{
			cout << "c1和c2两个立方体不同" << endl;
		}
	}

private:
	int m_H;
	int m_W;
	int m_L;
};


bool isSame(Cube& c1, Cube& c2)
{
	if(c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}
	else 
	{
		return false;
	}
}


int main()
{
	Cube c1;
	Cube c2;

	c1.setH(11);
	c1.setL(15);
	c1.setW(16);

	cout << "立方体的面积为" << c1.dadculateS() << "\t" << "立方体的体积为" << c1.dadculateV() << endl;

	c2.setH(10);
	c2.setL(10);
	c2.setW(10);


	if(isSame(c1,c2))
	{
		cout << "c1和c2两个立方体相同" << endl;
	}
	else 
	{
		cout << "c1和c2两个立方体不同" << endl;
	}

	c1.isSame(c2);


	system("pause");
	return 0;
}