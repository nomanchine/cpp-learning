#include<iostream>
using namespace std;
#include<string>

class myFunction
{
public:
	myFunction()
	{
		this->num = 0;
	}

	void function(string word)
	{
		cout << word << endl;
		num++;
	}

	int num;
};

void doprint(myFunction &mf,string word)
{
	mf.function(word);
}

void test1()
{
	myFunction mf;
	//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
	mf.function("hello word");

	//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
	mf.function("hello word");
	mf.function("hello word");
	mf.function("hello word");
	cout << mf.num << endl;

	//3.函数对象可以作为参数传递
	doprint(mf, "caogaola");
}


int main()
{


	test1();
	

	system("pause");
	return 0;
}