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


	GETSINGLETON(DoubleBuffer)->WriteBuffer(
		0, 8,
		(char*)"ΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙ");

	GETSINGLETON(DoubleBuffer)->WriteBuffer(
		0, 18,
		(char*)"ΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙ");

	GETSINGLETON(DoubleBuffer)->WriteBuffer(
		0, 28,
		(char*)"ΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙ");


	/*
	DoubleBuffer::GetInstance()->WriteBuffer(
		0, 8,
		(char*)"ΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙ");

	DoubleBuffer::GetInstance()->WriteBuffer(
		0, 18,
		(char*)"ΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙ");

	DoubleBuffer::GetInstance()->WriteBuffer(
		0, 28,
		(char*)"ΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙΆΙ");
	*/



}

void BackGround::Release()
{
}

