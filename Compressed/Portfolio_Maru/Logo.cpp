#include "Logo.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Initialize()
{
	Trans[0].Texture = (char*)"	                      .|";
	Trans[1].Texture = (char*)"                       | |";
	Trans[2].Texture = (char*)"                       |'|            ._____";
	Trans[3].Texture = (char*)"               ___    |  |            |     |  .----.";
	Trans[4].Texture = (char*)"       _    .-'   '-. |  |     .--'|  |     | _|    |";
	Trans[5].Texture = (char*)"    .-'|  _.|  |    ||   '-__  |   |  |     ||      |";
	Trans[6].Texture = (char*)"    |' | |.    |    ||       | |   |  |     ||      |";
	Trans[7].Texture = (char*)" ___|  '-'     '    ""         '-'   '-.'     '`      |____";
	Trans[8].Texture = (char*)"                                                         ";
	Trans[9].Texture = (char*)"                                                         ";
	Trans[10].Texture = (char*)"   #####    #####   ##   ##  ######   ####     #######";
	Trans[11].Texture = (char*)"   ## ##   ##   ##  ##   ##   ##  ##   ##       ##   #";
	Trans[12].Texture = (char*)"   ##  ##  ##   ##  ##   ##   ##  ##   ##       ## #  ";
	Trans[13].Texture = (char*)"   ##  ##  ##   ##  ##   ##   #####    ##       ####  ";
	Trans[14].Texture = (char*)"   ##  ##  ##   ##  ##   ##   ##  ##   ##   #   ## #  ";
	Trans[15].Texture = (char*)"   ## ##   ##   ##  ##   ##   ##  ##   ##  ##   ##   #";
	Trans[16].Texture = (char*)"   #####    #####    #####   ######   #######  #######";
	Trans[17].Texture = (char*)"=========================================================";
	Trans[18].Texture = (char*)"        #####    ####    #####    #######  #####    ";
	Trans[19].Texture = (char*)"       ##   ##    ##      ## ##    ##   #   ## ##   ";
	Trans[20].Texture = (char*)"       #          ##      ##  ##   ## #     ##  ##  ";
	Trans[21].Texture = (char*)"        #####     ##      ##  ##   ####     ##  ##  ";
	Trans[22].Texture = (char*)"            ##    ##      ##  ##   ## #     ##  ##  ";
	Trans[23].Texture = (char*)"       ##   ##    ##      ## ##    ##   #   ## ##   ";
	Trans[24].Texture = (char*)"        #####    ####    #####    #######  #####    ";

	for (int i = 0; i < 26; ++i)
	{
		Trans[i].TransPos.Position = Vector3(
			60 - ((float)strlen(Trans[17].Texture) / 2), 1.0f);
	}

	Trans[26].Texture = (char*)" 게임을 시작하려면 ENTER를 눌러주세요";
	Trans[26].TransPos.Position = Vector3(60 - ((float)strlen(Trans[26].Texture) / 2), 27.0f);
	Trans[26].Color = 7;

	LogoCheck = 0;
}

void Logo::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Getinstance()->SetScene(SCENEID_STORY);
	}
}

void Logo::Render()
{
	for (int i = 0; i < 25; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(Trans[i].TransPos.Position.x),
			int(Trans[i].TransPos.Position.y + i),
			Trans[i].Texture);	
	}

	DoubleBuffer::GetInstance()->WriteBuffer(
		int(Trans[26].TransPos.Position.x),
		int(Trans[26].TransPos.Position.y),
		Trans[26].Texture, Trans[26].Color);
}

void Logo::Release()
{
}
