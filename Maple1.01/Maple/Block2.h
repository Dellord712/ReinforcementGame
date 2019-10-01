#pragma once
#include "Obj.h"
class Block2 : public Obj
{
private:
	int x;
	int y;
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Block2(int x_,int y_);
	~Block2();
};
