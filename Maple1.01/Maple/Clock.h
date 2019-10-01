#pragma once
#include "Obj.h"
class Clock:public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Clock();
	~Clock();
};

