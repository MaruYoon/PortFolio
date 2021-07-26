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
	DoubleBuffer::GetInstance()->CreateBuffer(
		CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);

	SceneManager::Getinstance()->SetScene(SCENEID_STAGE);
}

void MainUpdate::Update()
{
	InputManager::Getinstance()->CheckKey();
	SceneManager::Getinstance()->Update();

	DoubleBuffer::GetInstance()->FlippingBuffer();
	DoubleBuffer::GetInstance()->ClearBuffer();

}

void MainUpdate::Render()
{
	SceneManager::Getinstance()->Render();
}

void MainUpdate::Release()
{
	DoubleBuffer::GetInstance()->DestroyBuffer();
	SceneManager::Getinstance()->Release();
}

