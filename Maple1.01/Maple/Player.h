#pragma once
#include "Obj.h"
class Player : public Obj
{
private:
	int currentY;
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Player();
	~Player();
};

