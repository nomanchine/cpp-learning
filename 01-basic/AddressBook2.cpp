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

void showMenu1()
{
	cout << "***********************" << endl;
	cout << "***  1. 修改姓名  ***" << endl;
	cout << "***  2. 修改性别  ***" << endl;
	cout << "***  3. 修改年龄  ***" << endl;
	cout << "***  4. 修改电话  ***" << endl;
	cout << "***  5. 修改地址  ***" << endl;
	cout << "***  6. 退出修改  ***" << endl;
}

//1. 添加联系人 
void addPerson(Addressbooks * abs)
{
	abs->m_size++;
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

	cout << "添加联系人成功" << endl;
	system("pause");
	system("cls");
}

//2. 显示联系人
void showPerson(Addressbooks * abs)
{
	if(abs->m_size == 0)
	{
		cout << "当前联系人为0 " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "下面将会显示所有联系人" << endl;
		for(int i=1; i <= abs->m_size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_name << "\t";
			cout << "性别： " << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_age << "\t";
			cout << "电话： " << abs->personArray[i].m_phone << "\t";
			cout << "住址： " << abs->personArray[i].m_addr << endl;
		}
		system("pause");
		system("cls");
	}
}


//判断联系人是否存在
int isExist(Addressbooks* abs,string name)
{
	for(int i=1; i <= abs->m_size;i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

//3. 删除联系人
void deletePerson(Addressbooks * abs,int j)
{
	for(int i=j; i<=abs->m_size ; i++)
	{
		abs->personArray[i].m_name = abs->personArray[i + 1].m_name;
		abs->personArray[i].m_sex = abs->personArray[i + 1].m_sex;
		abs->personArray[i].m_age = abs->personArray[i + 1].m_age;
		abs->personArray[i].m_phone = abs->personArray[i + 1].m_phone;
		abs->personArray[i].m_addr = abs->personArray[i + 1].m_addr;
	}
	cout << "删除成功" << endl;
	abs->m_size--;
	system("pause");
	system("cls");
}

//4. 查找联系人 
void findPerson(Addressbooks * abs)
{
	string name;
	cout << "请输入联系人的姓名： " << endl;
	cin >> name;
	int i=isExist(abs, name);
	if(i!=-1)
	{
		cout << "查找成功" << endl;
		cout << "姓名： " << abs->personArray[i].m_name << "\t";
		cout << "性别： " << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[i].m_age << "\t";
		cout << "电话： " << abs->personArray[i].m_phone << "\t";
		cout << "住址： " << abs->personArray[i].m_addr << endl;
	
	}
	else
	{
		cout << "查无此人" << endl;
		
	}
}


//5. 修改联系人
void modifyPerson(Addressbooks * abs)
{
	string name;
	cout << "请输入联系人的姓名： " << endl;
	cin >> name;
	int i = isExist(abs, name);
	if (i != -1)
	{
		int select;
		bool flag = true;
		while(flag)
		{
			showMenu1();
			cout << "请选择修改： " << endl;
			cin >> select;
			switch (select)
			{
			case 1:
			{
				string name1;//输入姓名
				cout << "请输入姓名： " << endl;
				cin >> name1;
				abs->personArray[i].m_name = name1;
				break;
			}
			case 2:
			{
				int sex;//输入性别
				cout << "请输入性别，如果是男输入1，如果是女输入2" << endl;
				cin >> sex;
				while (1)
				{
					if (sex == 1 || sex == 2)
					{
						cout << "输入合法" << endl;
						abs->personArray[i].m_sex = sex;
						break;
					}
					else
					{
						cout << "输入不合法，请重新输入： " << endl;
						cin >> sex;
					}
				}
				break;
			}
			case 3:
			{
				int age;//输入年龄
				cout << "请输入年龄： " << endl;
				cin >> age;
				abs->personArray[i].m_age = age;
				break;
			}
			case 4:
			{
				string phone;//输入电话
				cout << "请输入电话： " << endl;
				cin >> phone;
				abs->personArray[abs->m_size].m_phone = phone;
				break;
			}
			case 5:
			{
				string addr;
				cout << "请输入住址： " << endl;
				cin >> addr;
				abs->personArray[abs->m_size].m_addr = addr;
				break;
			}
			case 6:
			{
				flag = false;
				
				break;
			}
			default:
				break;
			}
			
		}
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


//6. 清空联系人
void cleanPerson(Addressbooks * abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
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
		//string name;为什么不能定义在switch里面         case后面不能跟定义语句，必须加大括号
		//int exist;
		switch (select)
		{
		case 1:			//1. 添加联系人 
			addPerson(& abs);   //利用地址传递修饰实参
			break;
		case 2:         //2. 显示联系人
			showPerson(& abs);
			break;
		case 3:			//3. 删除联系人
		{			
			int exist;
			string name;
			cout << "请输入想要删除联系人的姓名： " << endl;
			cin >> name;
			exist = isExist(&abs, name);
			if (exist != -1)
			{
				deletePerson(&abs, exist);
			}
			else
			{
				cout << "查无此人" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 4:			//4. 查找联系人 
			findPerson(&abs);
			system("pause");
			system("cls");
			break;
		case 5:			//5. 修改联系人
			modifyPerson(&abs);
			break;
		case 6:			//6. 清空联系人
			cleanPerson(&abs);
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