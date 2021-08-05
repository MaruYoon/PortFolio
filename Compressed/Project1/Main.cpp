#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <Windows.h>

using namespace std;

struct StudentInfo
{
	char* Name;
	int Index;

	int Kor;
	int Eng;
	int Math;
};


list<StudentInfo> StudentList;


void LoadDate();
void ScoreSwap(StudentInfo& _A, StudentInfo& _B);
void KorSort();
void EngSort();
void MathSort();

int main(void)
{
	LoadDate();

	/*
	for (list<StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << iter->Index << " : " << iter->Name << endl;
		cout << "���� ���� : " << iter->Kor << endl;
		cout << "���� ���� : " << iter->Eng << endl;
		cout << "���� ���� : " << iter->Math << endl << endl;
	}
	*/

	//** �о�� �����͸� ������ ������ ���� �������� ������ �Ұ��̴�.
	//** ����, ����, ���� �������� ������ �� ���õ� ������ ������ �������� �����Ұ�.




	while (true)
	{

		cout << "**�л� ���� ����**" << endl << endl;
		cout << "1.��ü ���� ���" << endl;
		cout << "2.���� ���� ����" << endl;
		cout << "3.��          ��" << endl << endl;


		int Num;
		cout << "�Է� : "; cin >> Num;
		cout << endl;



		switch (Num)
		{
		case 1:
			for (list<StudentInfo>::iterator iter = StudentList.begin();
				iter != StudentList.end(); ++iter)
			{
				cout << iter->Index << " : " << iter->Name << endl;
				cout << "���� ���� : " << iter->Kor << endl;
				cout << "���� ���� : " << iter->Eng << endl;
				cout << "���� ���� : " << iter->Math << endl << endl;
			}
			break;

		case 2:

			cout << "**���� ������ �����ϼ���**" << endl << endl;
			cout << "1.���� ����" << endl;
			cout << "2.���� ����" << endl;
			cout << "3.���� ����" << endl << endl;

			int num;
			cout << "�Է� : ";
			cin >> num;
			
			switch (num)
			{
			case 1:
				KorSort();
				break;

			case 2:
				EngSort();
				break;

			case 3:
				MathSort();
				break;
			}
			break;

		case 3:
			exit(NULL);
			break;

		}
		system("pause");
		system("cls");
	}

	return 0;
}


void LoadDate()
{
	//** �����͸� �ҷ��´�.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** ������ ������ �о�´�.
	while (!feof(pFileCSV))
	{
		StudentInfo Info;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&Info.Index, &Info.Kor, &Info.Eng, &Info.Math, buffer);


		//** �о�� ���ڿ��� �����Ϳ� �°� �����Ѵ�.
		Info.Name = new char[4];
		strcpy(Info.Name, buffer);

		//** ����Ʈ�� �߰��Ѵ�.
		StudentList.push_back(Info);
	}

	//** ������ �ݴ´�.
	fclose(pFileCSV);
}


void ScoreSwap(StudentInfo& _A, StudentInfo& _B)
{
	StudentInfo Tmp = _A;

	_A = _B;
	_B = Tmp;
}

void KorSort()
{
	for (list<StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		for (list<StudentInfo>::iterator iter2 = iter;
			iter2 != StudentList.end(); ++iter2)
		{
			if ((*iter).Kor < (*iter2).Kor)
			{
				ScoreSwap((*iter), (*iter2));

			}
		}
	}
}

void EngSort()
{
	for (list<StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		for (list<StudentInfo>::iterator iter2 = iter;
			iter2 != StudentList.end(); ++iter2)
		{
			if ((*iter).Eng < (*iter).Eng)
			{
				ScoreSwap((*iter), (*iter2));
			}
		}
	}
}

void MathSort()
{
	for (list<StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		for (list<StudentInfo>::iterator iter2 = iter;
			iter2 != StudentList.end(); ++iter2)
		{
			if ((*iter).Math < (*iter).Math)
			{
				ScoreSwap((*iter), (*iter2));
			}
		}
	}
}




