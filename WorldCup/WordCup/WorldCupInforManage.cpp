#include "pch.h"
#include "WorldCupInforManage.h"

//�����������λ����
void WCIM::FindField()
{
	int inputField;  //�û�����ĳ���
	cout << "�����볡��:";
FIND:
	cin >> inputField;
	int fieldsIndex = -1;  //match[]�ṹ�����е��±�
	int goalsEndIndex = -1;  //goals[]�ṹ�����е��±�

	//���ֲ��� - ���νṹ����fields[]
	int left = 0, right = fieldsCount - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (inputField == fields[mid].field)
		{
			fieldsIndex = mid;
			break;
		}
		else if (inputField < fields[mid].field) right = mid - 1;
		else left = mid + 1;
	}

	if (fieldsIndex == -1)
	{
		cout << "�����ڵ�" << inputField << "����" << endl;
		cout << "����������:";

		goto FIND;
	}
	else
	{
		DisplayFieldInfor(fieldsIndex);  //����ҵ��ĳ�����Ϣ
	}

	//����inputField��Ӧ�Ľ�����Ϣ
	int begin = -1, end = -1;
	//begin
	for (int i = 0; i < goalsCount; ++i)
	{
		if (inputField == goals[i].field)
		{
			begin = i;
			break;
		}
	}
	//end
	for (int i = begin; i < goalsCount; ++i)
	{
		if (inputField != goals[i].field)
		{
			end = i - 1;
			break;
		}
	}

	for (int i = begin; i <= end; ++i)
	{
		DisplayGoalsInfor(i);
	}

}

//�����������ʾһ��������Ϣ
void WCIM::DisplayFieldInfor(int position)
{
	cout << "����" << "\t" << "����ʱ��" << "\t" << "����" << "\t" << "����" << "\t" << "�ȷ�" << endl;
	int i = position;
	cout << fields[i].field << "\t"
		<< fields[i].time << "\t"
		<< fields[i].team1 << "\t"
		<< fields[i].team2 << "\t"
		<< fields[i].scores << endl;
}

//��ʾ���г�����Ϣ
void WCIM::DisplayFieldInforAll()
{
	for (int i = 0; i < fieldsCount; ++i)  //??? i<fieldsCount-1 != i<fieldsCount
	{
		DisplayFieldInfor(i);
	}
}

//��ʾһ�������еĽ�����Ϣ
void WCIM::DisplayGoalsInfor(int position)
{
	int i = position;
	cout << "����ʱ��" << "\t"
		<< "����" << "\t"
		<< "����" << "\t"
		<< "��Ա���" << "\t"
		<< "��������" << "\t" << endl;

	cout << goals[i].time << "\t"
		<< goals[i].name << "\t"
		<< goals[i].nameTeam << "\t"
		<< goals[i].numberPlayer << "\t"
		<< goals[i].GoalCharacteristics << endl;
}

//������������ְ�and���ְ�����ͳ��
string WCIM::IntegralAndShooterStatistics()
//������������ְ�and���ְ�����ͳ��
{
	string inputTime;
	cout << "������ʱ��:";
	cin >> inputTime;


	//���ְ�
	int nFlag = 0;
	//����ʱ��ڵ���inputTime֮ǰ�ı�����¼��Ŀ(����inputTime)
	for (int i = 0; i < matchCount; ++i)
	{
		if (inputTime >= match[i].time)
		{
			nFlag++;
		}
		else
		{
			break;
		}
	}
	int AFlag = -1, BFlag = -1;  //����1��team�е�λ�ã�����2��team�е�λ��
	//��һ��������¼matchRecordƥ�����team�����û��ּ���Ĺ���
	for (int i = 0; i < nFlag; ++i)
	{
		/*for (int j = 0; j < teamCount; ++j)
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
		}*/

		//new - ��һ��������¼����team1��team2
		for (int j = 0; j < teamCount; ++j)
		{
			if (team[j].nameTeam == match[i].team1)
			{
				AFlag = j;
				break;
			}
		}

		for (int j = 0; j < teamCount; ++j)
		{
			if (team[j].nameTeam == match[i].team2)
			{
				BFlag = j;
				break;
			}
		}

		//�����ж���ʤƽ���ж�
		if (i % 2 == 0)  //ż��¼�����������ջ���
		{
			if (match[i].numGoal1 > match[i].numGoal2)
			{
				team[AFlag].integral += 3;
				team[AFlag].numWin++;
				team[BFlag].numNegative++;
			}
			else if (match[i].numGoal1 < match[i].numGoal2)
			{
				team[BFlag].integral += 3;
				team[BFlag].numWin++;
				team[AFlag].numNegative++;
			}
			else //match[i].numGoal1 == match[i].numGoal2
			{
				team[AFlag].integral += 1;
				team[BFlag].integral += 1;
				team[AFlag].numFlat++;
				team[BFlag].numFlat++;
			}
		}
		else //i%2!=0, ���¼���������ջ���
		{
			if (match[i].numGoal1 > match[i].numGoal2)
			{
				if (match[i - 1].numGoal1 > match[i - 1].numGoal2)
				{
					//Do Nothing
				}
				else if (match[i - 1].numGoal1 < match[i - 1].numGoal2)
				{
					team[AFlag].integral += 3;
					team[BFlag].integral -= 3;
					team[AFlag].numNegative--;
					team[AFlag].numWin++;
					team[BFlag].numNegative++;
					team[BFlag].numWin--;
				}
				else //match[i-1].numGoal1 == match[i-1].numGoal2
				{
					team[AFlag].integral += 2;
					team[BFlag].integral -= 1;
					team[AFlag].numFlat--;
					team[BFlag].numFlat--;
					team[AFlag].numWin++;
					team[BFlag].numNegative++;
				}
			}
			else if (match[i].numGoal1 < match[i].numGoal2)
			{
				if (match[i - 1].numGoal1 > match[i - 1].numGoal2)
				{
					team[AFlag].integral -= 3;
					team[BFlag].integral += 3;
					team[BFlag].numNegative--;
					team[BFlag].numWin++;
					team[AFlag].numWin--;
					team[AFlag].numNegative++;
				}
				else if (match[i - 1].numGoal1 < match[i - 1].numGoal2)
				{
					//Do Nothing
				}
				else
				{
					team[AFlag].integral -= 1;
					team[BFlag].integral += 2;
					team[AFlag].numFlat--;
					team[BFlag].numFlat--;
					team[BFlag].numWin++;
					team[AFlag].numNegative++;
				}
			}
			else  //match[i].numGoal1 == match[i].numGoal2
			{
				if (match[i - 1].numGoal1 > match[i - 1].numGoal2)
				{
					team[AFlag].integral = team[AFlag].integral - 3 + 1;
					team[BFlag].integral += 1;
					team[AFlag].numWin--;
					team[BFlag].numNegative--;
					team[AFlag].numFlat++;
					team[BFlag].numFlat++;
				}
				else if (match[i - 1].numGoal1 < match[i - 1].numGoal2)
				{
					team[BFlag].integral = team[BFlag].integral - 3 + 1;
					team[AFlag].integral += 1;
					team[BFlag].numWin--;
					team[AFlag].numNegative--;
					team[BFlag].numFlat++;
					team[AFlag].numFlat++;
				}
				else //match[i - 1].numGoal1 == match[i - 1].numGoal2
				{
					//Do Nothing
				}
			}
		}
	}

	//���ְ�
	int nCount = 0;
	//����ʱ��ڵ�������ʱ��֮ǰ(��������ʱ��)�����н����¼����
	for (int i = 0; i < goalsCount; ++i)
	{
		if (inputTime >= goals[i].time)
		{
			nCount++;
		}
		else
		{
			break;
		}
	}
	int aFlag = -1;
	//��ʱ��ڵ���inputTime֮ǰ�Ľ����¼����Ӧ��player[]ƥ�䣬���ý�������¼����
	for (int i = 0; i < nCount; ++i)
	{
		int j;
		for (j = 0; j < playerCount; ++j)
		{
			if (player[j].name == goals[i].name)
			{
				aFlag = j;  //��¼��Ա��player�е�λ��
				break;
			}
		}

		if (aFlag != -1 && j != playerCount) player[aFlag].numGoal++;
	}


	return inputTime;
}

//������������ְ�And���ְ�������ʾ
void WCIM::IntegralAndShooterTable(string time)
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
		teamCopy[i].group = team[i].group;
		teamCopy[i].numWin = team[i].numWin;
		teamCopy[i].numFlat = team[i].numFlat;
		teamCopy[i].numNegative = team[i].numNegative;
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
	cout << "===============" << time << "�Ļ��ְ�===============" << endl;
	cout << "���" << "\t" << "����" << "\t\t" << "����" << "\t" << "ʤ" << "\t" << "ƽ" << "\t" << "��" << endl;
	for (int i = 0; i < teamCount; ++i)
	{
		cout << teamCopy[i].group << "\t"
			<< teamCopy[i].nameTeam << "\t\t"
			<< teamCopy[i].integral << "\t"
			<< teamCopy[i].numWin << "\t"
			<< teamCopy[i].numFlat << "\t"
			<< teamCopy[i].numNegative << endl;
	}

	//���ְ�
	//ð������
	for (int i = 0; i < playerCount - 1; ++i)
	{
		for (int j = 0; j < playerCount - i - 1; ++j)
		{
			if (player[j].numGoal < player[j + 1].numGoal) //�Ӵ�С
			{
				SwapPlayerInfor(player[j], player[j + 1]);  //������Աλ��
			}
		}
	}
	//������ְ�,����������Ϊ0��������Ϣ���
	cout << "===============" << time << "�����ְ�" << "===============" << endl;
	cout << "��Ա" << "\t\t" << "������" << "\t" << "���" << "\t" << "����" << endl;
	for (int i = 0; i < playerCount; i++)
	{
		if (player[i].numGoal != 0)
		{
			cout << player[i].name << "\t\t"
				<< player[i].numGoal << "\t"
				<< player[i].number << "\t"
				<< player[i].nameTeam << endl;
		}
		else
		{
			break;
		}
	}

	//���֡�ʤ��ƽ��������Ա����������
	ClearZeroISWFN();
}

//�����������������λ��
void WCIM::SwapTeamInfor(TeamInfor & a, TeamInfor & b)
//�����������������λ��
{
	TeamInfor temp;
	temp.group = a.group;
	temp.nameTeam = a.nameTeam;
	temp.numWin = a.numWin;
	temp.numFlat = a.numFlat;
	temp.numNegative = a.numNegative;
	temp.numGoal = a.numGoal;
	temp.integral = a.integral;

	a.group = b.group;
	a.nameTeam = b.nameTeam;
	a.numWin = b.numWin;
	a.numFlat = b.numFlat;
	a.numNegative = b.numNegative;
	a.numGoal = b.numGoal;
	a.integral = b.integral;

	b.group = temp.group;
	b.nameTeam = temp.nameTeam;
	b.numWin = temp.numWin;
	b.numFlat = temp.numFlat;
	b.numNegative = temp.numNegative;
	b.numGoal = temp.numGoal;
	b.integral = temp.integral;
}

//�������������������Ա�������е�λ��
void WCIM::SwapPlayerInfor(PlayerInfor &a, PlayerInfor &b)
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

//�����������ʾ���б�����¼
void WCIM::DisplayMatchInforAll()
//�����������ʾ���б�����¼
{
	cout << "��������" << "\t"
		<< "ʱ��" << "\t\t" << "����" << "\t"
		<< "�ͳ�" << "\t" << "Num1" << "\t\t"
		<< "Num2" << endl;

	for (int i = 0; i < matchCount; ++i)
	{
		DisplayMatchInfor(match[i]);
	}
}

//�����������ʾһ��������¼
void WCIM::DisplayMatchInfor(const MatchInfor & matchInfor)
//�����������ʾһ��������¼
{
	cout << matchInfor.natureCompetition << "\t\t"
		<< matchInfor.time << "\t" << matchInfor.team1 << "\t"
		<< matchInfor.team2 << "\t" << matchInfor.numGoal1 << "\t\t"
		<< matchInfor.numGoal2 << endl;
}

//�����������ʾ������Ա��Ϣ
void WCIM::DisplayPlayerInforAll()
//�����������ʾ������Ա��Ϣ
{
	cout << "����" << "\t\t"
		<< "����" << endl;

	for (int i = 0; i < playerCount; ++i)
	{
		DisplayPlayerInfor(player[i]);
	}
}

//�����������ʾһ����Ա��¼
void WCIM::DisplayPlayerInfor(const PlayerInfor & playerInfor)
//�����������ʾһ����Ա��¼
{
	cout << playerInfor.name << "\t\t"
		<< playerInfor.nameTeam << endl;
}

//������������֡�ʤ��ƽ��������Ա����������
void WCIM::ClearZeroISWFN()
//��������������ֺ���Ա����������
{
	//���֡�ʤ��ƽ��������
	for (int i = 0; i < teamCount; ++i)
	{
		team[i].integral = 0;
		team[i].numWin = 0;
		team[i].numFlat = 0;
		team[i].numNegative = 0;
	}

	//��Ա����������
	for (int i = 0; i < playerCount; ++i)
	{
		player[i].numGoal = 0;
	}
}

//�������������С�����������16ǿ
void WCIM::Strong16()
{
	//��С������
	//���ṹ����ֶΣ�һ��8��С��
	//0~3,4~7, 8~11, 12~15, 16~19, 20~23, 24~27, 28~31
	TeamInfor teamCopy[100];
	for (int i = 0; i < teamCount; ++i)
	{
		teamCopy[i].nameTeam = team[i].nameTeam;
		teamCopy[i].integral = team[i].integral;
		teamCopy[i].group = team[i].group;
		teamCopy[i].numWin = team[i].numWin;
		teamCopy[i].numFlat = team[i].numFlat;
		teamCopy[i].numNegative = team[i].numNegative;
	}

	//A�飬�±귶Χ0~3
	for (int i = 0; i < 4 - 1; ++i)
	{
		for (int j = 0; j < 4 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	//B�飬�±귶Χ4~7
	for (int i = 4; i < 8 - 1; ++i)
	{
		for (int j = 4; j < 8 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	//C�飬�±귶Χ8~11
	for (int i = 8; i < 12 - 1; ++i)
	{
		for (int j = 8; j < 12 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	//D�飬�±귶Χ12~15
	for (int i = 12; i < 16 - 1; ++i)
	{
		for (int j = 12; j < 16 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	//E,�±귶Χ16~19
	for (int i = 16; i < 20 - 1; ++i)
	{
		for (int j = 16; j < 20 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	//F�飬�±귶Χ20~23
	for (int i = 20; i < 14 - 1; ++i)
	{
		for (int j = 20; j < 24 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	//G�飬�±귶Χ24~27
	for (int i = 24; i < 28 - 1; ++i)
	{
		for (int j = 24; j < 28 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	//H�飬�±귶Χ28~31
	for (int i = 28; i < 32 - 1; ++i)
	{
		for (int j = 28; j < 32 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	for (int i = 0; i < teamCount; ++i)
	{
		cout << team[i].group << "\t"
			<< team[i].nameTeam << "\t\t"
			<< team[i].integral << endl;
	}
}

//�������������ԭʼ����
WCIM::WCIM()
//�������������ԭʼ����
{
	matchCount = 0;
	teamCount = 0;
	playerCount = 0;
	goalsCount = 0;
	fieldsCount = 0;

	ifstream fieldsFile("fieldsRecord.txt", ios::in);
	if (!fieldsFile)
	{
		cerr << "open fieldsFiel error" << endl;
		exit(1);
	}
	while (!fieldsFile.eof())
	{
		fieldsFile >> fields[fieldsCount].field
			>> fields[fieldsCount].time
			>> fields[fieldsCount].team1
			>> fields[fieldsCount].team2
			>> fields[fieldsCount].scores;

		++fieldsCount;
	}

	fieldsFile.close();

	ifstream matchFile("matchRecord.txt", ios::in); 	//������ķ�ʽ���ļ�

	if (!matchFile)   				//�����Ƿ�ɹ���
	{
		cerr << "open matchFile error!" << endl;
		exit(1);
	}
	while (!matchFile.eof())
	{
		matchFile >> match[matchCount].natureCompetition
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
		teamFile >> team[teamCount].group
			>> team[teamCount].nameTeam;
		team[teamCount].integral = 0;  //���������0
		team[teamCount].numWin = 0;  //ʤ
		team[teamCount].numFlat = 0;  //ƽ
		team[teamCount].numNegative = 0;  //��
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
			>> player[playerCount].nameTeam
			>> player[playerCount].number;
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
		goalsFile >> goals[goalsCount].field  //����
			>> goals[goalsCount].time  //����ʱ��
			>> goals[goalsCount].name
			>> goals[goalsCount].nameTeam
			>> goals[goalsCount].numberPlayer  //���
			>> goals[goalsCount].GoalCharacteristics;  //��������
		++goalsCount;
	}
	goalsFile.close();

	cout << "matchCount:" << matchCount << endl;
	cout << "teamCount:" << teamCount << endl;
	cout << "playerCount:" << playerCount << endl;
	cout << "goalsCount:" << goalsCount << endl;
	cout << "fieldsCount:" << fieldsCount << endl;
}

//���������ģ���ѯϵͳ
void WCIM::Run()
//���������ģ���ѯϵͳ
{
	cout << "==============2018����˹���籭��������|����|���ְ�|���ְ�==============" << endl;
	int select;  //��ʱ����
	do
	{
		cout << "** 1--��ʾ��ʷ��������         **" << endl;
		cout << "** 2--��ʾ��ʷ��������         **" << endl;
		cout << "** 3--����ʱ�̣����������Ԥ�� **" << endl;
		cout << "** 4--��ѯ���Σ���ʾ��ϸ��Ϣ   **" << endl;
		cout << "** 5--��ʾ���г�����Ϣ         **" << endl;

		cout << "����ѡ��";  //����ѡ��
		cin >> select;  //����ѡ��
		while (getchar() != '\n');  //������ǰ�е������ַ�
		string time;
		switch (select)
		{
		case 1:
			DisplayMatchInforAll();
			break;
		case 2:
			DisplayPlayerInforAll();
			break;
		case 3:
			time = IntegralAndShooterStatistics();
			IntegralAndShooterTable(time);
			break;
		case 4:
			FindField();
			break;
		case 5:
			DisplayFieldInforAll();
			break;

			//case 5:
			//	DisplayALL();  //��ʾ���м�¼
			//	break;
		}
	} while (select != 0);
}
