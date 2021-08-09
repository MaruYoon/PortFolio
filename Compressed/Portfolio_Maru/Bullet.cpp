#include "Bullet.h"
#include "DoubleBuffer.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
	Release();
}

void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("*"), 1.0f);

	Active = false;
}

int Bullet::Update()
{
	TransInfo.Position.x += 3.0f;

	if (TransInfo.Position.x >= (120.0f - TransInfo.Scale.x))
	{
		return 1;
	}
	return 0;

}

void Bullet::Render()
{
	GETSINGLETON(DoubleBuffer)->WriteBuffer()

	DoubleBuffer::GetInstance()->WriteBuffer(
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)+1),
		(char*)"*");

}

void Bullet::Release()
{
}

