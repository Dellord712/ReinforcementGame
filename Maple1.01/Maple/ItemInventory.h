#pragma once
#include "Obj.h"
class ItemInventory:public Obj
{
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	ItemInventory();
	~ItemInventory();
};

