#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

class compare
{
public:
	bool operator()(int val1,int val2)
	{
		return val1 > val2;
	}
};

void test1()
{
	
	vector<int> v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	sort(v.begin(), v.end(), compare());

	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{


	test1();
	

	system("pause");
	return 0;
}