#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <Windows.h>


// (��,.��)v
using namespace std;


struct StudentInfo
{
	string Name;
	int Index;

	int Kor;
	int Eng;
	int Math;

};


//list<StudentInfo*> StudentList;



void LoadDate();

//void ScoreSwap(StudentInfo& _A, StudentInfo& _B);
void KorSort();
void EngSort();
void MathSort();
void Output();

//string strKey;
//string GetKey() { return strKey; }



int main(void)
{
	LoadDate();

	map<int, list<StudentInfo>>StudentList;

	
	
	

	int Num;
	cout << "�Է� : "; cin >> Num;
	cout << endl;


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


	


	/*
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
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != StudentList.end(); ++iter)
			{
				cout << (*iter)->Index << " : " << (*iter)->Name << endl;
				cout << "���� ���� : " << (*iter)->Kor << endl;
				cout << "���� ���� : " << (*iter)->Eng << endl;
				cout << "���� ���� : " << (*iter)->Math << endl << endl;
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
	*/

	return 0;
}


void LoadDate()
{
	//** �����͸� �ҷ��´�.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** ������ ������ �о�´�.
	while (!feof(pFileCSV))
	{
		StudentInfo* pInfo = new StudentInfo;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&pInfo->Index, &pInfo->Kor, &pInfo->Eng, &pInfo->Math, buffer);

		//** �о�� ���ڿ��� �����Ϳ� �°� �����Ѵ�.
		pInfo->Name = new char[4];
		strcpy(pInfo->Name, buffer);

		//** ����Ʈ�� �߰��Ѵ�.
		StudentList.push_back(pInfo);
	}

	StudentList.pop_back();

	//** ������ �ݴ´�.
	fclose(pFileCSV);
}


//void ScoreSwap(StudentInfo& _A, StudentInfo& _B)
//{
//	StudentInfo Tmp = _A;
//
//	_A = _B;
//	_B = Tmp;
//}

void KorSort()
{
	strKey = "KOR";

	list<StudentInfo*>SortList(StudentList);

	for (list<StudentInfo*>::iterator iter = SortList.begin();
		iter != SortList.end(); ++iter)
	{
		for (list<StudentInfo*>::iterator iter2 = iter;
			iter2 != SortList.end(); ++iter2)
		{
			if ((*iter)->Kor < (*iter2)->Kor)
			{
				StudentInfo* pTemp = (*iter);
				(*iter) = (*iter2);
				(*iter2) = pTemp;
			}
		}
	}
}

void EngSort()
{
	strKey = "ENG";

	list<StudentInfo*>SortList(StudentList);

	for (list<StudentInfo*>::iterator iter = SortList.begin();
		iter != SortList.end(); ++iter)
	{
		for (list<StudentInfo*>::iterator iter2 = iter;
			iter2 != SortList.end(); ++iter2)
		{
			if ((*iter)->Eng < (*iter2)->Eng)
			{
				StudentInfo* pTemp = (*iter);
				(*iter) = (*iter2);
				(*iter2) = pTemp;
			}
		}
	}
}

void MathSort()
{
	strKey = "MATH";

	list<StudentInfo*>SortList(StudentList);

	for (list<StudentInfo*>::iterator iter = SortList.begin();
		iter != SortList.end(); ++iter)
	{
		for (list<StudentInfo*>::iterator iter2 = iter;
			iter2 != SortList.end(); ++iter2)
		{
			if ((*iter)->Math < (*iter2)->Math)
			{
				StudentInfo* pTemp = (*iter);
				(*iter) = (*iter2);
				(*iter2) = pTemp;
			}
		}
	}
}

void Output()
{
	for (list<StudentInfo*>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter)->Index << " : " << (*iter)->Name << endl;
		cout << "���� ���� : " << (*iter)->Kor << endl;
		cout << "���� ���� : " << (*iter)->Eng << endl;
		cout << "���� ���� : " << (*iter)->Math << endl << endl;
	}
}





