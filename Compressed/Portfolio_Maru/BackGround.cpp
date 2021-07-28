#include "BackGround.h"
#include "DoubleBuffer.h"


BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void BackGround::Initialize()
{
	strKey = "BackGround";
}

int BackGround::Update()
{
	return 0;
}

void BackGround::Render()
{
	
	DoubleBuffer::GetInstance()->WriteBuffer(
		0, 8,
		(char*)"�ɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢ�");

	DoubleBuffer::GetInstance()->WriteBuffer(
		0, 18,
		(char*)"�ɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢ�");

	DoubleBuffer::GetInstance()->WriteBuffer(
		0, 28,
		(char*)"�ɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢɢ�");



}

void BackGround::Release()
{
}

