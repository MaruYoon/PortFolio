#include "Enemy.h"
#include "DoubleBuffer.h"


Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	strKey = "Enemy";
	
	Texture[0][0][0] = (char*)" __{ )";
	Texture[0][0][1] = (char*)"' '￣)";
	Texture[0][0][2] = (char*)"   / |";

	Texture[0][1][0] = (char*)" __{ )";
	Texture[0][1][1] = (char*)"' '￣)";
	Texture[0][1][2] = (char*)"   < (";

	Texture[0][2][0] = (char*)" __{ )";
	Texture[0][2][1] = (char*)"' '￣)";
	Texture[0][2][2] = (char*)"   ( V";


	Texture[1][0][0] = (char*)"( }__";
	Texture[1][0][1] = (char*)"( ￣''";
	Texture[1][0][2] = (char*)"| ＼";

	Texture[1][1][0] = (char*)"( }__";
	Texture[1][1][1] = (char*)"( ￣''";
	Texture[1][1][2] = (char*)") >";

	Texture[1][2][0] = (char*)"( }__";
	Texture[1][2][1] = (char*)"( ￣''";
	Texture[1][2][2] = (char*)"V )";

	//[2][3][3]
	//[다른 방향을 가진 동작들] [세부 동작들 순서] [하나의 동작이 가진 배열의 수]

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("' '￣)"), 3.0f);

	Speed = 0.2f;
	Active = false;

	Horizontal = 0;
	Motion = 0;
	Index = 0;
}

int Enemy::Update()
{
	if (Horizontal == 0)
		TransInfo.Position.x -= Speed;
	else
		TransInfo.Position.x += Speed;

	
	if (TransInfo.Position.x <= 2 || 
		(TransInfo.Position.x + TransInfo.Scale.x) >= 119 )
	{
		Horizontal = !Horizontal;
	}

	Motion++;

	if (Motion >= 2)
		Motion = 0;

	return 0;
}

void Enemy::Render()
{
	for (int i = 0; i < 3; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
			Texture[Horizontal][Motion][i]);
	}
}

void Enemy::Release()
{
}

