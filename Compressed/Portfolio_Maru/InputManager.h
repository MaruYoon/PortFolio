#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* m_pinstance;
public:
	static InputManager* Getinstance()
	{
		if (m_pinstance == NULL)
			m_pinstance = new InputManager;

		return m_pinstance;
	}

private:
	ULONG m_ulKey;
public:
	ULONG GetKey() const { return m_ulKey; }
	void CheckKey();

private:
	InputManager();
public:
	~InputManager();

};

