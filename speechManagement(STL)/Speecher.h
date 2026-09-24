#pragma once
#include<iostream>
using namespace std;



class Speecher
{
public:

	Speecher();

	~Speecher();

	string m_name;     //选手姓名

	double m_score[2]; //选手两轮平均分记录
};