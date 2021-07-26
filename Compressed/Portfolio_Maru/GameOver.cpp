#include "GameOver.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::Initialize()
{

	Trans[0].Texture = (char*)"                          	          .adAMMMb.   .dAMMMAbn.			";
	Trans[1].Texture = (char*)"                                  .adAWWWWWWWWWAuAWWWWWWWWWWAbn.		";
	Trans[2].Texture = (char*)"                               .adWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWbn.	";
	Trans[3].Texture = (char*)"                           ..adMMMMMP^~ .-- ~^YWWWWWWWWWWHHMMMMMMMMbn..";
	Trans[4].Texture = (char*)"                                ~^Y   /    ..dMWMP .ammmmdMMMUP^~		";
	Trans[5].Texture = (char*)"                                  |   Y    dMAbammdAMMMMMMP^~			";
	Trans[6].Texture = (char*)"                                  |   |    MMMMMMMMMMMMU^  			";
	Trans[7].Texture = (char*)"                                  l   :    Y^YUWWWWUP^ 				";
	Trans[8].Texture = (char*)"                                   \       j							";
	Trans[9].Texture = (char*)"                          		 -..,.^    					    ";
	Trans[10].Texture = (char*)"";
	Trans[11].Texture = (char*)"";

	Trans[12].Texture = (char*)"              ___     ___      ___   ___   _  _______    _______  __   __  _______  ";
	Trans[13].Texture = (char*)"             |   |   |   |    |   | |   | | ||       |  |       ||  | |  ||       | ";
	Trans[14].Texture = (char*)"             |   |   |   |    |   | |   |_| ||    ___|  |_     _||  |_|  ||    ___| ";
	Trans[15].Texture = (char*)"             |   |   |   |    |   | |      _||   |___     |   |  |       ||   |___  ";
	Trans[16].Texture = (char*)"             |   |   |   |___ |   | |     |_ |    ___|    |   |  |       ||    ___| ";
	Trans[17].Texture = (char*)"             |   |   |       ||   | |    _  ||   |___     |   |  |   _   ||   |___  ";
	Trans[18].Texture = (char*)"             |___|   |_______||___| |___| |_||_______|    |___|  |__| |__||_______| ";
	Trans[19].Texture = (char*)"             																		";
	Trans[20].Texture = (char*)" _______  _______  _______  _______  _______    _______  _______    __   __  _______  __   __ ";
	Trans[21].Texture = (char*)"|       ||   _   ||       ||       ||       |  |       ||       |  |  | |  ||       ||  | |  |";
	Trans[22].Texture = (char*)"|_     _||  |_|  ||  _____||_     _||    ___|  |   _   ||    ___|  |  |_|  ||   _   ||  | |  |";
	Trans[23].Texture = (char*)"  |   |  |       || |_____   |   |  |   |___   |  | |  ||   |___   |       ||  | |  ||  |_|  |";
	Trans[24].Texture = (char*)"  |   |  |       ||_____  |  |   |  |    ___|  |  |_|  ||    ___|  |_     _||  |_|  ||       |";
	Trans[25].Texture = (char*)"  |   |  |   _   | _____| |  |   |  |   |___   |       ||   |        |   |  |       ||       |";
	Trans[26].Texture = (char*)"  |___|  |__| |__||_______|  |___|  |_______|  |_______||___|        |___|  |_______||_______|";

	for (int i = 0; i < 27; ++i)
	{
		Trans[i].TransPos.Position = Vector3(
			60 - (float)strlen(Trans[21].Texture) / 2, 1.0f);
	}

}

void GameOver::Update()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		SceneManager::Getinstance()->SetScene(SCENEID_LOGO);
	}

}

void GameOver::Render()
{
	for (int i = 0; i < 27; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(Trans[i].TransPos.Position.x),
			int(Trans[i].TransPos.Position.y) + i,
			Trans[i].Texture);
	}
}

void GameOver::Release()
{
}

