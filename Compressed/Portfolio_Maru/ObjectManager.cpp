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


//ObjectManager* ObjectManager::m_pinstance = NULL;


ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::Initialize()
{
	/*
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
	*/

	/*
	for (int i = 0; i < 128; ++i)
	{
		ObjectList[OBJID_ENEMY][i] = ObjectFactory<Enemy>::CreateObject();
		ObjectList[OBJID_BULLET][i] = ObjectFactory<Bullet>::CreateObject();
	}
	*/

	//스테이지1.
	AddObject(ObjectFactory<BackGround>::CreateObject());

	//pBackGround = ObjectManager::Getinstance().

	//스테이지2.
	for (int i = 0; i < 9; ++i)
	{
		AddObject(ObjectFactory<Room>::CreateObject());
	}

	for (int i = 0; i < 9; ++i)
	{
		AddObject(ObjectFactory<Door>::CreateObject());
	}

	//탑플레이어
	AddObject(ObjectFactory<TopPlayer>::CreateObject());

	//아이템
	AddObject(ObjectFactory<Item>::CreateObject());

	//미션창
	AddObject(ObjectFactory<CheckMission>::CreateObject());

	CreatDoor();
	CreatExit();

	//적
	for (int i = 0; i < 128; ++i)
	{
		AddObject(ObjectFactory<Enemy>::CreateObject());
	}

	EnemyCount = 0;
	CheckInRoom = false;
	_CheckMission = false;

	CreateEnemy();

}

void ObjectManager::Update()
{

	/*
	for (int i = 0; i < OBJID_MAX; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			int iResult = 0;

			if(!CheckInRoom)
				if (ObjectList[i][j])->GetActive())
					iResult = ObjectList[i][j]->Update();

			if (iResult == 1)
				ObjectList[i][j]->SetActive(false);

			if (iResult == -1)
				--EnemyCount;
		}
	}

	for (int i = 0; i < 128; ++i)
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

	//list<Object*>::iterator iterEnemy = (*ObjectList.find("Enemy")).second.begin();

	/*

	//1
	//이렇게 찾으려고 한다면
	map<string, list<Object*>>::iterator iterEnemy = ObjectList.find("Enemy");
	map<string, list<Object*>>::iterator iterPlayer = ObjectList.find("Player");


	//아래의 내용처럼 조건이 갖추어져 있어야 한다.
	if (iterEnemy == ObjectList.end())
		return;

	if (iterPlayer == ObjectList.end())
		return;


	아니라면 GetObjectList같은 함수를 생성하여 사용하는 것이 좋다. 
	이 방법이 가장 효율적인 방법

	list<Object*>* pEnemyList = GetObjectList("Enemy");
	list<Object*>* pPlayerList = GetObjectList("Player");
	list<Object*>* pDoor = GetObjectList("Door");

	*/

	/*
	if (pEnemyList)
	{
		pEnemyList->front();
	}
	if (pPlayerList)
	{
		pPlayerList->front();
	}
	*/

	/*
	
	//2
	list<Object*>::iterator iterPlayer = (*ObjectList.find("Player")).second.begin();

	//3
	list<Object*>::iterator iterEnemy =  GetObjectList("Enemy")->begin();

	//4
	Enemy* pEnemy;
	list<Object*>::iterator iterEnemy = (*ObjectList.find(pEnemy->GetKey())).second.begin();

	(*iterEnemy)->GetTransform();

	*/

    //list<Object*>* pEnemyList = GetObjectList("Enemy");
    //list<Object*>* pPlayerList = GetObjectList("Player");
	//list<Object*>* pDoorList = GetObjectList("Door");
	//list<Object*>* pExitList = GetObjectList("Exit");
	//list<Object*>* pTopPlayerList = GetObjectList("TopPlayer");
	//list<Object*>* pItemList = GetObjectList("Item");
	//list<Object*>* pRoomList = GetObjectList("Room");
	//list<Object*>* pCheckMissionList = GetObjectList("CheckMission");

	for (int i = 0; i < 128; ++i)
	{
		if (pEnemyList&&pPlayerList)
		{
			pEnemyList->front();
			pPlayerList->front();

			if ((pEnemyList)->front()->GetActive())
			{
				if (CollisionManager::CollisionRact(
					*(pEnemyList)->front()->GetTransform(), *(pPlayerList)->front()->GetTransform()))
				{
					if (GetAsyncKeyState(VK_CONTROL))
					{
						break;
					}
					else
					{
						GETSINGLETON(SceneManager)->SetScene(SCENEID_EXIT);
						//SceneManager::Getinstance()->SetScene(SCENEID_EXIT);
					}
					(pEnemyList)->front()->SetActive(false);
				}
			}
		}
	}

	//ULONG ulKey = InputManager::Getinstance()->GetKey();
	ULONG ulKey = GETSINGLETON(InputManager)->GetKey();

	for (int i = 0; i < 9; ++i)
	{
		if (pDoorList && pTopPlayerList && pItemList && pPlayerList)
		{
			pDoorList->front();
			pTopPlayerList->front();
			pItemList->front();
			pPlayerList->front();

			if (CollisionManager::CollisionRact(
				*(pDoorList)->front()->GetTransform(), *(pPlayerList)->front()->GetTransform()))
			{
				if (ulKey & KEYID_UP)
				{
					CheckInRoom = true;
					RoomIndex = i;

					(pTopPlayerList)->front()->Initialize();
					(pItemList)->front()->Initialize();
				}
			}
		}
	}
	
	/*
	map<string, list<Object*>>::iterator iter = ObjectList.find("Enemy");

	if (iter == ObjectList.end())
		return;
	*/
	
	//find로 키값을 받아 온다고 해도 저 Enemy가 우리가 찾을 Enemy의 키값이라고 장담할수 없다.
	//Enmey의 키값을 GetKey로 받아와야 한다.
	
	if (pRoomList)
		pRoomList->front();

	if (CheckInRoom)
	{
		(pRoomList)->front()->Update();
		(pItemList)->front()->Update();
		(pTopPlayerList)->front()->Update();

		//InRoom[RoomIndex]->Update();
		//Initem->Update();
		//pTopPlayer->Update();
	} 

	else
	{
		(pPlayerList)->front()->Update();
		//pPlayer->Update();
	}

	if (pExitList && pCheckMissionList)
	{
		pExitList->front();
		pCheckMissionList->front();
	}

	for (int i = 0; i < 3; ++i)
	{
		if (CollisionManager::CollisionRact(
			*(pExitList)->front()->GetTransform(),
			*(pPlayerList)->front()->GetTransform()))
		{
			if (ulKey & KEYID_DOWN)
			{
				if (pPlayerList->front()->GetPosition().y < 27.0f)
				{
					(pPlayerList)->front()->SetPosition(
						(pPlayerList)->front()->GetPosition().x,
						(pPlayerList)->front()->GetPosition().y + 10.0f);

					break;
				}

				else
					break;

			}

			if (ulKey & KEYID_UP)
			{
				if ((pPlayerList)->front()->GetPosition().y > 7.0f)
				{
					(pPlayerList)->front()->SetPosition(
						(pPlayerList)->front()->GetPosition().x,
						(pPlayerList)->front()->GetPosition().y - 10.0f);

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
		(pCheckMissionList)->front()->Initialize();
	}
	if (_CheckMission)
	{
		(pCheckMissionList)->front()->Update();
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

	//list<Object*>* pCheckMissionList = GetObjectList("CheckMission");
	//list<Object*>* pRoomList = GetObjectList("Room");
	//list<Object*>* pBackGroundList = GetObjectList("BackGround");
	//list<Object*>* pDoorList = GetObjectList("Door");
	//list<Object*>* pExitList = GetObjectList("Exit");
	//list<Object*>* pPlayerList = GetObjectList("Player");

	if (CheckInRoom)
	{
		pRoomList->front()->Render();
		//InRoom[RoomIndex]->Render();  
	}

	else if (_CheckMission)
	{
		(pCheckMissionList)->front()->Render();
	}

	else
	{
		pBackGroundList->front()->Render();

		for (int i = 0; i < 9; ++i)
			pDoorList->front()->Render();

		for (int i = 0; i < 3; ++i)
			pExitList->front()->Render();


		pPlayerList->front()->Render();
		//pPlayer->Render();

		for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
			iter != ObjectList.end(); ++iter)
		{
			for (list<Object*>::iterator iter2 = iter->second.begin();
				iter2 != iter->second.end(); ++iter2)
			{
				if ((*iter2)->GetActive())
					(*iter2)->Render();
			}
		}


		/*
		for (int i = 0; i < OBJID_MAX; ++i)
		{
			for (int j = 0; j < 128; ++j)
			{
				if (ObjectList[i][j]->GetActive())
					ObjectList[i][j]->Render();
			}
		}
		*/
	}

#endif
}

void ObjectManager::Release()
{

	SAFE_RELEASE(pPlayerList);


	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			SAFE_RELEASE(*iter2);
		}
	}

	//for (int i = 0; i < OBJID_MAX; ++i)
	//	for (int j = 0; j < 128; ++j)
	//		SAFE_RELEASE(ObjectList[i][j]);

}

void ObjectManager::CreatDoor()
{
	//객실문
	for (int i = 0; i < 3; ++i)
	{
		Object* pDoor1 = ObjectFactory<Door>::CreateObject(12.0f, 8.0f + (i * 10));
		((Door*)pDoor1)->SetIndex(i * 3 + 1);
		AddObject(pDoor1);


		Object* pDoor2 = ObjectFactory<Door>::CreateObject(42.0f, 8.0f + (i * 10));
		((Door*)pDoor2)->SetIndex(i * 3 + 2);
		AddObject(pDoor2);


		Object* pDoor3 = ObjectFactory<Door>::CreateObject(72.0f, 8.0f + (i * 10));
		((Door*)pDoor3)->SetIndex(i * 3 + 3);
		AddObject(pDoor3);
	}
}

void ObjectManager::CreatExit()
{
	//비상계단
	for (int i = 0; i < 3; ++i)
		AddObject(ObjectFactory<Exit>::CreateObject(105.0f, 8.0f + (i * 10) ) );
}

void ObjectManager::CreateEnemy()
{
	int Index = EnemyCount % 3;
	// Index = 0,1,2
	int Horizontal = rand() % 2;
	//horizontal = 0,1

	Enemy* pEnemy;


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

/*
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
*/

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

//
// 
//template <typename T>
//void ObjectManager::InsertList(const int& _count, const string& _strKey)
//{
//	list<Object*> pTempList;
//
//	for (int i = 0; i < _count; ++i)
//	{
//		Object* pObject = ObjectFactory<T>::CreateObject();
//		pTempList.push_back(pObject);
//	}
//
//	ObjectList.insert(make_pair(_strKey, pTempList));
// 
// if()
//}

Transform* ObjectManager::GetTopPlayer()
{
	return pTopPlayerList->front()->GetTransform();
}

void ObjectManager::FindObject()
{
	list<Object*>* pEnemyList = GetObjectList("Enemy");
	list<Object*>* pPlayerList = GetObjectList("Player");
	list<Object*>* pDoorList = GetObjectList("Door");
	list<Object*>* pExitList = GetObjectList("Exit");
	list<Object*>* pTopPlayerList = GetObjectList("TopPlayer");
	list<Object*>* pItemList = GetObjectList("Item");
	list<Object*>* pRoomList = GetObjectList("Room");
	list<Object*>* pCheckMissionList = GetObjectList("CheckMission");
}


