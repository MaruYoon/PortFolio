#pragma once
#include "Object.h"


class Player : public Object
{
private:
	char* Texture[4][4][3];
	int Horizontal;
	int Motion;
	int RoomIndex;



public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	void CheckKey();
	
public:
	Player();
	virtual ~Player();
};

