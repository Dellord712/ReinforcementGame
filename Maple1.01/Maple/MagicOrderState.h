#pragma once
#include "Obj.h"
class MagicOrderState:public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	MagicOrderState(int _x,int _y,int n);
	~MagicOrderState();
};

