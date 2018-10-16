#include "pch.h"
#include "WorldCupInforManage.h"

//�����������λ����
void WCIM::FindField()
{
	int inputField;  //�û�����ĳ���
	cout << "�����볡��:";
FIND:
	cin >> inputField;
	if (inputField < 1 || inputField > 64)
	{
		cout << "�������!!!��������1~64��Χ��������ȷ��ֵ:";
		goto FIND;
		
	}
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
//�����������ʾ���г�����Ϣ
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

//�������������С�����������16ǿ
void WCIM::GroupMatchSituation()
{
	//ͳ��С�����������ݲ���ʾ=============
    //����ͳ��
	int AFlag = -1, BFlag = -1;  //����1��team�е�λ�ã�����2��team�е�λ��
	//��һ��������¼matchRecordƥ�����team�����û��ּ���Ĺ���
	//ͳ��С�����������ݲ���ʾ
	for (int i = 0; i < 96; ++i)
	{
		//��һ��������¼����team1��team2
		for (int j = 0; j < teamCount; ++j)  //��match[i].team1��team[]�е�λ��
		{
			if (team[j].nameTeam == match[i].team1)
			{
				AFlag = j;
				break;
			}
		} 

		for (int j = 0; j < teamCount; ++j)  //��match[i].team2��team[]�е�λ��
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
			////new - �������С�����ܽ�����
			//team[AFlag].goalsTotal += match[i].numGoal1; //����1С�������ܽ�����
			//team[BFlag].goalsTotal += match[i].numGoal2; //����2С�������ܽ�����

			//new - ����С������ʤ�����
			team[AFlag].goalsDifference += match[i].numGoal1 - match[i].numGoal2; //����1���ܾ�ʤ��
			team[BFlag].goalsDifference += match[i].numGoal2 - match[i].numGoal1;//����2���ܾ�ʤ��

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

	//�������������㷨���Ȼ��֣���group�����ʤ��
	//Test - ��һ�������羻ʤ�����������⣬����n(n>=2)ʱ���ݾ�������
	//integral
	for (int i = 0; i < teamCount - 1; ++i)
	{
		for (int j = 0; j < teamCount - i - 1; ++j)
		{
			if (team[j].integral < team[j + 1].integral) //�������ţ��Ӵ�С
			{
				SwapTeamInfor(team[j], team[j + 1]);
			}
		}
	}

	//group
	for (int i = 0; i < teamCount - 1; ++i)
	{
		for (int j = 0; j < teamCount - i - 1; ++j)
		{
			if (team[j].group > team[j + 1].group) //group��С����
			{
				SwapTeamInfor(team[j], team[j + 1]);
			}
		}
	}

	//goalsDifference
	for (int i = 0; i < teamCount - 1; ++i)
	{
		for (int j = 0; j < teamCount - i - 1; ++j)
		{
			//����ͬһgroup,����ʤ��Ӵ�С����
			if (team[j].group == team[j + 1].group) 
			{
				if (team[j].integral == team[j + 1].integral)
				{
					if (team[j].goalsDifference < team[j + 1].goalsDifference)
					{
						SwapTeamInfor(team[j], team[j + 1]);
					}
				}
			}
			if (team[j].group > team[j + 1].group) //group��С����
			{
				SwapTeamInfor(team[j], team[j + 1]);
			}
		}
	}

	//��ʾ���ְ�
	cout << "===============С�������յĻ��ְ�===============" << endl;
	cout << "���" << "\t" << "����" << "\t\t" << "����" << "\t" << "ʤ" << "\t" << "ƽ" << "\t" << "��" << "\t" << "��ʤ��" << endl;
	for (int i = 0; i < teamCount; ++i)
	{
		cout << team[i].group << "\t"
			<< team[i].nameTeam << "\t\t"
			<< team[i].integral << "\t"
			<< team[i].numWin << "\t"
			<< team[i].numFlat << "\t"
			<< team[i].numNegative << "\t"
			<< team[i].goalsDifference << endl;
	}

	//���ְ���������
	ClearZeroIntegral();
}

//���������ʱ������������ͨ�������ʱ����ò�ͬ�ĺ���
void WCIM::TimeGuide()
//���������ʱ������������ͨ�������ʱ����ò�ͬ�ĺ���
{
	string groupCloseTime = "06-29-04";  //���һ��С�����Ľ���ʱ��
	string inputTime;
	cout << "������ʱ��:";
	cin >> inputTime;

	//С�����л��ְ���̭���޻��ְ񣬵��������ְ�
	if (inputTime <= groupCloseTime)  //С����������
	{
		//���ְ�����ͳ�Ʋ���ʾ
		Integral(inputTime);

		//���ְ�����ͳ�Ʋ���ʾ
		Shooters(inputTime);
	}
	else  //��̭��������
	{
		//��ʾС��������ʱ�Ļ��ְ�
		//����С���������Ϊ��̭����׼��
		GroupMatchSituation();  //С�������ս��չʾ
		InitializeKnockoutData();  //16ǿ

		cout << "��̭�����ڱ�д������" << endl;
		cout << "Wating..." << endl;
	}
}

//������������ְ�����ͳ�Ʋ���ʾ
void WCIM::Integral(string inputTime)
//������������ְ�����ͳ�Ʋ���ʾ
{
	//����ͳ��
	int nCount = 0;
	//����ʱ��ڵ���inputTime֮ǰ�ı�����¼��Ŀ(����inputTime)
	for (int i = 0; i < matchCount; ++i)
	{
		if (inputTime >= match[i].time)
		{
			nCount++;
		}
		else
		{
			break;
		}
	}
	int AFlag = -1, BFlag = -1;  //����1��team�е�λ�ã�����2��team�е�λ��
	//��һ��������¼matchRecordƥ�����team�����û��ּ���Ĺ���
	for (int i = 0; i < nCount; ++i)
	{
		//��һ��������¼����team1��team2
		for (int j = 0; j < teamCount; ++j)  //��match[i].team1��team[]�е�λ��
		{
			if (team[j].nameTeam == match[i].team1)
			{
				AFlag = j;
				break;
			}
		} 

		for (int j = 0; j < teamCount; ++j)  //��match[i].team2��team[]�е�λ��
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

	//�����ʾ
	//ð������
	for (int i = 0; i < teamCount - 1; ++i)
	{
		for (int j = 0; j < teamCount - i - 1; ++j)
		{
			if (team[j].integral < team[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(team[j], team[j + 1]);
			}
		}
	}

	//��ʾ���ְ�
	cout << "===============" << inputTime << "�Ļ��ְ�===============" << endl;
	cout << "���" << "\t" << "����" << "\t\t" << "����" << "\t" << "ʤ" << "\t" << "ƽ" << "\t" << "��" << endl;
	for (int i = 0; i < teamCount; ++i)
	{
		cout << team[i].group << "\t"
			<< team[i].nameTeam << "\t\t"
			<< team[i].integral << "\t"
			<< team[i].numWin << "\t"
			<< team[i].numFlat << "\t"
			<< team[i].numNegative << endl;
	}

	//���ְ���������
	ClearZeroIntegral();
}

//������������ְ�����ͳ�Ʋ���ʾ
void WCIM::Shooters(string inputTime)
//������������ְ�����ͳ�Ʋ���ʾ
{
	//����ͳ��
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

	//�����ʾ
	//ð������
	for (int i = 0; i < playerCount - 1; ++i)
	//������Ϣ����Ա��Ϣƥ��
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
	cout << "===============" << inputTime << "�����ְ�" << "===============" << endl;
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

	//���ְ���������
	ClearZeroShooters();
}

//������������ְ�����
void WCIM::ClearZeroIntegral()
//������������ְ�����
{
	//���֡�ʤ��ƽ��������ʤ������
	for (int i = 0; i < teamCount; ++i)
	{
		team[i].integral = 0;
		team[i].numWin = 0;
		team[i].numFlat = 0;
		team[i].numNegative = 0;
		team[i].goalsDifference = 0;
	}
}

//������������ְ�����
void WCIM::ClearZeroShooters()
//������������ְ�����
{
	//��Ա����������
	for (int i = 0; i < playerCount; ++i)
	{
		player[i].numGoal = 0;
	}
}

//�����������¼16ǿ��������8ǿ
void WCIM::InitializeKnockoutData()
//�����������¼16ǿ��������8ǿ
{
	int Count_16 = 0;

	//����16ǿ
	//����A1,B2 \ C1,D2 \ E1,F2 \ G1,H2 || A2,B1 \ C2,D1 \ E2,F1 \ G2,H1s˳�����16ǿ
	knockkoutMatch[Count_16].team1 = team[0].nameTeam;  //A1
	knockkoutMatch[Count_16].team2 = team[5].nameTeam;  //B2
	Count_16++;
	knockkoutMatch[Count_16].team1 = team[8].nameTeam;  //C1
	knockkoutMatch[Count_16].team2 = team[13].nameTeam;  //D2
	Count_16++;
	knockkoutMatch[Count_16].team1 = team[16].nameTeam;  //E1
	knockkoutMatch[Count_16].team2 = team[21].nameTeam;  //F2
	Count_16++;
	knockkoutMatch[Count_16].team1 = team[24].nameTeam;  //G1
	knockkoutMatch[Count_16].team2 = team[29].nameTeam;  //H2
	Count_16++;
	knockkoutMatch[Count_16].team1 = team[1].nameTeam;  //A2
	knockkoutMatch[Count_16].team2 = team[4].nameTeam;  //B1
	Count_16++;
	knockkoutMatch[Count_16].team1 = team[9].nameTeam;  //C2
	knockkoutMatch[Count_16].team2 = team[12].nameTeam;  //D1
	Count_16++;
	knockkoutMatch[Count_16].team1 = team[17].nameTeam;  //E2
	knockkoutMatch[Count_16].team2 = team[20].nameTeam;  //F1
	Count_16++;
	knockkoutMatch[Count_16].team1 = team[25].nameTeam;  //G2
	knockkoutMatch[Count_16].team2 = team[28].nameTeam;  //H1
	Count_16++;

	//test - ����������
	cout << "16ǿ" << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout << knockkoutMatch[i].team1 << "    "
		     << knockkoutMatch[i].team2 << endl;
	}

	//����8ǿ
	for (int i = 0; i < 8; i++)  //ͨ������1/8������¼���1/4��������
	{
		string leftNameTeam;
		string rightNameTeam;
		if (i % 2 == 0)  //�±�Ϊż��
		{
			if (knockkoutMatch[i].numGoal1 > knockkoutMatch[i].numGoal2)  //A1 > B2
			{
				 leftNameTeam = knockkoutMatch[i].team1;
			}
			else
			{
				leftNameTeam = knockkoutMatch[i].team2;
			}

			knockkoutMatch[Count_16].team1 = leftNameTeam;
		}
		else  //�±�Ϊ����
		{
			if (knockkoutMatch[i].numGoal1 > knockkoutMatch[i].numGoal2)  //C1 > D2
			{
				rightNameTeam = knockkoutMatch[i].team1;
			}
			else
			{
				rightNameTeam = knockkoutMatch[i].team2;
			}

			knockkoutMatch[Count_16].team2 = rightNameTeam;
		    
			//����ʱ��̭��������������1
			Count_16++;  //������һ������˫���ļ�¼
		}
	}

	//test - ���8ǿ�������
	cout << "8ǿ" << endl;
	for (int i = 8; i < 12; ++i)
	{
		cout << knockkoutMatch[i].team1 << " "
			<< knockkoutMatch[i].team2 << endl;
	}

	//����4ǿ
	for (int i = 8; i < 12; ++i)  //ͨ������1/4������ð������������
	{
		string leftNameTeam;
		string rightNameTeam;
		if (i % 2 == 0)  //�±�Ϊż��
		{
			if (knockkoutMatch[i].numGoal1 > knockkoutMatch[i].numGoal2)  //A1 > B2
			{
				leftNameTeam = knockkoutMatch[i].team1;
			}
			else
			{
				leftNameTeam = knockkoutMatch[i].team2;
			}

			knockkoutMatch[Count_16].team1 = leftNameTeam;
		}
		else  //�±�Ϊ����
		{
			if (knockkoutMatch[i].numGoal1 > knockkoutMatch[i].numGoal2)  //C1 > D2
			{
				rightNameTeam = knockkoutMatch[i].team1;
			}
			else
			{
				rightNameTeam = knockkoutMatch[i].team2;
			}

			knockkoutMatch[Count_16].team2 = rightNameTeam;

			//����ʱ��̭��������������1
			Count_16++;  //������һ������˫���ļ�¼
		}
	}

	//test - ���4ǿ�������
	cout << "4ǿ" << endl;
	for (int i = 12; i < 14; ++i)
	{
		cout << knockkoutMatch[i].team1 << " "
			<< knockkoutMatch[i].team2 << endl;
	}

	//���ɰ�����;�������
	for (int i = 12; i < 14; ++i)  //����1/4������ð�����;�������
	{
		//������������ս����˫��
		string leftSemifinalsNameTeam;
		string rightSemifinalsNameTeam;
		//һ����������ս����˫��
		string leftFinalsNameTeam;
		string rightFinalsNameTeam;

		if (i % 2 == 0)  
		{
			if (knockkoutMatch[i].numGoal1 > knockkoutMatch[i].numGoal2)
			{
				leftFinalsNameTeam = knockkoutMatch[i].team1;
				leftSemifinalsNameTeam = knockkoutMatch[i].team2;
			}
			else
			{
				leftFinalsNameTeam = knockkoutMatch[i].team2;
				leftSemifinalsNameTeam = knockkoutMatch[i].team1;
			}

			knockkoutMatch[Count_16].team1 = leftSemifinalsNameTeam;
			knockkoutMatch[Count_16 + 1].team1 = leftFinalsNameTeam;
			Count_16++;  //����һ������
		}
		else
		{
			if (knockkoutMatch[i].numGoal1 > knockkoutMatch[i].numGoal2)
			{
				rightFinalsNameTeam = knockkoutMatch[i].team1;
				rightSemifinalsNameTeam = knockkoutMatch[i].team2;
			}
			else
			{
				rightFinalsNameTeam = knockkoutMatch[i].team2;
				rightSemifinalsNameTeam = knockkoutMatch[i].team1;
			}

			knockkoutMatch[Count_16 - 1].team2 = rightSemifinalsNameTeam;
			knockkoutMatch[Count_16].team2 = rightFinalsNameTeam;

		}
	}

	//test - ��������
	cout << "�����" << endl;
	cout << knockkoutMatch[14].team1 << " "
		<< knockkoutMatch[14].team2 << endl;

	//test - �������
	cout << "����" << endl;
	cout << knockkoutMatch[15].team1 << " "
		<< knockkoutMatch[15].team2 << endl;

	//�����������������
	if (knockkoutMatch[14].numGoal1 > knockkoutMatch[14].numGoal2)
	{
		cout << "��������" << knockkoutMatch[14].team1 << endl;
		cout << "������: " << knockkoutMatch[14].team2 << endl;
	}
	else
	{
		cout << "��������" << knockkoutMatch[14].team2 << endl;
		cout << "��������" << knockkoutMatch[14].team1 << endl;
	}

	//���������һ������
	if (knockkoutMatch[15].numGoal1 > knockkoutMatch[15].numGoal2)
	{
		cout << "��һ����" << knockkoutMatch[15].team1 << endl;
		cout << "�ڶ���: " << knockkoutMatch[15].team2 << endl;
	}
	else
	{
		cout << "��һ����" << knockkoutMatch[15].team2 << endl;
		cout << "�ڶ�����" << knockkoutMatch[15].team1 << endl;
	}
}

//�������������ԭʼ����
WCIM::WCIM()
//�������������ԭʼ����
{
	//new - ��̭�����ļ��ж���ļ�¼��
	knockkoutMatchCount = 0;

	matchCount = 0;
	teamCount = 0;
	playerCount = 0;
	goalsCount = 0;
	fieldsCount = 0;

	//new - ��ʼ����̭������
	ifstream knockkoutMatchFile("knockkoutMatchRecord.txt", ios::in);
	if (!knockkoutMatchFile)
	{
		cerr << "open knockkoutMatchRecord.txt error" << endl;
		exit(1);
	}
	while (!knockkoutMatchFile.eof())
	{
		knockkoutMatchFile >> knockkoutMatch[knockkoutMatchCount].time  //ʱ��
			>> knockkoutMatch[knockkoutMatchCount].numGoal1  //���1������
			>> knockkoutMatch[knockkoutMatchCount].numGoal2;  //���2������

		knockkoutMatchCount++;
	}

	//new - ��ʼ��knockkoutMatch��̭���ṹ���ݵ�����
	for (int i = 0; i < 16; ++i)
	{
		knockkoutMatch[i].team1 = "";
		knockkoutMatch[i].team2 = "";
	}
	knockkoutMatchFile.close();

	ifstream fieldsFile("fieldsRecord.txt", ios::in);
	if (!fieldsFile)
	{
		cerr << "open fieldsRecord.txt error" << endl;
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
		cerr << "open matchRecord.txt error!" << endl;
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
		cerr << "open teamRecord.txt error!" << endl;
		exit(1);
	}
	while (!teamFile.eof())
	{
		teamFile >> team[teamCount].group
			>> team[teamCount].nameTeam;
		//������Ϣ��ʼ��
		team[teamCount].integral = 0;  //����
		team[teamCount].numWin = 0;  //ʤ
		team[teamCount].numFlat = 0;  //ƽ
		team[teamCount].numNegative = 0;  //��
		team[teamCount].goalsDifference = 0;  //��ʤ��
		++teamCount;
	}
	teamFile.close();

	ifstream playerFile("playerRecord.txt", ios::in); //������ķ�ʽ���ļ�
	if (!playerFile)   				//�����Ƿ�ɹ���
	{
		cerr << "open playerRecord.txt error!" << endl;
		exit(1);
	}
	while (!playerFile.eof())
	{
		playerFile >> player[playerCount].nameTeam
			>> player[playerCount].name
			>> player[playerCount].number;
		player[playerCount].numGoal = 0;  //��Ա������

		++playerCount;
	}
	playerFile.close();

	ifstream goalsFile("goalsRecord.txt", ios::in);
	if (!goalsFile)
	{
		cerr << "open goalsRecord.txt error" << endl;
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

	//��¼���ļ��ж������������
	cout << "matchCount:" << matchCount << endl;
	cout << "teamCount:" << teamCount << endl;
	cout << "playerCount:" << playerCount << endl;
	cout << "goalsCount:" << goalsCount << endl;
	cout << "fieldsCount:" << fieldsCount << endl;
	cout << "knockkoutMatchCount:" << knockkoutMatchCount << endl;
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
		//string time;
		switch (select)
		{
		case 1:
			DisplayMatchInforAll();
			break;
		case 2:
			DisplayPlayerInforAll();
			break;
		case 3:
			TimeGuide();
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
