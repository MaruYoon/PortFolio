#pragma once
#include "Object.h"

class TopPlayer : public Object
{

public:
	char* Texture[4][2][3];
	int Horizontal;
	int Motion;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	void _CheckKey();

public:
	TopPlayer();
	virtual ~TopPlayer();

};

