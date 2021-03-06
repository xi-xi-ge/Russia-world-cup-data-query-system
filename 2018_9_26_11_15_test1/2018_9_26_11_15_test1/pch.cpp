// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
#include "pch.h"

//MatchInforManage类相关成员函数的实现

void MatchInforManage::Search()
//操作结果：查找记录
{
	char inputTime[10];
	cout << "输入时间:";
	cin >> inputTime;
	while (getchar() != '\n');  //跳过当前行的其他字符

	int flag1 = -1, flag2 = -1, flag3 = -1;
	//最多每天有4场比赛，要找出时间相同的不同场次，最多重复4次二分查找
	//查找并显示当天的比赛信息
	//NO.1
	int left = 0, right = matchCount-1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (strcmp(inputTime,match[mid].time) == 0 )
		{
			Display(match[mid]);
			flag1 = mid;
			break;
		}
		else if (strcmp(inputTime,match[mid].time) <0) right = mid-1;
		else left = mid + 1;
	}

	//NO.2
	left = 0, right = matchCount-1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (strcmp(inputTime, match[mid].time) == 0 && mid != flag1)
		{
			Display(match[mid]);
			flag2 = mid;
			break;
		}
		else if (strcmp(inputTime, match[mid].time) < 0) right = mid-1;
		else left = mid + 1;
	}

	//NO.3
	left = 0, right = matchCount-1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (strcmp(inputTime, match[mid].time) == 0 && mid != flag1 && mid != flag2)
		{
			Display(match[mid]);
			flag3 = mid;
			break;
		}
		else if (strcmp(inputTime, match[mid].time) < 0) right = mid-1;
		else left = mid + 1;
	}

	//NO.4
	left = 0, right = matchCount - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (strcmp(inputTime, match[mid].time) == 0 && mid != flag1 && mid != flag2 && mid !=flag3 )
		{
			Display(match[mid]);
			break;
		}
		else if (strcmp(inputTime, match[mid].time) < 0) right = mid - 1;
		else left = mid + 1;
	}

	//显示之前的的信息
	cout << inputTime << "Before:" << endl;
	int pos = -1;  //当前比赛在match[N]中的位置
	left = 0, right = matchCount - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (strcmp(inputTime, match[mid].time) == 0)
		{
			Display(match[mid]);
			pos = mid;
			break;
		}
		else if (strcmp(inputTime, match[mid].time) < 0) right = mid - 1;
		else left = mid + 1;
	}

	if (pos != -1)
	{
		//将时间在inputTime之前的比赛情况全部输出
		for (int i = 0; i < pos; i++) 
		{
			Display(match[i]);
		}
	}
	else
	{
		return;
	}

	return;

}

void MatchInforManage::Display(const MatchInfor &matchInfor)
//操作结果：显示指定记录
{

	cout << matchInfor.key << "\t" << matchInfor.natureCompetition << "\t\t" 
		<< matchInfor.time << "\t" << matchInfor.team1 << "\t" 
		<< matchInfor.team2 << "\t" << matchInfor.numGoal1 << "\t\t" 
		<<  matchInfor.numGoal2 << endl;
}

void MatchInforManage::DisplayALL()
//操作结果：显示所有记录
{
	cout << "场次" << "\t\t" << "比赛性质" << "\t" 
		<< "时间" << "\t\t"<< "主场" << "\t" 
		<< "客场" << "\t" << "Num1" << "\t\t"
		<< "Num2" << endl;

	for (int i = 0; i < matchCount; ++i)
	{
		Display(match[i]);
	}
}

MatchInforManage::MatchInforManage()
//操作结果：构造索引表及初始化相关信息
//将文件中的内容放到结构数组match[N]中，便于操作
{
	matchCount = 0;
	//下面从文件中读取数据到结构体数组
	ifstream infile("F:\\VS2017\\2018_9_26_11_15_test1\\2018_9_26_11_15_test1\\matchRecord.txt", ios::in); 	//以输入的方式打开文件

	if (!infile)   				//测试是否成功打开
	{
		cerr << "open error!" << endl;
		exit(1);
	}

	int i = 0;

	while (!infile.eof())
	{
		infile >> match[i].key >> match[i].natureCompetition 
			   >> match[i].time >> match[i].team1 
			   >> match[i].team2 >> match[i].numGoal1 
			   >> match[i].numGoal2;

		++matchCount;

		++i;
	}

	infile.close();
}