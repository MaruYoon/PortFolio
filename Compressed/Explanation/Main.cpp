#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>


using namespace std;


struct StudentInfo
{
	char* Name;
	int Index;

	int Kor;
	int Eng;
	int Math;
};

list<StudentInfo*> StudentList;


void LoadDate();
void Output();

int main(void)
{
	LoadDate();

	list<StudentInfo*> SortList(StudentList);


	/*
	Output();

	//** 읽어온 데이터를 각각의 점수에 따라 내림차순 정렬을 할것이다.
	//** 국어, 영어, 수학 점수별로 선택한 후 선택된 과목의 점수를 내림차순 정렬할것.

	int num;

	cout << "내림차순 정렬" << endl << endl;
	cout << "1. 국어 점수 정렬" << endl;
	cout << "2. 영어 점수 정렬" << endl;
	cout << "3. 수학 점수 정렬" << endl;

	cout << "입력 : "; cin >> num;


	switch (num)
	{
	case 1:
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
		break;

	case 2:
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
		break;

	case 3:
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

		break;
	}

	cout << endl << endl;
	cout << "******************" << endl;
	for (list<StudentInfo*>::iterator iter = SortList.begin();
		iter != SortList.end(); ++iter)
	{
		cout << (*iter)->Index << " : " << (*iter)->Name << endl;
		cout << "국어 점수 : " << (*iter)->Kor << endl;
		cout << "영어 점수 : " << (*iter)->Eng << endl;
		cout << "수학 점수 : " << (*iter)->Math << endl << endl;
	}
	cout << "******************" << endl;


	//Output();

	*/

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

	

	return 0;
}


void LoadDate()
{
	//** 에디터를 불러온다.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** 파일을 완전이 읽어온다.
	while (!feof(pFileCSV))
	{
		StudentInfo* pInfo = new StudentInfo;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&pInfo->Index, &pInfo->Kor, &pInfo->Eng, &pInfo->Math, buffer);

		//** 읽어온 문자열을 포인터에 맞게 변경한다.
		pInfo->Name = new char[4];
		strcpy(pInfo->Name, buffer);

		//** 리스트에 추가한다.
		StudentList.push_back(pInfo);
	}

	StudentList.pop_back();

	//** 파일을 닫는다.
	fclose(pFileCSV);
}


void Output()
{
	cout << endl << endl;
	cout << "******************" << endl;
	for (list<StudentInfo*>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter)->Index << " : " << (*iter)->Name << endl;
		cout << "국어 점수 : " << (*iter)->Kor << endl;
		cout << "영어 점수 : " << (*iter)->Eng << endl;
		cout << "수학 점수 : " << (*iter)->Math << endl << endl;
	}
	cout << "******************" << endl;
}
