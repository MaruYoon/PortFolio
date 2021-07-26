#include "Chapter00.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

Chapter00::Chapter00()
{
}

Chapter00::~Chapter00()
{
}

void Chapter00::Initialize()
{


	Trans[0].Texture = (char*)"+======================================================+";
	Trans[1].Texture = (char*)"|                                                      |";
	Trans[2].Texture = (char*)"|                                                      |";
	Trans[3].Texture = (char*)"|                                                      |";
	Trans[4].Texture = (char*)"|                                                      |";
	Trans[5].Texture = (char*)"|                                                      |";
	Trans[6].Texture = (char*)"|                                                      |";
	Trans[7].Texture = (char*)"+======================================================+";
	
	for (int i = 0; i < 8; ++i)
	{
		Trans[i].TransPos.Position = Vector3(32.0f, 18.0f);
	}




	pImage[0][0].Texture = (char*)"           _____";
	pImage[0][1].Texture = (char*)"          [IIIII]";
	pImage[0][2].Texture = (char*)"           )   (";
	pImage[0][3].Texture = (char*)"          /    ＼ ";
	pImage[0][4].Texture = (char*)"         /      ＼ ";
	pImage[0][5].Texture = (char*)"         |`-...-'|";
	pImage[0][6].Texture = (char*)"         |       |";
	pImage[0][7].Texture = (char*)"       _ |`-...-'j";
	pImage[0][8].Texture = (char*)"      (＼)`-.___.(I) _(/)";
	pImage[0][9].Texture = (char*)"        (I)  (/)(I)(＼)";
	pImage[0][10].Texture = (char*)"          (I)";


	pImage[1][0].Texture = (char*)"	        _.-/`) ";
	pImage[1][1].Texture = (char*)"             // / / ) ";
	pImage[1][2].Texture = (char*)"          .=// / / / )";
	pImage[1][3].Texture = (char*)"         // / / / / /";
	pImage[1][4].Texture = (char*)"        // /       /";
	pImage[1][5].Texture = (char*)"       ||         /";
	pImage[1][6].Texture = (char*)"        \\       / ";
	pImage[1][7].Texture = (char*)"         ))    .' ";
	pImage[1][8].Texture = (char*)"        //    / ";
	pImage[1][9].Texture = (char*)"       //    / ";
	pImage[1][10].Texture = (char*)"           / ";


	pImage[2][0].Texture = (char*)"      	 ___";
	pImage[2][1].Texture = (char*)"         '-.  |   |  .-' ";
	pImage[2][2].Texture = (char*)"           ___|   |___   ";
	pImage[2][3].Texture = (char*)"      -=  [           ]  =- ";
	pImage[2][4].Texture = (char*)"          `---.   .---'   ";
	pImage[2][5].Texture = (char*)"       __||__ |   | __||__ ";
	pImage[2][6].Texture = (char*)"       '-..-' |   | '-..-' ";
	pImage[2][7].Texture = (char*)"         ||   |   |   ||   ";
	pImage[2][8].Texture = (char*)"         ||_.-|   |-,_||   ";
	pImage[2][9].Texture = (char*)"       .- `   ` `'`   ` -_ ";
	pImage[2][10].Texture = (char*)"    .'                   '.";
   

	pImage[3][0].Texture = (char*)"      	 ___";
	pImage[3][1].Texture = (char*)"         '-.  |   |  .-' ";
	pImage[3][2].Texture = (char*)"           ___|   |___   ";
	pImage[3][3].Texture = (char*)"      -=  [           ]  =- ";
	pImage[3][4].Texture = (char*)"          `---.   .---'   ";
	pImage[3][5].Texture = (char*)"       __||__ |   | __||__ ";
	pImage[3][6].Texture = (char*)"       '-..-' |   | '-..-' ";
	pImage[3][7].Texture = (char*)"         ||   |   |   ||   ";
	pImage[3][8].Texture = (char*)"         ||_.-|   |-,_||   ";
	pImage[3][9].Texture = (char*)"       .- `   ` `'`   ` -_ ";
	pImage[3][10].Texture = (char*)"    .'                   '.";
   
	
	pImage[4][0].Texture = (char*)"               ___          /|";
	pImage[4][1].Texture = (char*)"  ||||     .-'`   `'-.     } | ";
	pImage[4][2].Texture = (char*)"  ||||   .'  .-'`'-.  '.   } | ";
	pImage[4][3].Texture = (char*)"  \  /  /  .'         '.  \  | ";
	pImage[4][4].Texture = (char*)"    ||  /  ;            ;  \ | ";
	pImage[4][5].Texture = (char*)"   ||  | ;             ; |  || ";
	pImage[4][6].Texture = (char*)"   %%  | ;             ; |  %% ";
	pImage[4][7].Texture = (char*)"   %%  \  ;            ;  /  %% ";
	pImage[4][8].Texture = (char*)"   %%   \  '.        .'  /   %% ";
	pImage[4][9].Texture = (char*)"   %%    '.  `-.,.-'  .'    %% ";
	pImage[4][10].Texture = (char*)"   %%      '-.,___,.-'      %% ";


	pImage[5][0].Texture = (char*)"               ___          /|";
	pImage[5][1].Texture = (char*)"  ||||     .-'`   `'-.     } | ";
	pImage[5][2].Texture = (char*)"  ||||   .'  .-'`'-.  '.   } | ";
	pImage[5][3].Texture = (char*)"  \  /  /  .'         '.  \  | ";
	pImage[5][4].Texture = (char*)"    ||  /  ;            ;  \ | ";
	pImage[5][5].Texture = (char*)"   ||  | ;             ; |  || ";
	pImage[5][6].Texture = (char*)"   %%  | ;             ; |  %% ";
	pImage[5][7].Texture = (char*)"   %%  \  ;            ;  /  %% ";
	pImage[5][8].Texture = (char*)"   %%   \  '.        .'  /   %% ";
	pImage[5][9].Texture = (char*)"   %%    '.  `-.,.-'  .'    %% ";
	pImage[5][10].Texture = (char*)"   %%      '-.,___,.-'      %% ";


	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			pImage[i][j].TransPos.Position = Vector3(70 - (float)strlen("|                                                      |")/2, 6.0f);
		}
	}




	pText[0][0].Texture = (char*)"  『 사거리 빵집에서 일을 하던 스티븐은";
	pText[0][1].Texture = (char*)"   제약회사의 신약 개발 때문이라 했고,↓ 』";

	pText[1][0].Texture = (char*)"         『 윗집에 살던 윌슨 부부는";
	pText[1][1].Texture = (char*)"         분노한 신의 심판이라 했다.↓ 』";

	pText[2][0].Texture = (char*)"『 그들은 원인을 찾으면 모든것이 해결될 것 처럼 ";
	pText[2][1].Texture = (char*)" 죽는 순간까지도 진실을 갈구했지만,↓ 』";
		 
	pText[3][0].Texture = (char*)"           『 나는 관심 없다↓ 』";
	pText[3][1].Texture = (char*)"";
		 		
	pText[4][0].Texture = (char*)"      『 나는 그저 오늘 저녁 식사가 ";
	pText[4][1].Texture = (char*)"    물에 불린 개사료가 아니길 바랄뿐이다.↓ 』";
		 	
	pText[5][0].Texture = (char*)"       『 이제 나가봐야 할 시간이다.↓ 』";
	pText[5][1].Texture = (char*)" ";
	

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			pText[i][j].TransPos.Position = Vector3(64 - (float)strlen("|                                                      |")/2, 21.0f);
		}
	}



	int Count = 0;


}

void Chapter00::Update()
{
	
	if (GetAsyncKeyState(VK_DOWN))
	{
		++Count;

		if (Count > 5)
		{
			SceneManager::Getinstance()->SetScene(SCENEID_MENU);
		}
		Sleep(200);
	}


}

void Chapter00::Render()
{

	for (int i = 0; i < 8; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(Trans[i].TransPos.Position.x),
			int(Trans[i].TransPos.Position.y + i),
			Trans[i].Texture);
	}




	for (int i = 0; i < 11; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(pImage[Count][i].TransPos.Position.x),
			int(pImage[Count][i].TransPos.Position.y + i),
			pImage[Count][i].Texture);
	}

	for (int i = 0; i < 2; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(pText[Count][i].TransPos.Position.x),
			int(pText[Count][i].TransPos.Position.y + i),
			pText[Count][i].Texture);

	}
	
	


}

void Chapter00::Release()
{
}

