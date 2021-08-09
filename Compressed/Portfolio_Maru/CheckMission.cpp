#include "CheckMission.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"
#include "Item.h"

CheckMission::CheckMission()
{

}

CheckMission::~CheckMission()
{
}

void CheckMission::Initialize()
{
	pPaper[0].Texture = (char*)"   _____________________________________________________ ";
	pPaper[1].Texture = (char*)" / ＼                                                   | ";
	pPaper[2].Texture = (char*)"|   |                                                   |";
	pPaper[3].Texture = (char*)"＼_ |                                                   |";
	pPaper[4].Texture = (char*)"    |                [ 체 크   리 스 트 ]               |";
	pPaper[5].Texture = (char*)"    |                                                   |";
	pPaper[6].Texture = (char*)"    |                                                   |";
	pPaper[7].Texture = (char*)"    |             1. 음    식            □             |";
	pPaper[8].Texture = (char*)"    |                                                   |";
	pPaper[9].Texture = (char*)"    |             2. 생    수            □             |";
	pPaper[10].Texture = (char*)"    |                                                   |";
	pPaper[11].Texture = (char*)"    |             3. 건 전 지            □             |";
	pPaper[12].Texture = (char*)"    |                                                   |";
	pPaper[13].Texture = (char*)"    |             4. 양    초            □             |";
	pPaper[14].Texture = (char*)"    |                                                   |";
	pPaper[15].Texture = (char*)"    |                                                   |";
	pPaper[16].Texture = (char*)"    |                                                   |";
	pPaper[17].Texture = (char*)"    |               * * 주 의   사 항 * *               |";
	pPaper[18].Texture = (char*)"    |                                                   |";
	pPaper[19].Texture = (char*)"    |                                                   |";
	pPaper[20].Texture = (char*)"    |               오래 머무르지 말 것!!               |";
	pPaper[21].Texture = (char*)"    |                                                   |";
	pPaper[22].Texture = (char*)"    |                                                   |";
	pPaper[23].Texture = (char*)"    |    _______________________________________________|____";
	pPaper[24].Texture = (char*)"    |   /                                                   / ";
	pPaper[25].Texture = (char*)"    ＼_/___________________________________________________/  ";

	vector<char*>::push_back()

	for (int i = 0; i < 26; ++i)
	{
		pPaper[i].TransPos.Position = Vector3(4.0f, 2.0f);
	}

	strKey = "CheckMission";


	pCheck[0].Texture = (char*)"GOT IT!!";
	pCheck[0].TransPos.Position = Vector3(42.0f, 9.0f);

	pCheck[1].Texture = (char*)"GOT IT!!";
	pCheck[1].TransPos.Position = Vector3(42.0f, 10.0f);
	
	pCheck[2].Texture = (char*)"GOT IT!!";
	pCheck[2].TransPos.Position = Vector3(42.0f, 11.0f);

	pCheck[3].Texture = (char*)"GOT IT!!";
	pCheck[3].TransPos.Position = Vector3(42.0f, 12.0f);





	//메뉴

	pMenu[0].Texture = (char*)"이어 하기";
	pMenu[1].Texture = (char*)"종     료";

	pMenu[0].Color = 8;
	pMenu[1].Color = 8;

	pMenu[0].TransPos.Position = Vector3(85, 17.0f);
	pMenu[1].TransPos.Position = Vector3(85, 18.0f);

	pMenu[0].TransPos.Scale = Vector3(9.0f, 1.0f);
	pMenu[1].TransPos.Scale = Vector3(9.0f, 1.0f);


	//타이틀

	pTitle[0].Texture = (char*)"  ______      __             _       __";
	pTitle[1].Texture = (char*)" /_  __/_  __/ /____   _____(_)___ _/ /";
	pTitle[2].Texture = (char*)"  / / / / / / __/ __＼/ ___/ / __ `/ / ";
	pTitle[3].Texture = (char*)" / / / /_/ / /_/ /_/ / /  / / /_/ / /";
	pTitle[4].Texture = (char*)"/_/  ＼___/＼__/＼__/_/  /_/＼___/_/  ";
	pTitle[5].Texture = (char*)"     __  ____           _           ";
	pTitle[6].Texture = (char*)"    /  |/  (_)_________(_)___   ___	";
	pTitle[7].Texture = (char*)"   / /|_/ / / ___/ ___/ / __ ＼/ __＼";
	pTitle[8].Texture = (char*)"  / /  / / (__  |__  ) / /_/  / / / /";
	pTitle[9].Texture = (char*)" /_/  /_/_/____/____/_/＼____/_/ /_/ ";


	for (int i = 0; i < 10; ++i)
	{
		pTitle[i].TransPos.Position = Vector3(70.0f, 3.0f);
	}

	Choice = 0;
}

int CheckMission::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (Choice != 0)
			Choice--;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (Choice != 1)
			Choice++;
	}

	switch (Choice)
	{
	case 0:
		pMenu[0].Color = 15;
		pMenu[1].Color = 8;
		break;

	case 1:
		pMenu[0].Color = 8;
		pMenu[1].Color = 15;
		break;

	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (Choice)
		{
		case 0:
			GETSINGLETON(ObjectManager)->SetCheckMission(false);
			//ObjectManager::Getinstance()->SetCheckMission(false);
		
			break;

		case 1:
			exit(NULL);
			break;

		}
	}

	return 0;
}

void CheckMission::Render()
{


	for (int i = 0; i < 26; ++i)
	{
		GETSINGLETON(DoubleBuffer)->WriteBuffer(
			(int)pPaper[i].TransPos.Position.x,
			(int)pPaper[i].TransPos.Position.y + i,
			pPaper[i].Texture);
		/*
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)pPaper[i].TransPos.Position.x,
			(int)pPaper[i].TransPos.Position.y + i,
			pPaper[i].Texture);
		*/
	}

	for (int i = 0; i < 10; ++i)
	{
		GETSINGLETON(DoubleBuffer)->WriteBuffer(
			(int)pTitle[i].TransPos.Position.x,
			(int)pTitle[i].TransPos.Position.y + i,
			pTitle[i].Texture);
		/*
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)pTitle[i].TransPos.Position.x,
			(int)pTitle[i].TransPos.Position.y + i,
			pTitle[i].Texture);
		*/
	}

	for (int i = 0; i < 2; ++i)
	{
		GETSINGLETON(DoubleBuffer)->WriteBuffer(
			int(pMenu[i].TransPos.Position.x),
			int(pMenu[i].TransPos.Position.y + i),
			pMenu[i].Texture, pMenu[i].Color);
		/*
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(pMenu[i].TransPos.Position.x),
			int(pMenu[i].TransPos.Position.y + i),
			pMenu[i].Texture, pMenu[i].Color);
		*/
	}


	for (int i = 0; i < 4; ++i)
	{
		GETSINGLETON(DoubleBuffer)->WriteBuffer(
			(int)pCheck[i].TransPos.Position.x,
			(int)pCheck[i].TransPos.Position.y + i,
			pCheck[i].Texture);
		/*
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)pCheck[i].TransPos.Position.x,
			(int)pCheck[i].TransPos.Position.y+i,
			pCheck[i].Texture);
		*/
	}


}

void CheckMission::Release()
{
}