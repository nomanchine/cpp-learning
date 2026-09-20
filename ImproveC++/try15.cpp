#include<iostream>
using namespace std;
#include<string>
#include<map>



class Person
{
public:

	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class Compare
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.m_age > p2.m_age;
	}
};

void printMap( map<Person,int, Compare>&m)
{
	for(map<Person,int, Compare>::iterator it = m.begin();it!=m.end();it++)
	{
		cout << "姓名：" << (*it).first.m_name << "  年龄：" << it->first.m_age << "  分数：" << it->second<< endl;
	}
	
}



void test1()
{
	map<Person, int, Compare>m;
	Person p1("Tom", 30);
	Person p2("Lucy", 40);
	Person p3("Jery", 29);
	Person p4("Ben", 25);
	Person p5("Gewen", 20);

	//插入
	//第一种
	m.insert(pair<Person, int>(p1, 69));

	//第二种
	m.insert(make_pair(p2, 85));

	//第三种
	m.insert(map<Person, int>::value_type(p3, 77));

	//第四种
	m[p4] = 89;

	m.insert(make_pair(p5, 95));

	map<Person, int, Compare>m2;
	m2 = m;
	printMap(m);



}


int main()
{

	test1();
	//test2();
	//test3();
	//test4();
	//test5();

	system("pause");
	return 0;
}