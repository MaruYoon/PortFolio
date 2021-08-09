#include "Exit.h"
#include "DoubleBuffer.h"

Exit::Exit()
{
}

Exit::~Exit()
{
}

void Exit::Initialize()
{
	Texture[0] = (char*)"      EXIT";
	Texture[1] = (char*)" _______________ ";
	Texture[2] = (char*)"|       |       |";
	Texture[3] = (char*)"|_______|       |";
	Texture[4] = (char*)"|_______|       |";
	Texture[5] = (char*)"|_______|       |";
	Texture[6] = (char*)"|_______|       |";
	Texture[7] = (char*)"|_______|_______|";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("|       |       |")/2, 8.0f);

	strKey = "Exit";
}

int Exit::Update()
{
	return 0;
}

void Exit::Render()
{
	for (int i = 0; i < 8; ++i)
	{
		GETSINGLETON(DoubleBuffer)->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x)),
			int(TransInfo.Position.y - (TransInfo.Scale.y) + i),
			Texture[i]);
		/*
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x)),
			int(TransInfo.Position.y - (TransInfo.Scale.y) + i),
			Texture[i]);
		*/
	}

}

void Exit::Release()
{
}

