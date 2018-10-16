#pragma once
#include "pch.h"

//������Ϣ��¼�ṹ
struct MatchInfor  //С��������̭�����ýṹ
{
	string natureCompetition;  //�������ʣ�ÿ������ռ�����ַ�
	string time; //06-01-05 ��ʾ6��1���賿5��
	string team1;  //����1����
	string team2;  //����2����
	int numGoal1;  //����1������
	int numGoal2;  //����2������
	string key;  //����
};

//��Ա��Ϣ��¼
struct PlayerInfor
{
	string name;  //��Ա����
	string nameTeam;  //�����������
	int number;  //���
//	string time;  //����ʱ��
	int numGoal;  //������ -- ���ְ���������
};

//������Ϣ��¼
struct GoalsInfor
{
	int field;  //����
	string time;  //����ʱ��
	string name;  //����
	string nameTeam;  //�������
	string numberPlayer;  //��Ա���
	string GoalCharacteristics;  //��������
};

//������Ϣ��¼
struct FieldInfor
{
	int field;  //����
	string time;  //����ʱ��
	string team1;  //����1
	string team2;  //����2
	string scores;  //�ȷ�
};

//�����Ϣ��¼�ṹ
struct TeamInfor
{
	string nameTeam;  //�������
	int numWin;  //ʤ�ĳ���
	int numFlat;  //ƽ�ĳ���
	int numNegative;  //���ĳ���
	int numGoal;  //������
	int integral;  //���� -- ��������/���ְ�����
	string group;  //�� A~H
	int goalsDifference;  //С������ʤ��

	//new - ��̭��ֻ��Ҫ��С������õ����� -- nameTeam������������
};

//WorldCupManageSystem
class WCIM
{
public:
	
	//��̭��������Ϣ�����ݳ�Ա
	MatchInfor knockkoutMatch[16];
	int knockkoutMatchCount;

	//С����������Ϣ�����ݳ�Ա
	MatchInfor match[200];  //������Ϣ�ṹ������
	int matchCount; //���ļ�����ı�������

	//������Ϣ�����ݳ�Ա
	TeamInfor team[40];  //������Ϣ�ṹ����
	int teamCount;  //���ļ��ж���������Ŀ - ����test

	//��Ա��Ϣ�����ݳ�Ա
	PlayerInfor player[800];  //��Ա��Ϣ�ṹ����
	int playerCount;  //���ļ��ж������Ա��Ϣ����

	//������Ϣ�����ݳ�Ա
	GoalsInfor goals[600];  //������Ϣ�ṹ����
	int goalsCount;  //���ļ��ж���Ľ�����Ϣ����

	//������Ϣ�����ݳ�Ա
	FieldInfor fields[70];  //������Ϣ�ṹ����
	int fieldsCount;  //���ļ��ж���ĳ�����Ϣ����

	//��������
	void SwapTeamInfor(TeamInfor &a, TeamInfor &b);  //�������������������е�λ��
	void SwapPlayerInfor(PlayerInfor &a, PlayerInfor &b);  //����������Ա�������е�λ��

	void DisplayMatchInforAll();  //��ʾ���б�����¼matchRecord_ALL
	void DisplayMatchInfor(const MatchInfor &matchInfor);  //��ʾһ��������¼matchRecord_ONE

	void DisplayPlayerInforAll();  //��ʾ������Ա��ϢplayerRecord_ALL
	void DisplayPlayerInfor(const PlayerInfor &playerInfor);  //��ʾһ����Ա��¼playerRecord_ONE

	void FindField();  //���Ҳ�����ĳһ�����ڽṹ�����е�λ��fieldsRecord.txt
	void DisplayFieldInfor(int position);  //��ʾһ��������ϢfieldsRecord_ONE
	void DisplayFieldInforAll();  //��ʾ���г�����ϢfiledsRecord_ALL
	void DisplayGoalsInfor(int position);  //��ʾһ������������ϢgoalsRecord_ONE

	void Integral(string inputTime);  //���ְ�����ͳ�Ʋ���ʾ
	void Shooters(string inputTime);  //���ְ�����ͳ�Ʋ���ʾ
	void ClearZeroIntegral();  //���ְ�����
	void ClearZeroShooters();  //���ְ�����

	void TimeGuide();   //inputTime��������(ͨ�������ʱ�䣬���ò�ͬ�ĺ���)

	void GroupMatchSituation();  //����С�������ּ��������16ǿ�Ķ��鲢��ʾС�������ս��

	//����̭��������Ҫ���¾��ǽ�ʤ�Ķ�������ƴ��ݸ���һ�ֱ������ɣ�������������������
	void InitializeKnockoutData();  //����С�����������̭�����������Ľ�����(���ļ��ж���)����̭�������б������ȷ������!!!
	 
	WCIM();
	//	~WCIM();
	void Run();  //ģ���ѯϵͳ
};