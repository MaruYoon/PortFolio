#pragma once
#include "Headers.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* m_pinstance;
public:
	static SceneManager* Getinstance()
	{
		if (m_pinstance == NULL)
			m_pinstance = new SceneManager;

		return m_pinstance;
	}

private:
	Scene* m_pSceneState;
public:
	void SetScene (const SCENEID& _SceneID);
	void Update();
	void Render();
	void Release();

private:
	SceneManager();
public:
	~SceneManager();


};

