#pragma once
#include "Obj.h"
class Blocks : public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Blocks(int _x,int _y, int n);
	~Blocks();
};

