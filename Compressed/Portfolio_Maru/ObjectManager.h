#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* m_pinstance;
public:
	static ObjectManager* Getinstance()
	{
		if (m_pinstance == NULL)
			m_pinstance = new ObjectManager;

		return m_pinstance;
	}

private:


	/*
	Object* pPlayer;
	Object* pTopPlayer;

	Object* pCheckMission;
	Object* pBackGround;
	Object* Initem;

    Object* InRoom;
	Object* BackDoor;
	Object* BackExit;
	*/

	map<string, list<Object*>> ObjectList;


	//Object* ObjectList[OBJID_MAX][128];
	/*
	Object* InRoom[9];
	Object* BackDoor[9];
	Object* BackExit[3];
	*/


	int EnemyCount;
	bool CheckInRoom;
	bool CheckFloor;
	bool _CheckMission;

	int RoomIndex;

public:
	void SetPlayer(Object* _Player) { pPlayer = _Player; }

	bool GetCheckInRoom() const { return CheckInRoom; }
	void SetCheckInRoom(const bool& _CheckInRoom) { CheckInRoom = _CheckInRoom; }


	bool GetCheckMission() const { return _CheckMission; }
	void SetCheckMission(const bool& m_CheckMission) { _CheckMission = m_CheckMission; }

	/*
	template <typename T>
	void InsertList(const int& _count, const string& _strKey);
	*/

	list<Object*>*GetObjectList(string _strKey)
	{
		map<string, list<Object*>>::iterator iter = ObjectList.find(_strKey);

		if (iter == ObjectList.end())
			return NULL;

	}

	//지정주석 처리 ctrl + k + C
	//지정주석 해제 ctrl + k + U

	//이름 바꾸기 ctrl + r+ r
	//alt 선택 


	Object* GetBackDoor(const int& _index) 
	{ 
		if (_index > 8)
			return nullptr;
			
		return BackDoor[_index]; 
	}

	Transform* GetTopPlayer();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

public:
	void CreatDoor();
	void CreatExit();
	void CreateEnemy();
    //void FireBullet(int _index);
	void AddObject(Object* _object);
	void FindObject();
 
public:
	list<Object*>* pEnemyList = GetObjectList("Enemy");
	list<Object*>* pPlayerList = GetObjectList("Player");
	list<Object*>* pDoorList = GetObjectList("Door");
	list<Object*>* pExitList = GetObjectList("Exit");
	list<Object*>* pTopPlayerList = GetObjectList("TopPlayer");
	list<Object*>* pItemList = GetObjectList("Item");
	list<Object*>* pRoomList = GetObjectList("Room");
	list<Object*>* pCheckMissionList = GetObjectList("CheckMission");
	list<Object*>* pBackGroundList = GetObjectList("BackGround");



private:
	ObjectManager();
public:
	~ObjectManager();


};

