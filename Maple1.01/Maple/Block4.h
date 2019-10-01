#pragma once
#include "Obj.h"
class Block4 : public Obj
{
private:
	int x, y;
	int num;
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Block4(int _x,int _y,int n);
	~Block4();
};

