#pragma once
#include "Object.h"

class Enemy : public Object
{
private:
	char* Texture[2][3][3];
	int Horizontal;
	int Motion;
	float Speed;
	int Index;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(const int& _index) { Index = _index; }
	void SetHorizontal(const int& _horizontal) { Horizontal = _horizontal; }

public:
	Enemy();
	virtual ~Enemy();

};

