#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<vector>
#include<random>


void myPrint(int val)
{
	cout << val << " ";
}
class Print
{
public:
	void operator()(int val) const
	{
		cout << val << " ";
	}
};

class greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test1()
{

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
		v2.push_back(100 + i);
	}
	v3 = v1;
	

	sort(v1.begin(), v1.end(),greater<int>());//加入greater<int>()  将默认升序改为降序
	for_each(v1.begin(), v1.end(), Print());
	cout << endl;

	random_device rd;    //先产生一个随机数种子
	mt19937 g(rd());     //用g是来接受随机数种子的一个随机数生成器

	shuffle(v1.begin(), v1.end(),g);
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

	vector<int>v4;
	v4.resize(v3.size() + v2.size());
	merge(v2.begin(), v2.end(), v3.begin(), v3.end(), v4.begin());         //要求两个容器必须是有序的
	for_each(v4.begin(), v4.end(), Print());
	cout << endl;

	reverse(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;


	vector<int>v5;
	v5.resize(v1.size());
	copy(v1.begin(), v1.end(), v5.begin());
	for_each(v5.begin(), v5.end(), myPrint);
	cout << endl;

	vector<int>v6;
	v6.push_back(20);
	v6.push_back(30);
	v6.push_back(40);
	v6.push_back(50);
	v6.push_back(20);
	v6.push_back(10);
	v6.push_back(20);
	v6.push_back(60);
	v6.push_back(20);

	vector<int>v7;
	v7 = v6;
	cout << "互换前" << endl;
	replace(v6.begin(), v6.end(), 20, 200);
	for_each(v6.begin(), v6.end(), myPrint);
	cout << endl;

	replace_if(v7.begin(), v7.end(), greater20(), 520);
	for_each(v7.begin(), v7.end(), myPrint);
	cout << endl;
	cout << "------------------" << endl;
	cout << "互换后" << endl;
	swap(v6, v7);
	for_each(v6.begin(), v6.end(), myPrint);
	cout << endl;
	for_each(v7.begin(), v7.end(), myPrint);
	cout << endl;
}


int main()
{
	test1();


	system("pause");
	return 0;
}