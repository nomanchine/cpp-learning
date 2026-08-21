#include<iostream>
using namespace std;
#include<string>

class Animal
{
public:
	virtual void speak()
		//虚函数
	{
		cout << "动物在说话" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak() 
	{
		cout << "小猫在说话" << endl;
	}
};
class Dog :public Animal
{
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
//我们希望传入什么对象，我们就调用什么函数

void DoSpeak(Animal & animal)
{
	animal.speak();
}
/*
多态满足条件：
1、有继承关系
2、子类重写父类中的虚函数
多态使用：
父类指针或引用指向子类对象
*/

void test01()
{
	Cat cat; 
	DoSpeak(cat);
	Dog dog;
	DoSpeak(dog);
}

int main()
{
	
	test01();
	//test02();
	return 0;
}