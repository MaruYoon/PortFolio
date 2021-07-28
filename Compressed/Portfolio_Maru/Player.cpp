#include "Player.h"
#include "InputManager.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"
#include "CollisionManager.h"

#include "Bullet.h"



Player::Player()
{
}

Player::~Player()
{
	Release();
}

void Player::Initialize()
{
	//** Texture[2][4][3];
	
	strKey = "Player";

	//우로 이동
	//멈춤 상태
   Texture[0][0][0] = (char*)"  ○";
   Texture[0][0][1] = (char*)"／|＼";
   Texture[0][0][2] = (char*)"／ |";

   //동작 형태
   Texture[0][1][0] = (char*)"  ○";
   Texture[0][1][1] = (char*)"／|＼";
   Texture[0][1][2] = (char*)" > )";
   
   Texture[0][2][0] = (char*)"   ○";
   Texture[0][2][1] = (char*)" ／|＼";
   Texture[0][2][2] = (char*)" ＼>";
   
   Texture[0][3][0] = (char*)"  ○";
   Texture[0][3][1] = (char*)"／|＼";
   Texture[0][3][2] = (char*)" )＼";



   //좌로 이동
   //멈춤 상태
   Texture[1][0][0] = (char*)" ○";
   Texture[1][0][1] = (char*)"／|＼";
   Texture[1][0][2] = (char*)" | ＼";

   //동작 형태
   Texture[1][1][0] = (char*)" ○";
   Texture[1][1][1] = (char*)"／|＼";
   Texture[1][1][2] = (char*)" ( <";
   
   Texture[1][2][0] = (char*)" ○";
   Texture[1][2][1] = (char*)"／|＼";
   Texture[1][2][2] = (char*)" <／";
   
   Texture[1][3][0] = (char*)" ○";
   Texture[1][3][1] = (char*)"／|＼";
   Texture[1][3][2] = (char*)"／(";


   //공격모션
   Texture[2][0][0] = (char*)" ○)";
   Texture[2][0][1] = (char*)"／|";
   Texture[2][0][2] = (char*)"／ |";

   Texture[2][1][0] = (char*)"  ○";
   Texture[2][1][1] = (char*)"／|￣";
   Texture[2][1][2] = (char*)"／ |";

   Texture[2][2][0] = (char*)"  ○";
   Texture[2][2][1] = (char*)"／|￣";
   Texture[2][2][2] = (char*)"／ |";
   
   Texture[2][3][0] = (char*)" ○)";
   Texture[2][3][1] = (char*)"／|";
   Texture[2][3][2] = (char*)"／ |";

   //공격모션
   Texture[3][0][0] = (char*)" ○";
   Texture[3][0][1] = (char*)"／|＼";
   Texture[3][0][2] = (char*)" | ＼";

   Texture[3][1][0] = (char*)" (○";
   Texture[3][1][1] = (char*)"  |＼";
   Texture[3][1][2] = (char*)" | ＼";

   Texture[3][2][0] = (char*)" ○";
   Texture[3][2][1] = (char*)"￣|＼";
   Texture[3][2][2] = (char*)" | ＼";

   Texture[3][3][0] = (char*)" ○";
   Texture[3][3][1] = (char*)"￣|＼";
   Texture[3][3][2] = (char*)" | ＼";


   TransInfo.Position = Vector3(60.0f, 7.0f);
   TransInfo.Scale = Vector3((float)strlen("／|＼"), 3.0f);


   Horizontal = 0;
   Motion = 0;
   RoomIndex = 0;

   CheckRoom = 0;

}

int Player::Update()
{
	CheckKey();

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 3; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
			Texture[Horizontal][Motion][i]);
	}
}

void Player::CheckKey()
{
	ULONG ulKey = InputManager::Getinstance()->GetKey();

	if (ulKey & KEYID_LEFT)
	{
		TransInfo.Position.x--;
		Horizontal = 1;
		Motion++;
	}

	if (ulKey & KEYID_RIGHT)
	{
		TransInfo.Position.x++;
		Horizontal = 0;
		Motion++;
	}


	if (ulKey & KEYID_CONTROL)
	{
		if (Horizontal == 0)
		{
			TransInfo.Position.x += 10.0f;
		}

		else if (Horizontal == 1)
		{
			TransInfo.Position.x -= 10.0f;
		}
	}

	
	if (Motion >= 4)
		Motion = 0;

#ifdef EDITMODE
	for (int i = 0; i < 3; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(2, 1, (int)TransInfo.Position.x);
		DoubleBuffer::GetInstance()->WriteBuffer(7, 1, (int)TransInfo.Position.y);
	}
#endif
}

void Player::Release()
{
}


