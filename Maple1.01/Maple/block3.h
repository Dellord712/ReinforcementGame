#pragma once
#include "Obj.h"
class block3 : public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	block3();
	~block3();
};

