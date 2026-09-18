#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

class Person
{
public:

	Person(string name,int score)
	{
		this->m_name = name;
		this->m_score = score;
	}

	string m_name;
	int m_score;

};

void createPerson(vector<Person>&v)
{
	string str = "ABCDE";
	for(int i= 0;i<5;i++)
	{
		string name =string("选手") + str[i];
		int score = 0;

		Person p(name, score);
		v.push_back(p);

		
	}
}

void printPerson(vector<Person>&v)
{
	for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
	{
		cout <<(*it).m_name  ;
		cout << "\t平均分：" << (*it).m_score << endl;
	}

}

void setScore(vector<Person> &v)
{
	
	
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		deque<int>d;
		cout << (*it).m_name;
		cout << "\t得分：";
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
			
		}

		sort(d.begin(),d.end());
		d.pop_front();
		d.pop_back();

		int num = 0;

		for (int i = 0; i < d.size(); i++)
		{
			cout << d[i]<<"  ";
			num += d[i];
		}
		(*it).m_score = num / 8;

		cout << endl;
	}
}

void getScore(vector<Person>&v)
{
	for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
	{
		cout << (*it).m_name << "\t平均分：" << (*it).m_score << endl;
	}
}

int main()
{

	srand((unsigned int)time(NULL));

	//1、打印五名选手
	vector<Person> v;
	createPerson(v);//创建五名选手
	//printPerson(v);
	


	//2、十位评委打分
	
	setScore(v);


	cout << "下面输出最终结果：" << endl;
	//3、输出每位选手平均分
	getScore(v);

	system("pause");

	return 0;

}
