#include<iostream>
using namespace std;
#include<string>


template<typename T>
void Mysort(T arr[],int num)
{
	for(int i= 0;i<num-1;i++)
	{
		int min = i;
		for(int j=i+1;j<num;j++)
		{
			if(arr[min]>arr[j])
			{
				min = j;
			}
		}
		if(i != min)
		{
			T temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
	for(int i = 0; i<num ; i++)
	{
		cout << arr[i] ;
	}
}


void test01()
{
	char arr[] = "vsaqdfv";
	int num = sizeof(arr) / sizeof(char);
	Mysort(arr, num);
}


int main()
{
	
	test01();
	//test02();
	return 0;
}