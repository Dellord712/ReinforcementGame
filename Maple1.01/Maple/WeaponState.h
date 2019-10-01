#pragma once
#include "Obj.h"
class WeaponState:public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	WeaponState();
	~WeaponState();
};

