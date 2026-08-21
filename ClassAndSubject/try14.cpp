#include<iostream>
using namespace std;
#include<string>
#include<fstream>


void test01()
{
	//ofstream ofs;
	//ofs.open("test.txt", ios::out);
	//ofs << "姓名：张三" << endl;
	//ofs << "性别：女" << endl;
	//ofs << "年龄：18" << endl;
	//ofs.close();

	ifstream ifs;

	ifs.open("test.txt", ios::in);

	if(!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据
	////第一种
	//char buf[1024] = { 0 };
	//while(ifs>>buf)
	//{
	//	cout << buf << endl;
	//}

	////第二种
	//char buf[1024] = { 0 };
	//while( ifs.getline(buf,sizeof(buf)) )
	//{
	//	cout << buf << endl;
	//}

	////第三种
	//string buf;

	//while(getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}

	//第四种
	char c;
	while((c = ifs.get())!=EOF)
	{
		cout << c;
	}



	ifs.close();


}



int main()
{
	
	test01();
	//test02();
	return 0;
}