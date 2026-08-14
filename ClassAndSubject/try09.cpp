#include<iostream>
using namespace std;
#include<string>

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;//私有成员只是隐藏了，但是还是会继承下去
};

class Son : public Base
{
public:
	int m_D;
};

//利用开发人员命令提示工具查看对象模型
// Visual Studio  工具  命令行  开发者命令提示
//跳转盘符   F：
//跳转文件路径   cd 具体路径如下
// c1 /d1 reportSingleClassLayout类名 文件名 

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main()
{
	
	test01();
	//test02();
	return 0;
}