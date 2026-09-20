#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<vector>
#include<ctime>

#define CEHUA 1
#define MEISHI 2
#define YANFA 3


class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void setWorker(vector<Worker>&v)
{
	string strSeed = "ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		Worker w ;
		string name = "员工";
		name += strSeed[i];
		w.m_Name = name;

		w.m_Salary = rand() % 10001 + 10000;

		v.push_back(w);
	}
	//测试
	//for(vector<Worker>::iterator it = v.begin();it!=v.end();it++)
	//{
	//	cout << "姓名：" << it->m_Name << "  薪水：" << it->m_Salary << endl;
	//}
}

void setGroupWorker(multimap<int, Worker>& m, vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++)
	{
		int group = rand() % 3 + 1;
		m.insert(make_pair(group, *it));
	}
	//测试
	//for (multimap<int, Worker>::iterator it = m.begin();it != m.end();it++)
	//{
	//	cout << "部门：" << it->first << "  姓名：" << it->second.m_Name << "  薪资：" << it->second.m_Salary << endl;
	//}
}

void showGroupWorker(multimap<int,Worker>&m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	for(int i=0;i<count;i++,pos++)
	{
		cout << "部门：" << pos->first << "  姓名：" << pos->second.m_Name << "  薪资：" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(MEISHI);
	count = m.count(MEISHI);
	for (int i = 0;i < count;i++, pos++)
	{
		cout << "部门：" << pos->first << "  姓名：" << pos->second.m_Name << "  薪资：" << pos->second.m_Salary << endl;
	}


	cout << "------------------------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	for (int i = 0;i < count;i++, pos++)
	{
		cout << "部门：" << pos->first << "  姓名：" << pos->second.m_Name << "  薪资：" << pos->second.m_Salary << endl;
	}


}


void test1()
{
	vector<Worker> vWorker;
	//1、创建十名员工
	setWorker(vWorker);
	//2、给员工分组
	multimap<int, Worker> mWorker;
	setGroupWorker(mWorker, vWorker);

	//3、展示部门和员工信息
	showGroupWorker(mWorker);
}


int main()
{
	srand((unsigned int)time(NULL));

	test1();
	

	system("pause");
	return 0;
}