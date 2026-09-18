//自己的通用数组类
#pragma once
#include<iostream>
using namespace std;
#include<string>

template<class T>
class MyArray
{
public:

	//有参构造  参数   容量
	MyArray(int Capacity)
	{
		cout << "MyArray  的 有参构造调用" << endl;

		this->m_Capacity = Capacity;
		this->m_Size = 0;
		this->pAddress = new T[m_Capacity];
	}

	//析构函数
	~MyArray()
	{
		cout << "MyArray  的 析构调用" << endl;

		delete[] this->pAddress;
		this->m_Size = 0;
		this->pAddress = NULL;
	}

	//拷贝构造
	MyArray(const MyArray &arr)
	{
		cout << "MyArray  的 拷贝构造调用" << endl;

		this->m_Capacity = arr.m_Capacity ;
		this->m_Size = arr.m_Size ;
		//this->pAddress = arr.pAddress;如果不进行深拷贝，编译器会自动帮我们写这三行代码
		
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		// 在堆区开辟一块新的数组空间，然后逐个复制 arr 中的数据
		

		for(int i= 0; i<arr.m_Size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 防止浅拷贝
	MyArray& operator= (const MyArray &arr)
	{
		cout << "MyArray  的 operator=调用" << endl;

		//先判断原来堆区是否有数据，如果有，先释放
		if(this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
			
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < arr.m_Size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T & val)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size) 
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back()
	{
		if(this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组元素   对于arr[index]想让它作为一个左值存在，还需要返回引用&
	T& operator[] (int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int Get_Capacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int Get_Size()
	{
		return this->m_Size;
	}

private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Size;
	int m_Capacity;
};