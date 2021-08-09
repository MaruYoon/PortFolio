#include "Door.h"
#include "DoubleBuffer.h"


Door::Door()
{
}

Door::~Door()
{
}

void Door::Initialize()
{

	Texture[0] = (char*)" _______ ";
	Texture[1] = (char*)"|       |";
	Texture[2] = (char*)"|       |";
	Texture[3] = (char*)"|       |";
	Texture[4] = (char*)"| o     |";
	Texture[5] = (char*)"|       |";
	Texture[6] = (char*)"|_______|";

	strKey = "Door";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("|       |")/2, 7.0f);
	
	Index = 0;
}

int Door::Update()
{
	return 0;
}

void Door::Render()
{
	for (int i = 0; i < 7; ++i)
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
	GETSINGLETON(DoubleBuffer)->WriteBuffer(
		int(TransInfo.Position.x - 1),
		int(TransInfo.Position.y - 5),
		Index);

	/*
	DoubleBuffer::GetInstance()->WriteBuffer(
		int(TransInfo.Position.x - 1),
		int(TransInfo.Position.y - 5),
		Index);
	*/
}

void Door::Release()
{
}
