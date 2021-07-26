#pragma once
#include "Story.h"

class Chapter00 : public Story
{
public:
	int Count;
	STORY pImage[16][16];
	STORY pText[16][64];

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;


public:
	Chapter00();
	virtual ~Chapter00();

};

