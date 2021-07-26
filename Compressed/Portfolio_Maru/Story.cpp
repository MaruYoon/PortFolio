#include "Story.h"
#include "Chapter00.h"
#include "SceneManager.h"

Story::Story()
{
}

Story::~Story()
{
	Release();
}

void Story::Initialize()
{
	Chap = new Chapter00;
	Chap->Initialize();
}

void Story::Update()
{
	Chap->Update();

}

void Story::Render()
{
	Chap->Render();
}

void Story::Release()
{
	Chap->Release();
}

