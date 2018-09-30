#include "pch.h"
#include "WorldCupManage.h"


string WorldCupManage::IntegralAndShooterStatistics()
//������������ְ�and���ְ�����ͳ��
{
	string inputTime;
	cout << "������ʱ��:";
	cin >> inputTime;
	int nFlag = 0;
	while (match[nFlag].time < inputTime) nFlag++;

	//���ְ�
	int AFlag, BFlag;
	for (int i = 0; i < nFlag; ++i)
	{
		for (int j = 0; j < teamCount; ++j)
		{
			if (team[j].nameTeam == match[i].team1)
			{
				AFlag = j;
				continue;
			}
			else if (team[j].nameTeam == match[i].team2)
			{
				BFlag = j;
				continue;
			}
		}//��һ�������ж�Ӧ�Ķ�����team�ṹ�����е�λ��

		//����ȷ�
		if (match[i].numGoal1 > match[i].numGoal2)
		{
			team[AFlag].integral += 3;
		}
		if (match[i].numGoal1 < match[i].numGoal2)
		{
			team[BFlag].integral += 3;
		}
		else if (match[i].numGoal1 == match[i].numGoal2)
		{
			team[AFlag].integral += 1;
			team[BFlag].integral += 1;
		}
	}

	//���ְ�
	int nCount = 0;
	while (goals[nCount].time < inputTime) nCount++;
	int aFlag = -1;
	for (int i = 0; i < nCount; ++i)
	{
		for (int j = 0; j < playerCount; ++j)
		{
			if (player[j].name == goals[i].name)
			{
				aFlag = j;  //��¼��Ա��player�е�λ��
				break;
			}
		}

		if (aFlag != -1) player[aFlag].numGoal++;
	}

	return inputTime;
}

void WorldCupManage::IntegralAndShooterTable(string time)
//������������ְ�And���ְ�������ʾ
{
	//����team[teamCount]
	//�������ļ��ж�����ԭʼ����

	//���ְ�
	TeamInfor teamCopy[100];
	for (int i = 0; i < teamCount; ++i)
	{
		teamCopy[i].nameTeam = team[i].nameTeam;
		teamCopy[i].integral = team[i].integral;
	}

	//ð������
	for (int i = 0; i < teamCount - 1; ++i)
	{
		for (int j = 0; j < teamCount - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);
			}
		}
	}

	//��ʾ���ְ�
	cout << "===============" << time << "֮ǰ�Ļ��ְ�===============" << endl;
	cout << "����" << "\t\t" << "����" << endl;
	for (int i = 0; i < teamCount; ++i)
	{
		cout << teamCopy[i].nameTeam << "\t\t"
			<< teamCopy[i].integral << endl;
	}

	//���ְ�
	PlayerInfor playerCopy[100];
	for (int i = 0; i < playerCount; ++i)
	{
		playerCopy[i].name = player[i].name;
		playerCopy[i].numGoal = player[i].numGoal;
	}

	//ð������
	for (int i = 0; i < playerCount - 1; ++i)
	{
		for (int j = 0; j < playerCount - i - 1; ++j)
		{
			if (playerCopy[j].numGoal < playerCopy[j + 1].numGoal) //�Ӵ�С
			{
				SwapPlayerInfor(playerCopy[j], playerCopy[j + 1]);  //������Աλ��
			}
		}
	}

	cout << "===============" << time << "֮ǰ�����ְ�" << "===============" << endl;
	cout << "��Ա" << "\t\t" << "������" << endl;
	for (int i = 0; i < playerCount; i++)
	{
		cout << playerCopy[i].name << "\t\t"
			<< playerCopy[i].numGoal << endl;
	}

	//���ֺ���Ա����������
	RecordIntegralAndShooter();
}

void WorldCupManage::SwapTeamInfor(TeamInfor & a, TeamInfor & b)
//�����������������λ��
{
	TeamInfor temp;
	temp.nameTeam = a.nameTeam;
	temp.numWin = a.numWin;
	temp.numFlat = a.numFlat;
	temp.numNegative = a.numNegative;
	temp.numGoal = a.numGoal;
	temp.integral = a.integral;

	a.nameTeam = b.nameTeam;
	a.numWin = b.numWin;
	a.numFlat = b.numFlat;
	a.numNegative = b.numNegative;
	a.numGoal = b.numGoal;
	a.integral = b.integral;

	b.nameTeam = temp.nameTeam;
	b.numWin = temp.numWin;
	b.numFlat = temp.numFlat;
	b.numNegative = temp.numNegative;
	b.numGoal = temp.numGoal;
	b.integral = temp.integral;
}

void WorldCupManage::SwapPlayerInfor(PlayerInfor &a, PlayerInfor &b)
//�������������������Ա�������е�λ��
{
	PlayerInfor temp;

	temp.name = a.name;
	temp.nameTeam = a.nameTeam;
	temp.number = a.number;
	temp.numGoal = a.numGoal;

	a.name = b.name;
	a.nameTeam = b.nameTeam;
	a.number = b.number;
	a.numGoal = b.numGoal;

	b.name = temp.name;
	b.nameTeam = temp.nameTeam;
	b.number = temp.number;
	b.numGoal = temp.numGoal;
}

void WorldCupManage::DisplayMatchInforAll()
//�����������ʾ���б�����¼
{
	cout << "����" << "\t\t" << "��������" << "\t"
		<< "ʱ��" << "\t\t" << "����" << "\t"
		<< "�ͳ�" << "\t" << "Num1" << "\t\t"
		<< "Num2" << endl;

	for (int i = 0; i < matchCount; ++i)
	{
		DisplayMatchInfor(match[i]);
	}
}

void WorldCupManage::DisplayMatchInfor(const MatchInfor & matchInfor)
//�����������ʾһ��������¼
{
	cout << matchInfor.key << "\t" << matchInfor.natureCompetition << "\t\t"
		<< matchInfor.time << "\t" << matchInfor.team1 << "\t"
		<< matchInfor.team2 << "\t" << matchInfor.numGoal1 << "\t\t"
		<< matchInfor.numGoal2 << endl;
}

void WorldCupManage::DisplayPlayerInforAll()
//�����������ʾ������Ա��Ϣ
{
	cout << "����" << "\t\t"
		<< "����" << endl;

	for (int i = 0; i < playerCount; ++i)
	{
		DisplayPlayerInfor(player[i]);
	}
}

void WorldCupManage::DisplayPlayerInfor(const PlayerInfor & playerInfor)
//�����������ʾһ����Ա��¼
{
	cout << playerInfor.name << "\t\t"
		<< playerInfor.nameTeam << endl;
}

void WorldCupManage::RecordIntegralAndShooter()
//��������������ֺ���Ա����������
{
	//��������
	for (int i = 0; i < teamCount; ++i)
	{
		team[i].integral = 0;
	}

	//��Ա����������
	for (int i = 0; i < playerCount; ++i)
	{
		player[i].numGoal = 0;
	}
}

WorldCupManage::WorldCupManage()
//�������������ԭʼ����
{
	matchCount = 0;
	teamCount = 0;
	playerCount = 0;
	goalsCount = 0;

	ifstream matchFile("matchRecord.txt", ios::in); 	//������ķ�ʽ���ļ�

	if (!matchFile)   				//�����Ƿ�ɹ���
	{
		cerr << "open matchFile error!" << endl;
		exit(1);
	}
	while (!matchFile.eof())
	{
		matchFile >> match[matchCount].key
			>> match[matchCount].natureCompetition
			>> match[matchCount].time
			>> match[matchCount].team1
			>> match[matchCount].team2
			>> match[matchCount].numGoal1
			>> match[matchCount].numGoal2;

		++matchCount;
	}
	matchFile.close();

	ifstream teamFile("teamRecord.txt", ios::in);  //������ķ�ʽ���ļ�
	if (!teamFile)   				//�����Ƿ�ɹ���
	{
		cerr << "open teamFile error!" << endl;
		exit(1);
	}
	while (!teamFile.eof())
	{
		teamFile >> team[teamCount].nameTeam;
		team[teamCount].integral = 0;

		++teamCount;
	}
	teamFile.close();

	ifstream playerFile("playerRecord.txt", ios::in); //������ķ�ʽ���ļ�
	if (!playerFile)   				//�����Ƿ�ɹ���
	{
		cerr << "open playerFile error!" << endl;
		exit(1);
	}
	while (!playerFile.eof())
	{
		playerFile >> player[playerCount].name
			>> player[playerCount].nameTeam;
		player[playerCount].numGoal = 0;  //��Ա������

		++playerCount;
	}
	playerFile.close();

	ifstream goalsFile("goalsRecord.txt", ios::in);
	if (!goalsFile)
	{
		cerr << "open goalsFile error" << endl;
		exit(1);
	}
	while (!goalsFile.eof())
	{
		goalsFile >> goals[goalsCount].time
			>> goals[goalsCount].name;
		++goalsCount;
	}
	goalsFile.close();
}

void WorldCupManage::Run()
//���������ģ���ѯϵͳ
{
	cout << "==============2018����˹���籭��������|����|���ְ�|���ְ�==============" << endl;
	int select;  //��ʱ����
	do
	{
		cout << "** 1--��ʾ��ʷ��������         **" << endl;
		cout << "** 2--��ʾ��ʷ��������         **" << endl;
		cout << "** 3--����ʱ�̣����������Ԥ�� **" << endl;
		cout << "*** 4--��ѯ���Σ���ʾ��ϸ��Ϣ   **" << endl;

		cout << "����ѡ��";  //����ѡ��
		cin >> select;  //����ѡ��
		while (getchar() != '\n');  //������ǰ�е������ַ�
		switch (select)
		{
		case 1:
			DisplayMatchInforAll();
			break;
		case 2:
			DisplayPlayerInforAll();
			break;
		case 3:
			string time = IntegralAndShooterStatistics();
			IntegralAndShooterTable(time);
			break;
			//case 4:
			//	
			//	break;
			//case 5:
			//	DisplayALL();  //��ʾ���м�¼
			//	break;
		}
	} while (select != 0);
}
