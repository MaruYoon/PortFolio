#include "Room.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "TopPlayer.h"

Room::Room()
{
}

Room::~Room()
{
}

void Room::Initialize()
{

	strKey = "Room";

	for (int y = 0; y < 25; ++y)
	{
		for (int x = 0; x < 46; ++x)
		{
			switch (Array[y][x])
			{
			case 0:
				Texture[y][x] = (char*)"　";
				break;
			case 1:
				Texture[y][x] = (char*)"▨";
				break;
			case 2:
				Texture[y][x] = (char*)"[=";
				break;
			case 3:
				Texture[y][x] = (char*)"=]";
				break;
			case 4:
				Texture[y][x] = (char*)"==";
				break;
			}

			Tilemap[y][x] = Vector3(x * 2, y);

		}
	}

	/*
	Texture[0] = (char*) "▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨[========]▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨";
	Texture[1] = (char*) "▨                                                    ▨                        ▨";
	Texture[2] = (char*) "▨                                                                              ▨";
	Texture[3] = (char*) "▨                                                                              ▨";
	Texture[4] = (char*) "▨                                                                              ▨";
	Texture[5] = (char*) "▨                                                    ▨                        ▨";
	Texture[6] = (char*) "▨                                                    ▨                        ▨";
	Texture[7] = (char*) "▨                                                    ▨▨▨▨▨▨▨▨▨▨▨▨▨▨";
	Texture[8] = (char*) "▨                                                                              ▨";
	Texture[9] = (char*) "▨                                                                              ▨";
	Texture[10] = (char*)"▨                                                                              ▨";
	Texture[11] = (char*)"▨                                                                              ▨";
	Texture[12] = (char*)"▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨         ▨▨▨▨▨▨         ▨▨▨▨▨▨▨▨▨▨▨";
	Texture[13] = (char*)"▨                                           ▨                                 ▨";
	Texture[14] = (char*)"▨                                           ▨                                 ▨";
	Texture[15] = (char*)"▨                                           ▨                                 ▨";
	Texture[16] = (char*)"▨                                           ▨                                 ▨";
	Texture[17] = (char*)"▨                                           ▨                                 ▨";
	Texture[18] = (char*)"▨                                           ▨                                 ▨";
	Texture[19] = (char*)"▨                                           ▨                                 ▨";
	Texture[20] = (char*)"▨                                           ▨                                 ▨";
	Texture[21] = (char*)"▨                                           ▨                                 ▨";
	Texture[22] = (char*)"▨                                           ▨                                 ▨";
	Texture[23] = (char*)"▨                                           ▨                                 ▨";
	Texture[24] = (char*)"▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨";
	*/

	TransInfo.Position = Vector3(23.0f, 15.0f);
	TransInfo.Scale = Vector3(46.0f, 25.0f);

	//ctrl+h = 패턴을 바꾸는 기능, 단 선택영역을 지정하지 않으면 파일안의 모든 모양이 지정된다. 
	//도구 - 옵션 - 텍스트편집기 - C/C++ - 스크롤 화면보기

}

int Room::Update()
{
	Transform* pTransPos = ObjectManager::Getinstance()->GetTopPlayer();
	
	int iX = (int)pTransPos->Position.x;
	int iY = (int)pTransPos->Position.y;

	Vector3 TempPos = Vector3(iX, iY);


	ULONG ulKey = InputManager::Getinstance()->GetKey();

	if (ulKey & KEYID_W)
		pTransPos->Position.y--;
	
	if (ulKey & KEYID_S)
		pTransPos->Position.y++;
	
	if (ulKey & KEYID_A)
		pTransPos->Position.x--;
	
	if (ulKey & KEYID_D)
		pTransPos->Position.x++;


	if (ObjectManager::Getinstance()->GetCheckInRoom())
	{
		for (int y = 0; y < 25; ++y)
		{
			for (int x = 0; x < 46; ++x)
			{
				if (Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x / 2) - 1] == 1 ||
					Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x / 2)]  == 1||
					Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x / 2) + 1] == 1||

					Array[(int)pTransPos->Position.y][int(pTransPos->Position.x / 2) - 1] == 1 ||
					Array[(int)pTransPos->Position.y][int(pTransPos->Position.x / 2) + 1] == 1||

					Array[(int)pTransPos->Position.y + 1][int(pTransPos->Position.x / 2) - 1] == 1 ||
					Array[(int)pTransPos->Position.y + 1][int(pTransPos->Position.x / 2)] == 1||
					Array[(int)pTransPos->Position.y + 1][int(pTransPos->Position.x / 2) + 1] == 1)

					pTransPos->Position = TempPos;

				if (Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x / 2) - 1] == 4 ||
					//Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x / 2)] == 4 ||
					Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x / 2) + 1] == 4)
				{
					if (GetAsyncKeyState('W'))
						ObjectManager::Getinstance()->SetCheckInRoom(false);
				}
			}
		}
	}

	//DoubleBuffer::GetInstance()->WriteBuffer(100, 15, Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x/2) - 1]);
	//DoubleBuffer::GetInstance()->WriteBuffer(105, 15, Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x/2)]);
	//DoubleBuffer::GetInstance()->WriteBuffer(110, 15, Array[(int)pTransPos->Position.y - 1][int(pTransPos->Position.x/2) + 1]);
	//
	//DoubleBuffer::GetInstance()->WriteBuffer(100, 16, Array[(int)pTransPos->Position.y][int(pTransPos->Position.x/2) - 1]);
	//DoubleBuffer::GetInstance()->WriteBuffer(105, 16, Array[(int)pTransPos->Position.y][int(pTransPos->Position.x/2)]);
	//DoubleBuffer::GetInstance()->WriteBuffer(110, 16, Array[(int)pTransPos->Position.y][int(pTransPos->Position.x/2) + 1]);
	//
	//DoubleBuffer::GetInstance()->WriteBuffer(100, 17, Array[(int)pTransPos->Position.y + 1][int(pTransPos->Position.x/2) - 1]);
	//DoubleBuffer::GetInstance()->WriteBuffer(105, 17, Array[(int)pTransPos->Position.y + 1][int(pTransPos->Position.x/2)]);
	//DoubleBuffer::GetInstance()->WriteBuffer(110, 17, Array[(int)pTransPos->Position.y + 1][int(pTransPos->Position.x/2) + 1]);


	/*
	for (int i = 0 ; i < 3; i++)
	{
		for (int j = 0 ; j < 3; j++)
		{
			DoubleBuffer::GetInstance()->WriteBuffer(
				110, 15, Array[(int)pTransPos->Position.y - 1][(int)pTransPos->Position.x + 1]);
		}
	}
	*/


	return 0;
}

void Room::Render()
{
	for (int y = 0; y < 25; ++y)
	{
		for (int x = 0; x < 46; ++x)
		{
			DoubleBuffer::GetInstance()->WriteBuffer(
				Tilemap[y][x].x,
				Tilemap[y][x].y,
				Texture[y][x]);
		}

		/*
	if (GetAsyncKeyState(VK_TAB))
	{
		for (int y = 0; y < 25; ++y)
		{
			for (int x = 0; x < 46; ++x)
			{
				DoubleBuffer::GetInstance()->WriteBuffer(
					Tilemap[y][x].x,
					Tilemap[y][x].y,
					Texture[y][x]);
			}
		}
	}
	else
	{
		for (int y = 0; y < 25; ++y)
		{
			for (int x = 0; x < 46; ++x)
			{
				DoubleBuffer::GetInstance()->WriteBuffer(
					x * 2,
					y, 
					Array[y][x]);
			}
		}
		for (int y = 0; y < 25; ++y)
		{
			for (int x = 0; x < 46; ++x)
			{
				DoubleBuffer::GetInstance()->WriteBuffer(
					int(TransInfo.Position.x + (x * 2)) - (TransInfo.Scale.x / 2),
					int(TransInfo.Position.y + y) - (TransInfo.Scale.y / 2),
					Array[y][x]);
			}
		}
		*/

	}
}

void Room::Release()
{
}

