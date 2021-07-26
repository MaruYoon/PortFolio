#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;
	char* Texture[128];
	bool Active;
	int CheckRoom;

public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;


public:
	Transform* GetTransform() { return &TransInfo; }

	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(const float& _x, const float& _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }

	Vector3 GetScale() const { return TransInfo.Scale; }

	bool GetActive() const { return Active; }
	void SetActive(const bool& _Active) { Active = _Active; }
public:
	Object();
	virtual ~Object();

};

