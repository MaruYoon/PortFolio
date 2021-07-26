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

	Object* pPlayer;
	Object* pTopPlayer;

	Object* pCheckMission;
	Object* pBackGround;
	Object* Initem;

	Object* ObjectList[OBJID_MAX][128];

    Object* InRoom[9];
	Object* BackDoor[9];
	Object* BackExit[3];

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
    void FireBullet(int _index);

	

private:
	ObjectManager();
public:
	~ObjectManager();


};

