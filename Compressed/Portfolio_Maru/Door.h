#pragma once
#include "Object.h"

class Door : public Object
{
private:
	int Index;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(const int& _index) { Index = _index; }
public:
	Door();
	virtual ~Door();
};

