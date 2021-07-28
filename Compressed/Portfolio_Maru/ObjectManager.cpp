#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "DoubleBuffer.h"
#include "InputManager.h"
#include "SceneManager.h"

#include "Enemy.h"
#include "Bullet.h"
#include "Door.h"
#include "Exit.h"
#include "Player.h"
#include "BackGround.h"
#include "Room.h"
#include "Object.h"
#include "TopPlayer.h"
#include "Item.h"
#include "CheckMission.h"


ObjectManager* ObjectManager::m_pinstance = NULL;


ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

Transform* ObjectManager::GetTopPlayer()
{
	return pTopPlayer->GetTransform();
}

void ObjectManager::Initialize()
{


	//스테이지 1
	pBackGround = ObjectFactory<BackGround>::CreateObject();

	//스테이지 2
	for (int i = 0; i < 9; ++i)
	{
		InRoom[i] = ObjectFactory<Room>::CreateObject();
	}

	pTopPlayer = ObjectFactory<TopPlayer>::CreateObject();
	
	//아이템
	
	Initem = ObjectFactory<Item>::CreateObject();
	
	pCheckMission = ObjectFactory<CheckMission>::CreateObject();

	CreatDoor();
	CreatExit();



	for (int i = 0; i < 128; ++i)
	{
		AddObject(ObjectFactory<Enemy>::CreateObject());

		//ObjectList[OBJID_ENEMY][i] = ObjectFactory<Enemy>::CreateObject();
		//ObjectList[OBJID_BULLET][i] = ObjectFactory<Bullet>::CreateObject();
	}

	EnemyCount = 0;
	CheckInRoom = false;
	_CheckMission = false;


	CreateEnemy();

	
}

void ObjectManager::Update()
{
	for (int i = 0; i < OBJID_MAX; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			int iResult = 0;

			if(!CheckInRoom)
				if (ObjectList.find(Object::GetKey(Enemy))->GetActive())
					iResult = ObjectList[i][j]->Update();

			if (iResult == 1)
				ObjectList[i][j]->SetActive(false);

			if (iResult == -1)
				--EnemyCount;

		}
	}

	/*for (int i = 0; i < 128; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			if (ObjectList[OBJID_ENEMY][i]->GetActive())
			{
				if (ObjectList[OBJID_BULLET][j]->GetActive())
				{
					if (CollisionManager::CollisionRact(
						*ObjectList[OBJID_ENEMY][i]->GetTransform(),
						*ObjectList[OBJID_BULLET][j]->GetTransform()))
					{
						ObjectList[OBJID_ENEMY][i]->SetActive(false);
						ObjectList[OBJID_BULLET][j]->SetActive(false);
						--EnemyCount;
					}
				}
			}
		}
	}*/


	for (int i = 0; i < 128; ++i)
	{
		ObjectList.find("Enemy")->first.begin();

		if (ObjectList[OBJID_ENEMY][i]->GetActive())
		{
			if (CollisionManager::CollisionRact(
				*ObjectList[OBJID_ENEMY][i]->GetTransform(),
				*pPlayer->GetTransform()))
			{
				if (GetAsyncKeyState(VK_CONTROL))
				{
					break;
				}
				else
				{
					SceneManager::Getinstance()->SetScene(SCENEID_EXIT);
				}
				ObjectList[OBJID_ENEMY][i]->SetActive(false);
			}
		}
	}




	ULONG ulKey = InputManager::Getinstance()->GetKey();

	for (int i = 0; i < 9; ++i)
	{
		if (CollisionManager::CollisionRact(
			*BackDoor[i]->GetTransform(),
			*pPlayer->GetTransform()))
		{
			if (ulKey & KEYID_UP)
			{
				CheckInRoom = true;
				RoomIndex = i;

				pTopPlayer->Initialize();
				Initem->Initialize();
			}
		}
	}

	if (CheckInRoom)
	{
		InRoom[RoomIndex]->Update();

		Initem->Update();
		pTopPlayer->Update();

	} 

	else
	{
		pPlayer->Update();
	}

	for (int i = 0; i < 3; ++i)
	{
		if (CollisionManager::CollisionRact(
			*BackExit[i]->GetTransform(),
			*pPlayer->GetTransform()))
		{
			if (ulKey & KEYID_DOWN)
			{
				if (pPlayer->GetPosition().y < 27.0f)
				{
					pPlayer->SetPosition(
						pPlayer->GetPosition().x,
						pPlayer->GetPosition().y + 10.0f);

					break;
				}

				else
					break;

			}

			if (ulKey & KEYID_UP)
			{
				if (pPlayer->GetPosition().y > 7.0f)
				{
					pPlayer->SetPosition(
						pPlayer->GetPosition().x,
						pPlayer->GetPosition().y - 10.0f);

					break;
				}
				
				else
					break;

			}
		}
	}
	

	if (ulKey & KEYID_ESCAPE)
	{
		_CheckMission = true;
		pCheckMission->Initialize();
	}
	if (_CheckMission)
	{
		pCheckMission->Update();
	}





}

void ObjectManager::Render()
{

#ifdef EDITMODE

	if (CheckInRoom)
	{
		InRoom[RoomIndex]->Render();

		Initem->Render();
		pTopPlayer->Render();

	}
	else
	{
		pBackGround->Render();

		for (int i = 0; i < 9; ++i)
			BackDoor[i]->Render();

		for (int i = 0; i < 3; ++i)
			BackExit[i]->Render();

		pPlayer->Render();
	}

	for (int i = 0; i < OBJID_MAX; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			if (!CheckInRoom)
				if (ObjectList[i][j]->GetActive())
					ObjectList[i][j]->Render();
		}
	}


	for (int i = 0; i < (EnemyCount + 2); ++i)
	{
		if (i == 0 || i == (EnemyCount + 1))
			DoubleBuffer::GetInstance()->WriteBuffer(
				0, i, (char*)"*──────────*");
		else
			DoubleBuffer::GetInstance()->WriteBuffer(
				0, i, (char*)"*　　　　　　　　　　*");
	}


	for (int i = 0; i < 128; ++i)
	{
		if (ObjectList[OBJID_ENEMY][i]->GetActive())
		{
			DoubleBuffer::GetInstance()->WriteBuffer((int)12, i + 1, (int)ObjectList[OBJID_ENEMY][i]->GetPosition().x);
			DoubleBuffer::GetInstance()->WriteBuffer((int)17, i + 1, (int)ObjectList[OBJID_ENEMY][i]->GetPosition().y);
		}
	}



#else

	if (CheckInRoom)
	{
		InRoom[RoomIndex]->Render();

		pTopPlayer->Render();
		Initem->Render();

	}

	else if (_CheckMission)
	{
		pCheckMission->Render();
	}

	else
	{
		pBackGround->Render();

		for (int i = 0; i < 9; ++i)
			BackDoor[i]->Render();

		for (int i = 0; i < 3; ++i)
			BackExit[i]->Render();

		pPlayer->Render();

		for (int i = 0; i < OBJID_MAX; ++i)
		{
			for (int j = 0; j < 128; ++j)
			{
				if (ObjectList[i][j]->GetActive())
					ObjectList[i][j]->Render();
			}
		}
	}
	


#endif
}

void ObjectManager::Release()
{
	SAFE_RELEASE(pPlayer);

	for (int i = 0; i < OBJID_MAX; ++i)
		for (int j = 0; j < 128; ++j)
			SAFE_RELEASE(ObjectList[i][j]);
}


void ObjectManager::CreatDoor()
{
	//객실문
	for (int i = 0; i < 9; ++i)
	{
		BackDoor[i] = ObjectFactory<Door>::CreateObject();
	}

	BackDoor[0]->SetPosition(12.0f, 8.0f);
	BackDoor[1]->SetPosition(42.0f, 8.0f);
	BackDoor[2]->SetPosition(72.0f, 8.0f);

	BackDoor[3]->SetPosition(12.0f, 18.0f);
	BackDoor[4]->SetPosition(42.0f, 18.0f);
	BackDoor[5]->SetPosition(72.0f, 18.0f);
	 
	BackDoor[6]->SetPosition(12.0f, 28.0f);
	BackDoor[7]->SetPosition(42.0f, 28.0f);
	BackDoor[8]->SetPosition(72.0f, 28.0f);

	for (int i = 0; i < 9; ++i)
	{
		((Door*)BackDoor[i])->SetIndex(i);
	}
}

void ObjectManager::CreatExit()
{
	//비상계단
	for (int i = 0; i < 3; ++i)
	{
		BackExit[i] = ObjectFactory<Exit>::CreateObject();
	}

	BackExit[0]->SetPosition(105.0f, 8.0f);
	BackExit[1]->SetPosition(105.0f, 18.0f);
	BackExit[2]->SetPosition(105.0f, 28.0f);

}

void ObjectManager::CreateEnemy()
{
	ObjectList[OBJID_ENEMY][EnemyCount]->Initialize();

	int Index = EnemyCount % 3;
	// Index = 0,1,2
	int Horizontal = rand() % 2;
	//horizontal = 0,1

	((Enemy*)ObjectList[OBJID_ENEMY][EnemyCount])->SetIndex(Index);
	((Enemy*)ObjectList[OBJID_ENEMY][EnemyCount])->SetHorizontal(Horizontal);

	if (Horizontal)
	{
		switch (Index)
		{
		case 0:
			ObjectList[OBJID_ENEMY][EnemyCount]->SetPosition(
				4.0f, 7.0f);
			break;
		case 1:
			ObjectList[OBJID_ENEMY][EnemyCount]->SetPosition(
				4.0f, 17.0f);
			break;
		case 2:
			ObjectList[OBJID_ENEMY][EnemyCount]->SetPosition(
				4.0f, 27.0f);
			break;
		}
	}
	else
	{
		switch (Index)
		{
		case 0:
			ObjectList[OBJID_ENEMY][EnemyCount]->SetPosition(
				105.0f, 7.0f);
			break;
		case 1:
			ObjectList[OBJID_ENEMY][EnemyCount]->SetPosition(
				105.0f, 17.0f);
			break;
		case 2:
			ObjectList[OBJID_ENEMY][EnemyCount]->SetPosition(
				105.0f, 27.0f);
			break;
		}
	}

	ObjectList[OBJID_ENEMY][EnemyCount]->SetActive(true);
	++EnemyCount;
}


void ObjectManager::FireBullet(int _index)
{
	for (int i = 0; i < 128; ++i)
	{
		if (!ObjectList[_index][i]->GetActive())
		{
			ObjectList[_index][i]->SetActive(true);

			ObjectList[_index][i]->SetPosition(
				pPlayer->GetPosition().x + 6,
				pPlayer->GetPosition().y - 2);

			break;
		}
	}
}


void ObjectManager::AddObject(Object* _object)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_object->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> TempList;

		TempList.push_back(_object);

		ObjectList.insert(make_pair(_object->GetKey(), TempList));
	}
	else
	{
		iter->second.push_back(_object);
	}
}




