#pragma once

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
	string time;
	string name;
};

class WorldCupManage
{
public:
	//������Ϣ������ݳ�Ա
	MatchInfor match[70];  //������Ϣ�ṹ������
	int matchCount; //���ļ�����ı�������

	//������Ϣ������ݳ�Ա
	TeamInfor team[40];  //������Ϣ�ṹ����
	int teamCount;  //���ļ��ж���������Ŀ - ����test

	//��Ա��Ϣ������ݳ�Ա
	PlayerInfor player[500];  //��Ա��Ϣ�ṹ����
	int playerCount;  //���ļ��ж������Ա��Ϣ����

	//������Ϣ������ݳ�Ա
	GoalsInfor goals[100];  //������Ϣ�ṹ����
	int goalsCount;  //���ļ��ж���Ľ�����Ϣ����

	//��������
	string  IntegralAndShooterStatistics();  //���ְ�����ְ�����ͳ��
	void IntegralAndShooterTable(string time);  //���ְ�����ְ��������
	void SwapTeamInfor(TeamInfor &a, TeamInfor &b);  //�������������������е�λ��

	void SwapPlayerInfor(PlayerInfor &a, PlayerInfor &b);  //����������Ա�������е�λ��

	void DisplayMatchInforAll();  //��ʾ���б�����¼
	void DisplayMatchInfor(const MatchInfor &matchInfor);  //��ʾһ��������¼

	void DisplayPlayerInforAll();  //��ʾ������Ա��Ϣ
	void DisplayPlayerInfor(const PlayerInfor &playerInfor);  //��ʾһ����Ա��¼

	void RecordIntegralAndShooter();

	WorldCupManage();
	//	~WorldCupManage();
	void Run();  //ģ���ѯϵͳ
};