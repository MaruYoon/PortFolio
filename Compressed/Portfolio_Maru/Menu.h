#pragma once
#include "Scene.h"


class Menu : public Scene
{
private:
	int Choice;
	SCENE pMenu[8];
	SCENE pTitle[16];

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;


public:
	Menu();
	virtual ~Menu();

};


