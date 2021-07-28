#include "Item.h"
#include "DoubleBuffer.h"
#include "CollisionManager.h"
#include "TopPlayer.h"
#include "ObjectManager.h"

Item::Item()
{
}

Item::~Item()
{
	Release();
}

void Item::Initialize()
{
	
	strKey = "Item";

	 Texture[0] = (char*)"  ";

	 /*
	 */
	 
	 _Item[0][0][0] = (char*)"      ";
	 _Item[0][0][1] = (char*)"  ㆍ  ";
	 _Item[0][0][2] = (char*)"      ";

	 _Item[0][1][0] = (char*)"      ";
	 _Item[0][1][1] = (char*)"  ∴  ";
	 _Item[0][1][2] = (char*)"      ";

	 _Item[0][2][0] = (char*)"ㆍ  ㆍ";
	 _Item[0][2][1] = (char*)"  ⊙  ";
	 _Item[0][2][2] = (char*)"ㆍ  ㆍ";

	 _Item[0][3][0] = (char*)"";
	 _Item[0][3][1] = (char*)"  ♣  ";
	 _Item[0][3][2] = (char*)"";



	 _Item[1][0][0] = (char*)"      ";
	 _Item[1][0][1] = (char*)"  ㆍ  ";
	 _Item[1][0][2] = (char*)"      ";
		   
	 _Item[1][1][0] = (char*)"      ";
	 _Item[1][1][1] = (char*)"  ∴  ";
	 _Item[1][1][2] = (char*)"      ";
		   
	 _Item[1][2][0] = (char*)"ㆍ  ㆍ";
	 _Item[1][2][1] = (char*)"  ⊙  ";
	 _Item[1][2][2] = (char*)"ㆍ  ㆍ";
		   
	 _Item[1][3][0] = (char*)"";
	 _Item[1][3][1] = (char*)"  ★  ";
	 _Item[1][3][2] = (char*)"";



	 _Item[2][0][0] = (char*)"      ";
	 _Item[2][0][1] = (char*)"  ㆍ  ";
	 _Item[2][0][2] = (char*)"      ";
		   
	 _Item[2][1][0] = (char*)"      ";
	 _Item[2][1][1] = (char*)"  ∴  ";
	 _Item[2][1][2] = (char*)"      ";
		   
	 _Item[2][2][0] = (char*)"ㆍ  ㆍ";
	 _Item[2][2][1] = (char*)"  ⊙  ";
	 _Item[2][2][2] = (char*)"ㆍ  ㆍ";
		   
	 _Item[2][3][0] = (char*)"";
	 _Item[2][3][1] = (char*)"  ●  ";
	 _Item[2][3][2] = (char*)"";
	 


	 _Item[3][0][0] = (char*)"      ";
	 _Item[3][0][1] = (char*)"  ㆍ  ";
	 _Item[3][0][2] = (char*)"      ";
		   
	 _Item[3][1][0] = (char*)"      ";
	 _Item[3][1][1] = (char*)"  ∴  ";
	 _Item[3][1][2] = (char*)"      ";
		   
	 _Item[3][2][0] = (char*)"ㆍ  ㆍ";
	 _Item[3][2][1] = (char*)"  ⊙  ";
	 _Item[3][2][2] = (char*)"ㆍ  ㆍ";
		   
	 _Item[3][3][0] = (char*)"";
	 _Item[3][3][1] = (char*)"  ◆  ";
	 _Item[3][3][2] = (char*)"";









	 /*
			  
	 _Item[1][0] = (char*)"ㆍ";
	 _Item[1][1] = (char*)"∴";
	 _Item[1][2] = (char*)"★";
			 
	 _Item[2][0] = (char*)"ㆍ";
	 _Item[2][1] = (char*)"∴";
	 _Item[2][2] = (char*)"●";
			 
	 _Item[3][0] = (char*)"ㆍ";
	 _Item[3][1] = (char*)"∴";
	 _Item[3][2] = (char*)"◆";



	 int i = 0;
	 
	 switch (rand() % 4 + 1)
	 {
	 case 0:
	 {
		 _Item[i][0] = (char*)"ㆍ";
		 _Item[i][1] = (char*)"∴";
		 _Item[i][2] = (char*)"♣";

		 break;
	 }

	 case 1:
	 {
		 _Item[i][0] = (char*)"ㆍ";
		 _Item[i][1] = (char*)"∴";
		 _Item[i][2] = (char*)"★";
		 
		 break;
	 }
		
	 case 2:
	 {
		 _Item[i][0] = (char*)"ㆍ";
		 _Item[i][1] = (char*)"∴";
		 _Item[i][2] = (char*)"●";

		 break;
	 }

	 case 3:
	 {
		 _Item[i][0] = (char*)"ㆍ";
		 _Item[i][1] = (char*)"∴";
		 _Item[i][2] = (char*)"◆";

		 break;
	 }

	 }
	 */

	 

	 if (ObjectManager::Getinstance()->GetCheckInRoom() == true)
	 {
		 switch (rand() % 3 + 1)
		 {
		 case 0:
			 TransInfo.Position = Vector3(60.0f, 22.0f);
			 break;

		 case 1:
			 TransInfo.Position = Vector3(30.0f, 22.0f);
			 break;

		 case 2:
			 TransInfo.Position = Vector3(77.0f, 6.0f);
			 break;
		 }
	 }
	

	 TransInfo.Scale = Vector3((float)strlen("  ♣  "), 3.0f);

	 Collision = false;
	 Horizontal = rand() % 3 + 1;
	 Motion = 0;

}

int Item::Update()
{
	if (CollisionManager::CollisionRact(*ObjectManager::Getinstance()->GetTopPlayer(), TransInfo))
	{
		Collision = true;


		if (GetAsyncKeyState('E'))
		{
			Collision = false;
		}


	}

	if (Collision)
	{
		if (Motion < 3)
			Motion++;
	}
	


	return 0;
}

void Item::Render()
{
	if (Collision)
	{
		for (int i = 0; i < 3; ++i)
		{
			DoubleBuffer::GetInstance()->WriteBuffer(
				int(TransInfo.Position.x - (TransInfo.Scale.x)),
				int(TransInfo.Position.y - (TransInfo.Scale.y)+i),
				_Item[Horizontal][Motion][i]);
		}

		

		//for (int i = 0; i < 4; ++i)
		//{
		//	DoubleBuffer::GetInstance()->WriteBuffer(
		//		int(TransInfo.Position.x - (TransInfo.Scale.x)),
		//		int(TransInfo.Position.y - (TransInfo.Scale.y)),
		//		_Item[i][Motion]);
		//}
		
	}
	else
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x)),
			int(TransInfo.Position.y - (TransInfo.Scale.y)),
			Texture[0]);
	}
}

void Item::Release()
{
	
}

