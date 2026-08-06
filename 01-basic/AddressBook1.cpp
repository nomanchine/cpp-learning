#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

struct Addressbooks
{
	struct Person personArray [MAX];
	int m_size;
};


void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1. 添加联系人  *****" << endl;
	cout << "*****  2. 显示联系人  *****" << endl;
	cout << "*****  3. 删除联系人  *****" << endl;
	cout << "*****  4. 查找联系人  *****" << endl;
	cout << "*****  5. 修改联系人  *****" << endl;
	cout << "*****  6. 清空联系人  *****" << endl;
	cout << "*****  0. 退出通讯录  *****" << endl;
}

//1. 添加联系人 
void addPerson(Addressbooks * abs)
{
	string name;//输入姓名
	cout << "请输入姓名： " << endl;
	cin >> name;
	abs->personArray[abs->m_size].m_name = name;

	int sex;//输入性别
	cout << "请输入性别，如果是男输入1，如果是女输入2" << endl;
	cin >> sex;
	while(1)
	{
		if (sex == 1 || sex == 2)
		{
			cout << "输入合法" << endl;
			abs->personArray[abs->m_size].m_sex = sex;
			break;
		}
		else 
		{
			cout << "输入不合法，请重新输入： " << endl;
			cin >> sex;
		}
	}

	int age;//输入年龄
	cout << "请输入年龄： " << endl;
	cin >> age;
	abs->personArray[abs->m_size].m_age = age;

	string phone;//输入电话
	cout << "请输入电话： " << endl;
	cin >> phone;
	abs->personArray[abs->m_size].m_phone = phone;

	string addr;
	cout << "请输入住址： " << endl;
	cin >> addr;
	abs->personArray[abs->m_size].m_addr = addr;


	abs->m_size++;
	cout << "添加联系人成功" << endl;
	system("pause");
	system("cls");
}


int main() 
{
	//创建通讯录结构体变量并出初始化m_size
	Addressbooks abs;
	abs.m_size = 0;

	bool flag = true;

	while(flag)
	{
		showMenu();
		int select;
		cout << "请输入您的选择： " << endl;
		cin >> select;
		switch (select)
		{
		case 1:			//1. 添加联系人 
			addPerson(& abs);   //利用地址传递修饰实参
			break;
		case 2:         //2. 显示联系人
			break;
		case 3:			//3. 删除联系人
			break;
		case 4:			//4. 查找联系人 
			break;
		case 5:			//5. 修改联系人
			break;
		case 6:			//6. 清空联系人
			break;
		case 0:			//0. 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");		//"请按任意键继续. . ."
			flag = false;
			break;
		default:
			break;
		}
	}


	return 0;
}