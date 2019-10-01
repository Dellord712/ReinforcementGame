#pragma once
#include "Obj.h"

class Shop : public Obj
{
private:
	Obj* shopstate;
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Shop();
	~Shop();
};

