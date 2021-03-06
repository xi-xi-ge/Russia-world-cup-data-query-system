// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H



#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
//#include <string.h>
#include <cstdlib>  //在codeblocks下，exit(1)需要这个头文件
using namespace std;

//比赛信息记录结构
struct MatchInfor
{
	char natureCompetition[10];  //比赛性质，每个汉字占两个字符
	char time[10]; //06-01-05 表示6月1号凌晨5点
	char team1[20];  //队伍1名称
	char team2[20];  //队伍2名称
	int numGoal1;  //队伍1进球数
	int numGoal2;  //队伍2进球数
	char key[10];  //场次
};

const int N = 64;  //一共64场比赛


//比赛信息管理类
class MatchInforManage
{
private:
	//比赛信息类的数据成员
	MatchInfor match[N];  //比赛信息结构体数组
	int matchCount; //从文件读入的比赛场数

public:

	//辅助函数
	void Display(const MatchInfor &matchInfor);  //显示记录

	void DisplayALL();   //显示所有比赛记录


	void Search();  //按时间查找记录

	//公有函数
	MatchInforManage();  //无参构造函数
//	virtual ~MatchInforManage(); //析构函数
	void Run();  //模拟查询系统
};


#endif //PCH_H
