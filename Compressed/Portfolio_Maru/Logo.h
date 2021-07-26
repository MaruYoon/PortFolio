#pragma once
#include "Scene.h"

class Logo : public Scene
{
public:
	int LogoCheck;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;


public:
	Logo();
	virtual ~Logo();

};

