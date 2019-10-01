#pragma once
#include "Obj.h"
class Monster : public Obj
{
private:
	int Monster_Ani_count;
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Monster();
	~Monster();
};

