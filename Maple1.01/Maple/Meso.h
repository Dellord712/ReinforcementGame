#pragma once
#include "Obj.h"
class Meso:public Obj
{
private:
	int s_meso;
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Meso();
	~Meso();
};

