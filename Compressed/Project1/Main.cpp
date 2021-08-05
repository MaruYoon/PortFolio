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
		cout << "국어 점수 : " << iter->Kor << endl;
		cout << "영어 점수 : " << iter->Eng << endl;
		cout << "수학 점수 : " << iter->Math << endl << endl;
	}
	*/

	//** 읽어온 데이터를 각각의 점수에 따라 내림차순 정렬을 할것이다.
	//** 국어, 영어, 수학 점수별로 선택한 후 선택된 과목의 점수를 내림차순 정렬할것.

	while (true)
	{
		cout << "1.전체 점수 출력" << endl;
		cout << "2.지정 점수 정렬" << endl;
		cout << "3.종          료" << endl << endl;


		int Num;
		cout << "입력 : ";
		cin >> Num;

		system("cls");


		switch (Num)
		{
		case 1:
			for (list<StudentInfo>::iterator iter = StudentList.begin();
				iter != StudentList.end(); ++iter)
			{
				cout << iter->Index << " : " << iter->Name << endl;
				cout << "국어 점수 : " << iter->Kor << endl;
				cout << "영어 점수 : " << iter->Eng << endl;
				cout << "수학 점수 : " << iter->Math << endl << endl;
			}
			break;

		case 2:

			cout << "1.국어 정렬" << endl;
			cout << "2.영어 정렬" << endl;
			cout << "3.수학 정렬" << endl << endl;

			int num;
			cout << "입력 : ";
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
			//	cout << "수학 점수 : " << iter->Math < iter->Math << endl << endl;
			//}
			break;

		}

	}

	







	return 0;
}


void LoadDate()
{
	//** 에디터를 불러온다.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** 파일을 완전이 읽어온다.
	while (!feof(pFileCSV))
	{
		StudentInfo Info;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&Info.Index, &Info.Kor, &Info.Eng, &Info.Math, buffer);


		//** 읽어온 문자열을 포인터에 맞게 변경한다.
		Info.Name = new char[4];
		strcpy(Info.Name, buffer);

		//** 리스트에 추가한다.
		StudentList.push_back(Info);
	}

	//** 파일을 닫는다.
	fclose(pFileCSV);
}



