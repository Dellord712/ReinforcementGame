#pragma once
#include "Obj.h"
class Weapon2 :public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Weapon2();
	~Weapon2();
};