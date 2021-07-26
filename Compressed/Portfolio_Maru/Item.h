#pragma once
#include "Object.h"


class Item : public Object
{
private:
	char* _Item[4][4][3];
	int Horizontal;
	int Motion;
	bool Collision;


public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	int GetitemNum() const { return Horizontal; }

public:
	Item();
	virtual ~Item();
};

