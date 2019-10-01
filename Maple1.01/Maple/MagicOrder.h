#pragma once
#include "Obj.h"
class MagicOrder:public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	MagicOrder(int _x, int _y, int n);
	~MagicOrder();
};

