#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Story.h"
#include "GameOver.h"

//SceneManager* SceneManager::m_pinstance = NULL;

SceneManager::SceneManager(): m_pSceneState(NULL)
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(const SCENEID& _SceneID)
{
	if (m_pSceneState != NULL)
		SAFE_RELEASE(m_pSceneState);

	switch (_SceneID)
	{
	case SCENEID_LOGO:
		m_pSceneState = new Logo;
		break;
		
	case SCENEID_MENU:
		m_pSceneState = new Menu;
		break;
				
	case SCENEID_STORY:
		m_pSceneState = new Story;
		break;
		
	case SCENEID_STAGE:
		m_pSceneState = new Stage;
		break;
		
	case SCENEID_EXIT:
		m_pSceneState = new GameOver;
		break;
	}
	m_pSceneState->Initialize();
}

void SceneManager::Update()
{
	m_pSceneState->Update();
}

void SceneManager::Render()
{
	m_pSceneState->Render();
}

void SceneManager::Release()
{
	SAFE_RELEASE(m_pSceneState);
}

