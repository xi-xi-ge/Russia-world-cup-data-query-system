#pragma once
#include "pch.h"

//比赛信息记录结构
struct MatchInfor  //小组赛和淘汰赛共用结构
{
	string natureCompetition;  //比赛性质，每个汉字占两个字符
	string time; //06-01-05 表示6月1号凌晨5点
	string team1;  //队伍1名称
	string team2;  //队伍2名称
	int numGoal1;  //队伍1进球数
	int numGoal2;  //队伍2进球数
	string key;  //场次
};

//球员信息记录
struct PlayerInfor
{
	string name;  //球员姓名
	string nameTeam;  //所属球队名称
	int number;  //编号
//	string time;  //进球时间
	int numGoal;  //进球数 -- 射手榜排序依据
};

//进球信息记录
struct GoalsInfor
{
	int field;  //场次
	string time;  //进球时间
	string name;  //姓名
	string nameTeam;  //所属球队
	string numberPlayer;  //球员编号
	string GoalCharacteristics;  //进球特征
};

//场次信息记录
struct FieldInfor
{
	int field;  //场次
	string time;  //比赛时间
	string team1;  //国家1
	string team2;  //国家2
	string scores;  //比分
};

//球队信息记录结构
struct TeamInfor
{
	string nameTeam;  //球队名称
	int numWin;  //胜的场数
	int numFlat;  //平的场数
	int numNegative;  //负的场数
	int numGoal;  //进球数
	int integral;  //积分 -- 晋级依据/积分榜依据
	string group;  //组 A~H
	int goalsDifference;  //小组赛净胜球

	//new - 淘汰赛只需要从小组赛获得的属性 -- nameTeam！！！！！！
};

//WorldCupManageSystem
class WCIM
{
public:
	
	//淘汰赛比赛信息的数据成员
	MatchInfor knockkoutMatch[16];
	int knockkoutMatchCount;

	//小组赛比赛信息的数据成员
	MatchInfor match[200];  //比赛信息结构体数组
	int matchCount; //从文件读入的比赛场数

	//队伍信息的数据成员
	TeamInfor team[40];  //队伍信息结构数组
	int teamCount;  //从文件中读入的球队数目 - 方便test

	//球员信息的数据成员
	PlayerInfor player[800];  //球员信息结构数组
	int playerCount;  //从文件中读入的球员信息条数

	//进球信息的数据成员
	GoalsInfor goals[600];  //进球信息结构数组
	int goalsCount;  //从文件中读入的进球信息条数

	//场次信息的数据成员
	FieldInfor fields[70];  //场次信息结构数组
	int fieldsCount;  //从文件中读入的场次信息条数

	//辅助函数
	void SwapTeamInfor(TeamInfor &a, TeamInfor &b);  //交换两个队伍在数组中的位置
	void SwapPlayerInfor(PlayerInfor &a, PlayerInfor &b);  //交换两个球员在数组中的位置

	void DisplayMatchInforAll();  //显示所有比赛记录matchRecord_ALL
	void DisplayMatchInfor(const MatchInfor &matchInfor);  //显示一条比赛记录matchRecord_ONE

	void DisplayPlayerInforAll();  //显示所有球员信息playerRecord_ALL
	void DisplayPlayerInfor(const PlayerInfor &playerInfor);  //显示一条球员记录playerRecord_ONE

	void FindField();  //查找并返回某一场次在结构数组中的位置fieldsRecord.txt
	void DisplayFieldInfor(int position);  //显示一条场次信息fieldsRecord_ONE
	void DisplayFieldInforAll();  //显示所有场次信息filedsRecord_ALL
	void DisplayGoalsInfor(int position);  //显示一场比赛进球信息goalsRecord_ONE

	void Integral(string inputTime);  //积分榜数据统计并显示
	void Shooters(string inputTime);  //射手榜数据统计并显示
	void ClearZeroIntegral();  //积分榜清零
	void ClearZeroShooters();  //射手榜清零

	void TimeGuide();   //inputTime导流函数(通过输入的时间，调用不同的函数)

	void GroupMatchSituation();  //根据小组赛积分计算出晋级16强的队伍并显示小组赛最终结果

	//在淘汰赛中最重要的事就是将胜的队伍的名称传递给下一轮比赛即可！！！！！！！！！！
	void InitializeKnockoutData();  //根据小组赛结果和淘汰赛各场比赛的进球数(从文件中读入)将淘汰赛的所有比赛结果确定下来!!!
	 
	WCIM();
	//	~WCIM();
	void Run();  //模拟查询系统
};