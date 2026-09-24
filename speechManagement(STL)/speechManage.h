#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"Speecher.h"
#include<random>
#include<deque>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<cstdlib>   //exit(0)需要的头文件

class SpeechManage
{
public:

	SpeechManage();


	~SpeechManage();

	//显示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//初始化演讲人员
	void initialSpeech();

	//创建选手
	void setSpeecher();

	//抽签
	void speechDraw();

	//开始演讲
	void startSpeech();

	//晋级结果
	void vectorySpeech();

	//保存分数
	void saveRecord();

	//加载往届记录
	void loadRecord();

	//查看往届记录
	void showRecord();

	//清空往届记录
	void clearRecord();



	vector<int> v1;   //第一轮人员的编号
	vector<int> v2;   //第二轮人员的编号
	vector<int> v_vectory;  //前三名人员的编号
	map<int, Speecher>m_s;  //存放每位选手的信息
	int index;             //表示进行第几轮比赛

	map<int, vector<string>>m_history;  //记录往届比赛获奖名单    int记录第几届，vector记录姓名和分数
	bool fileIsEmpty;     //检测文件是否为空

};