#include<iostream>
using namespace std;
#include<string>

class CPU
{
public:
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU * cpu,VideoCard * vc,Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()
	{
		m_cpu->calculate();
		
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		if(m_cpu!=NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}

	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
//Intel厂商
class IntelCPU:public CPU
{
public:
	void calculate()
	{
		cout << "IntelCPU开始计算了" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Intel显卡开始运行了" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel内存开始存储了" << endl;
	}
};
//Lenovo厂商
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "LenovoCPU开始计算了" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo显卡开始运行了" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo内存开始存储了" << endl;
	}
};

void test01()
{
	CPU* intelCPU = new IntelCPU;
	VideoCard* lenovoCard = new LenovoVideoCard;
	Memory* intelMem = new IntelMemory;

	Computer* com = new Computer(intelCPU, lenovoCard, intelMem);
	com->work();
	delete com;
}



int main()
{
	
	test01();
	//test02();
	return 0;
}