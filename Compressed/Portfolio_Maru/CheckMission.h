#pragma once
#include "Object.h"

class Item;
class CheckMission : public Object
{
private:
	int Choice;
	STORY pMenu[8];
	STORY pTitle[16];
	STORY pPaper[64];
	STORY pCheck[6];
	Item* piTem;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;


public:
	CheckMission();
	virtual ~CheckMission();

};

