#pragma once
#include "Obj.h"
class ShopState :public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	ShopState();
	~ShopState();
};

