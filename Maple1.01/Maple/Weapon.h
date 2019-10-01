#pragma once
#include "Obj.h"
class Weapon:public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Weapon();
	~Weapon();
};

