#include "TopPlayer.h"
#include "InputManager.h"
#include "DoubleBuffer.h"
#include "CollisionManager.h"

#include "Room.h"

TopPlayer::TopPlayer()
{
}

TopPlayer::~TopPlayer()
{
}

void TopPlayer::Initialize()
{

	Texture[0][0][0] = (char*)"∩";
	Texture[0][0][1] = (char*)"  ∩";
	Texture[0][0][2] = (char*)"";

	Texture[0][1][0] = (char*)"  ∩";
	Texture[0][1][1] = (char*)"∩";
	Texture[0][1][2] = (char*)"";


	Texture[1][0][0] = (char*)"";
	Texture[1][0][1] = (char*)"∪";
	Texture[1][0][2] = (char*)"  ∪";

	Texture[1][1][0] = (char*)"";
	Texture[1][1][1] = (char*)"  ∪";
	Texture[1][1][2] = (char*)"∪";
	

	Texture[2][0][0] = (char*)"⊃";
	Texture[2][0][1] = (char*)"  ⊃";
	Texture[2][0][2] = (char*)"";
			
	Texture[2][1][0] = (char*)"  ⊃";
	Texture[2][1][1] = (char*)"⊃";
	Texture[2][1][2] = (char*)"";


	Texture[3][0][0] = (char*)"⊂";
	Texture[3][0][1] = (char*)"  ⊂";
	Texture[3][0][2] = (char*)"";
			
	Texture[3][1][0] = (char*)"  ⊂";
	Texture[3][1][1] = (char*)"⊂";
	Texture[3][1][2] = (char*)"";



	TransInfo.Position = Vector3(48.0f, 2.0f);
	TransInfo.Scale = Vector3((float)strlen("  ∪⊃"), 3.0f);
	Horizontal = 0;
	Motion = 0;
}

int TopPlayer::Update()
{
	_CheckKey();

	return 0;
}

void TopPlayer::Render()
{
	for (int i = 0; i < 3; ++i)
	{
		GETSINGLETON(DoubleBuffer)->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)) + 1,
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2)) + i + 1,
			Texture[Horizontal][Motion][i]);

		/*
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)) + 1,
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2)) + i + 1,
			Texture[Horizontal][Motion][i]);
		*/
	}
}

void TopPlayer::Release()
{
}

void TopPlayer::_CheckKey()
{
	//ULONG ulKey = InputManager::Getinstance()->GetKey();

	ULONG ulKey = GETSINGLETON(InputManager)->GetKey();

	if (ulKey & KEYID_W)
	{
		Horizontal = 0;
		Motion++;
	}

	if (ulKey & KEYID_S)
	{
		Horizontal = 1;
		Motion++;
	}

	if (ulKey & KEYID_D)
	{
		Horizontal = 2;
		Motion++;
	}

	if (ulKey & KEYID_A)
	{
		Horizontal = 3;
		Motion++;
	}

	if (Motion >= 2)
		Motion = 0;
}