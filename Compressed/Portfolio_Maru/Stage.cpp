#include "Stage.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"


#include "Player.h"



Stage::Stage()
{
}

Stage::~Stage()
{
	//Release();
}

void Stage::Initialize()
{
	Object* pPlayer = new Player;
	pPlayer->Initialize();

	ObjectManager::Getinstance()->Initialize();
	ObjectManager::Getinstance()->SetPlayer(pPlayer);

	Time = (ULONG)GetTickCount64();
}

void Stage::Update()
{
	if ( ULONG(Time + 10000) < GetTickCount64())
	{
		Time = (ULONG)GetTickCount64();
		ObjectManager::Getinstance()->CreateEnemy();
	}

	ObjectManager::Getinstance()->Update();

	//if (GetAsyncKeyState(VK_ESCAPE))
	//{
	//	SceneManager::Getinstance()->SetScene(SCENEID_MENU);
	//}
}

void Stage::Render()
{
	ObjectManager::Getinstance()->Render();
}

void Stage::Release()
{

}

