#include"speechManage.h"




SpeechManage::SpeechManage()
{
	index = 1;
	fileIsEmpty = true;
	
}


SpeechManage::~SpeechManage()
{

}

//显示菜单
void SpeechManage::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎参加演讲比赛  *********" << endl;
	cout << "*********  1.开始演讲比赛  *********" << endl;
	cout << "*********  2.查看往届记录  *********" << endl;
	cout << "*********  3.清空比赛记录  *********" << endl;
	cout << "*********  0.退出比赛程序  *********" << endl;
	cout << "********************************************" << endl;
	cout << endl;

}


//退出系统
void SpeechManage::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);         //结束程序
}

//初始化演讲人员
void SpeechManage::initialSpeech()
{
	v1.clear();
	v2.clear();
	v_vectory.clear();
	m_s.clear();

	index = 1;

	fileIsEmpty = true;

	////初始化记录容器
	//m_history.clear();

	////测试第一轮选手上场顺序
	//for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
	//{
	//	cout << "选手编号：" << *it << "  " << "选手姓名：" << m_s[*it].m_name << "  平均分：" << m_s[*it].m_score[0] << endl;
	//}
	//cout << endl;
}

//创建选手
void SpeechManage::setSpeecher()
{
	Speecher speecher;
	string nameSeed = "ABCDEFGHIJKL";
	string name = "选手";
	int numid;

	for (int i = 0;i < 12;i++)
	{

		speecher.m_name = name + nameSeed[i];
		speecher.m_score[0] = 0;
		speecher.m_score[1] = 0;

		numid = i + 10001;
		v1.push_back(numid);

		m_s.insert(make_pair(numid, speecher));
	}
}

//开始抽签
void SpeechManage::speechDraw()
{
	cout << "第<<" << this->index << ">>轮选手正在抽签" << endl;
	cout<<"----------------------------------" << endl;
	cout << "抽签结果如下" << endl;


	if(index==1)
	{
		random_device rd;        //将选手上场顺序打乱
		mt19937 g(rd());
		shuffle(v1.begin(), v1.end(), g);
		for(vector<int>::iterator it = v1.begin();it!=v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_device rd;        //将选手上场顺序打乱
		mt19937 g(rd());
		shuffle(v2.begin(), v2.end(), g);
		for (vector<int>::iterator it = v2.begin();it != v2.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}


}

//开始演讲
void SpeechManage::startSpeech()
{
	multimap<double, int, greater<double>> groupScore;  //存晋级人员分数和编号，且让分数降序排列
	int num = 0;
	vector<int> v_src;
	//if(index==1)
	//{
	//	v_src = v1;
	//}
	//else
	//{
	//	v_src = v2;
	//}
	v_src = (index == 1) ? v1 : v2;                   //是上述代码的缩写版本

	cout << "----------------------------------" << endl;
	cout << "第" << this->index << "轮比赛正式开始" << endl;
	cout << "----------------------------------" << endl;
	for(vector<int>::iterator it = v_src.begin();it!=v_src.end();it++)    //遍历每位选手
	{

		num++;//进行六个人一组的分组指标
		

		deque<double>d;
		for(int i=0;i<10;i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();//去掉一个最高分
		d.pop_back();//去掉一个最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->m_s[*it].m_score[index-1] = avg;

		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛结果名次" << endl;

			for (multimap<double, int, greater<double>>::iterator it1 = groupScore.begin();it1 != groupScore.end();it1++)
			{
				cout << "编号：" << it1->second << "  得分：" << it1->first << endl;

			}
			//取前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it1 = groupScore.begin();it1 != groupScore.end() && count < 3;it1++, count++)
			{
				if (index == 1)
				{
					v2.push_back(it1->second);
				}
				else
				{
					v_vectory.push_back(it1->second);
				}
			}
			groupScore.clear();
		}
		
	}
	system("pause");
}

//每一轮晋级选手
void SpeechManage::vectorySpeech()
{
	vector<int>v;
	if(index==1)
	{
		v = v2;
	}
	else
	{
		v = v_vectory;
	}
	cout << "-------------------------" << endl;
	cout << "---------第" << index << "轮晋级结果如下---------" << endl;

	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "编号：" << *it << "  姓名：" << m_s[*it].m_name << "  分数：" << m_s[*it].m_score[index-1] << endl;
	}
	cout << "---------第" << index << "轮比赛已结束---------" << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

//保存分数
void SpeechManage::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for(vector<int>::iterator it = v_vectory.begin();it!=v_vectory.end();it++)
	{
		ofs << *it << "," << m_s[*it].m_score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	this->fileIsEmpty = false;

	cout << "文件已保存" << endl;
	system("pause");
	system("cls");
}

//查看往届记录
void SpeechManage::loadRecord()
{
	//if(this->fileIsEmpty)
	//{
	//	cout << "文件不存在或者记录为空" << endl;
	//}
	vector<string>v;
	int index = 1;          //表示第几届的名单
	ifstream ifs;
	ifs.open("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		//说明文件不存在
		cout << "该文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//说明文件为空
		cout << "该文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);          //将上面的读取单个字符  放回来

	string date;
	while (ifs >> date)         //跳过前面的空白，然后一直读取，直到再次遇到空白。  空白包括" "（空格）,"\n"（换行），"\t"（Tab）
	{
		v.clear();     //读取每一行数据之前，先清空之前的数据
		//cout << date << endl;
		//10008,84.5,10005,82.125,10009,81.4625,
		int pos = -1;  //pos去接收","的位置
		int start = 0;

		//while (true)
		//{
		//	pos = date.find(",", start);

		//	if (pos == -1)
		//	{
		//		//没有找到","
		//		break;
		//	}
		//	string temp = date.substr(start, pos - start);
		//	start = pos + 1;
		//	v.push_back(temp);
		//}
		while (true)             //修改过后
		{
			pos = date.find(",", start);

			if (pos == string::npos)
			{
				string temp = date.substr(start);

				if (!temp.empty())
				{
					v.push_back(temp);
				}

				break;
			}


			string temp = date.substr(start, pos - start);

			v.push_back(temp);

			start = pos + 1;
		}
		m_history.insert(make_pair(index++, v));

	}
	ifs.close();
	
}

void SpeechManage::showRecord()
{
	for (map<int, vector<string>>::iterator it = m_history.begin();it != m_history.end();it++)

	{
		if (it->second.size() >= 6)
		{
			cout << "第" << it->first << "届" << "  冠军编号：" << it->second[0] << "  分数：" << it->second[1] << endl;
			cout << "第" << it->first << "届" << "  亚军编号：" << it->second[2] << "  分数：" << it->second[3] << endl;
			cout << "第" << it->first << "届" << "  季军编号：" << it->second[4] << "  分数：" << it->second[5] << endl;
		}

	}
	system("pause");
	system("cls");
}

//清空往届记录
void SpeechManage::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if(select==1)
	{
		ofstream ofs("speech.csv", ios::trunc);

		ofs.close();
		cout << "已成功清空记录" << endl;

		this->initialSpeech();

		this->setSpeecher();

		this->loadRecord();
		//初始化记录容器
		m_history.clear();
		
	}
	system("pause");
	system("cls");
	
}