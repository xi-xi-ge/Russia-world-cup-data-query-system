#pragma once
#include "pch.h"

//������Ϣ��¼�ṹ
struct MatchInfor
{
	string natureCompetition;  //�������ʣ�ÿ������ռ�����ַ�
	string time; //06-01-05 ��ʾ6��1���賿5��
	string team1;  //����1����
	string team2;  //����2����
	int numGoal1;  //����1������
	int numGoal2;  //����2������
	string key;  //����
};

//�����Ϣ��¼�ṹ
struct TeamInfor
{
	string nameTeam;  //�������
	int numWin;  //ʤ�ĳ���
	int numFlat;  //ƽ�ĳ���
	int numNegative;  //���ĳ���
	int numGoal;  //��ʤ��
	int integral;  //���� -- ��������/���ְ�����
	string group;  //�� A~H
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

//new - ������̭������ṹ����
//��̭��������Ϣ��¼
struct KnockoutTeamInfor
{
	string time;  //ʱ�䣬���ļ��ж���
	string nameTeam;  //���飬����С���������ȡ
	//new - ������̭��������Ϣ
	int numGoals_16;  //16ǿʱ������
	int numGoals_8;  //8ǿʱ������
	int numGoals_4;  //4ǿ������
	int numGoals_2;  //3��4��������
	int numGoals_1;  //����������
	bool four;  //�Ƿ��ǵ�4��
	bool three;  //�Ƿ��ǵ�3��
	bool two;  //�Ƿ��ǵ�2��
	bool one;  //�Ƿ��ǵ�1��
};

//WorldCupManageSystem
class WCIM
{
public:
	//������Ϣ�����ݳ�Ա
	MatchInfor match[200];  //������Ϣ�ṹ������
	int matchCount; //���ļ�����ı�������

	//������Ϣ�����ݳ�Ա
	TeamInfor team[40];  //������Ϣ�ṹ����
	int teamCount;  //���ļ��ж���������Ŀ - ����test

	//��Ա��Ϣ�����ݳ�Ա
	PlayerInfor player[500];  //��Ա��Ϣ�ṹ����
	int playerCount;  //���ļ��ж������Ա��Ϣ����

	//������Ϣ�����ݳ�Ա
	GoalsInfor goals[100];  //������Ϣ�ṹ����
	int goalsCount;  //���ļ��ж���Ľ�����Ϣ����

	//������Ϣ�����ݳ�Ա
	FieldInfor fields[70];  //������Ϣ�ṹ����
	int fieldsCount;  //���ļ��ж���ĳ�����Ϣ����

	////new - ��̭��
	////��̭����Ϣ�����ݳ�Ա
	//KnockoutTeamInfor knockoutTeam[16];

	//��������
	string  IntegralAndShooterStatistics();  //���ְ�����ְ�����ͳ��

	void IntegralAndShooterTable(string time);  //���ְ�����ְ��������

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

	void ClearZeroISWFN();  //���֡�ʤ��ƽ��������Ա����������

	//new - С��������ʱ��������ֶ���
	void Strong16();  //����С�����������16ǿ

	WCIM();
	//	~WCIM();
	void Run();  //ģ���ѯϵͳ
};