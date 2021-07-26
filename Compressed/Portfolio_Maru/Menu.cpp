#include "Menu.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"


Menu::Menu()
{

}

Menu::~Menu()
{
}

void Menu::Initialize()
{
	Trans[0].Texture = (char*)"   _____________________________________________________ ";
	Trans[1].Texture = (char*)" / ＼                                                   | ";
	Trans[2].Texture = (char*)"|   |                                                   |";
	Trans[3].Texture = (char*)"＼_ |                                                   |";
	Trans[4].Texture = (char*)"    |                [ 체 크   리 스 트 ]               |";
	Trans[5].Texture = (char*)"    |                                                   |";
	Trans[6].Texture = (char*)"    |                                                   |";
	Trans[7].Texture = (char*)"    |             1. 음    식            □             |";
	Trans[8].Texture = (char*)"    |                                                   |";
	Trans[9].Texture = (char*)"    |             2. 생    수            □             |";
	Trans[10].Texture = (char*)"    |                                                   |";
	Trans[11].Texture = (char*)"    |             3. 건 전 지            □             |";
	Trans[12].Texture = (char*)"    |                                                   |";
	Trans[13].Texture = (char*)"    |             4. 양    초            □             |";
	Trans[14].Texture = (char*)"    |                                                   |";
	Trans[15].Texture = (char*)"    |                                                   |";
	Trans[16].Texture = (char*)"    |                                                   |";
	Trans[17].Texture = (char*)"    |               * * 주 의   사 항 * *               |";
	Trans[18].Texture = (char*)"    |                                                   |";
	Trans[19].Texture = (char*)"    |                                                   |";
	Trans[20].Texture = (char*)"    |               오래 머무르지 말 것!!               |";
	Trans[21].Texture = (char*)"    |                                                   |";
	Trans[22].Texture = (char*)"    |                                                   |";
	Trans[23].Texture = (char*)"    |    _______________________________________________|____";
	Trans[24].Texture = (char*)"    |   /                                                   / ";
	Trans[25].Texture = (char*)"    ＼_/___________________________________________________/  ";

	for (int i = 0; i < 26; ++i)
	{
		Trans[i].TransPos.Position = Vector3(4.0f, 2.0f);
	}

	//메뉴

	pMenu[0].Texture = (char*)"계     속";
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

void Menu::Update()
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
			SceneManager::Getinstance()->SetScene(SCENEID_STAGE);
			break;

		case 1:
			exit(NULL);
			break;		

		}
	}
}

void Menu::Render()
{
	for (int i = 0; i < 26; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)Trans[i].TransPos.Position.x,
			(int)Trans[i].TransPos.Position.y + i,
			Trans[i].Texture);
	}

	for (int i = 0; i < 10; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)pTitle[i].TransPos.Position.x,
			(int)pTitle[i].TransPos.Position.y + i,
			pTitle[i].Texture);
	}

	for (int i = 0; i < 2; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(pMenu[i].TransPos.Position.x),
			int(pMenu[i].TransPos.Position.y+i),
			pMenu[i].Texture, pMenu[i].Color);
	}
}

void Menu::Release()
{
}
