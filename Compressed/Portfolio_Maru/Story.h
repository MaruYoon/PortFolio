#pragma once
#include "Scene.h"

class Chapter00;
class Story : public Scene
{
private:
	Chapter00* Chap;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;


public:
	Story();
	virtual ~Story();

};

