#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<vector>
#include<numeric>



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
	for(int i =0;i<=100;i++)
	{
		v1.push_back(i);
	}
	int sum = accumulate(v1.begin(), v1.end(), 1000);
	cout << sum << endl;
	vector<int>v2;
	v2.resize(10);
	fill(v2.begin(), v2.end(), 100);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

	vector<int>v3, v4,vTarget;
	for(int i =0;i<10;i++)
	{
		v3.push_back(i);
		v4.push_back(i + 5);
	}
	vTarget.resize(min(v3.size(), v4.size()));
	vector<int>::iterator its = set_intersection(v3.begin(), v3.end(), v4.begin(), v4.end(), vTarget.begin());
	for_each(vTarget.begin(), its, myPrint);
	cout << endl;

	vector<int>v5, v6;
	v5.resize(v3.size() + v4.size());
	vector<int>::iterator its1 = set_union(v3.begin(), v3.end(), v4.begin(), v4.end(), v5.begin());
	for_each(v5.begin(), its1, myPrint);
	cout << endl;

	v6.resize(max(v3.size(), v4.size()));
	vector<int>::iterator its2 = set_difference(v3.begin(), v3.end(), v4.begin(), v4.end(), v6.begin());
	for_each(v6.begin(), its2, myPrint);
	cout << endl;
}


int main()
{
	test1();


	system("pause");
	return 0;
}