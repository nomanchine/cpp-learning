#include<iostream>
using namespace std;
#include<string>

class Point
{
public:
	
	void setX(int x)
	{
		p_x = x;
	}
	int getX()
	{
		return p_x;
	}
	void setY(int y)
	{
		p_y = y;
	}
	int getY()
	{
		return p_y;
	}


private:
	int p_x;
	int p_y;
};

class Cycle
{
public:

	void setR(int r)
	{
		m_r = r;
	}
	int getR()
	{
		return m_r;
	}
	void setCenter(Point &c1)
	{
		m_cneter = c1;
	}
	Point getCenter()
	{
		return m_cneter;
	}


private:

	int m_r;
	Point m_cneter;
};

void wherePoint(Cycle &c,Point &p)
{
	int distenceP = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int distenceR = c.getR() * c.getR();
	if(distenceP == distenceR)
	{
		cout << "点在圆上" << endl;
	}
	else if(distenceP < distenceR)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}

int main()
{
	

	Point p;
	Point center;

	p.setX(10);
	p.setY(9);

	center.setX(10);
	center.setY(0);

	Cycle c;
	c.setR(10);
	c.setCenter(center);

	wherePoint(c, p);
	
	system("pause");
	return 0;
}