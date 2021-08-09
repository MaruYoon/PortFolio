#include "MainUpdate.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"
#include "InputManager.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Initialize()
{
	GETSINGLETON(DoubleBuffer)->CreateBuffer(
		CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);

	GETSINGLETON(SceneManager)->SetScene(SCENEID_STAGE);

	/*
	DoubleBuffer::GetInstance()->CreateBuffer(
		CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);
	*/

}

void MainUpdate::Update()
{
	GETSINGLETON(InputManager)->CheckKey();
	GETSINGLETON(SceneManager)->Update();

	GETSINGLETON(DoubleBuffer)->FlippingBuffer();
	GETSINGLETON(DoubleBuffer)->ClearBuffer();

	/*
	InputManager::Getinstance()->CheckKey();
	SceneManager::Getinstance()->Update();

	DoubleBuffer::GetInstance()->FlippingBuffer();
	DoubleBuffer::GetInstance()->ClearBuffer();
	*/

}

void MainUpdate::Render()
{
	GETSINGLETON(SceneManager)->Render();
	//SceneManager::Getinstance()->Render();
}

void MainUpdate::Release()
{
	GETSINGLETON(DoubleBuffer)->DestroyBuffer();
	GETSINGLETON(SceneManager)->Release();

	/*
	DoubleBuffer::GetInstance()->DestroyBuffer();
	SceneManager::Getinstance()->Release();
	*/
}

