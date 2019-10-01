#pragma once
#include "Obj.h"
class MagicOrder2 :public Obj
{private:
	int s_magicordercount[3];
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	MagicOrder2(int n);
	~MagicOrder2();
};
