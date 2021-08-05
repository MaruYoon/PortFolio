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
		cout << "1.��ü ���� ���" << endl;
		cout << "2.���� ���� ����" << endl;
		cout << "3.��          ��" << endl << endl;


		int Num;
		cout << "�Է� : ";
		cin >> Num;

		system("cls");


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

			cout << "1.���� ����" << endl;
			cout << "2.���� ����" << endl;
			cout << "3.���� ����" << endl << endl;

			int num;
			cout << "�Է� : ";
			cin >> num;
			
			switch (num)
			{
			case 1:
				
				for (list<StudentInfo>::iterator iter = StudentList.begin();
					iter != StudentList.end(); ++iter)
				{
					for (list<StudentInfo>::iterator iter2 = (iter++);
						iter2 != StudentList.end(); ++iter2)
					{
						if ((*iter).Kor < (*iter2).Kor)
						{
							int Temp = (*iter2).Kor;
							(*iter).Kor = (*iter).Kor;
							(*iter).Kor = Temp;
						}
					}
				}


				break;

			case 2:

				break;

			case 3:

				break;
			}
		



			break;

		case 3:
			//for (list<StudentInfo>::iterator iter = StudentList.begin();
			//	iter != StudentList.end(); ++iter)
			//{
			//	cout << iter->Index << " : " << iter->Name << endl;
			//	cout << "���� ���� : " << iter->Math < iter->Math << endl << endl;
			//}
			break;

		}

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



