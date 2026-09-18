#include<iostream>
using namespace std;
#include<string>

#include"MyArray.hpp"

class Person
{
public:

	Person(){}

	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;

	int m_age;
};

void printInArray1(MyArray<Person> &arr1)
{
	for (int i = 0;i < arr1.Get_Size();i++)
	{
		cout << "姓名：" <<arr1[i].m_name<<"    年龄"<<arr1[i].m_age<< endl;
	}
}

void printInArray(MyArray<int> &arr)
{
	for(int i = 0;i<arr.Get_Size();i++)
	{
		cout << arr[i] << endl;
	}
}

void test1()
{
	MyArray<int> arr(5);
	for(int i =1;i<6;i++)
	{
		arr.Push_Back(i);
	}
	arr.Get_Capacity();
	arr.Get_Size();

	printInArray(arr);

	cout << "输出尾删后的数组：" << endl;
	arr.Pop_Back();
	printInArray(arr);
}

void test2()
{
	Person p1("赵云", 29);
	Person p2("貂蝉", 19);
	Person p3("黄忠", 49);
	Person p4("关羽", 39);
	Person p5("韩信", 23);
	Person p6("牛魔", 200);

	MyArray<Person> arr1(6);
	arr1.Push_Back(p1);
	arr1.Push_Back(p2);
	arr1.Push_Back(p3);
	arr1.Push_Back(p4);
	arr1.Push_Back(p5);
	arr1.Push_Back(p6);

	printInArray1(arr1);
}


int main()
{

	test1();

	test2();

	system("pause");

	return 0;

}
