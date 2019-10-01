#pragma once
#include "Include.h"
class Obj
{
protected:
	HDC* memDC;
	HDC bitmapDC;
	HBITMAP myBitMap;
protected:
	int x, y;
	int bx, by;
	int tx, ty;
	int aniSpeed;
	int aniCount;
	int shapechange;
	int num;
	bool move;
	bool jumping;
	bool bx0;
	bool crash;
	int diff;
	double h, t;
	int nRandom;
	bool a_click;
	static int magicordercount[3];
	static int meso;
	static int offensepower;
	static int reinforce;
	static int percent;
	static int success;
	static int ex;
	static bool b_shop;
	static bool emotion;
	static bool getweapon;
	static int value;
	static int max_value;
	static int max_offensepower;
	static int max_reinforce;
	static int magicsuccess[3];
	static int magicfail[3];
protected:
	Transform transform;
	Transform Mon_transform;
protected:
	RECT colliderRect;
	RECT monsterRect;
	LINE line[9];

protected:
	void SetLine(LINE* line,int x, int y, int ex, int ey,bool ig) {
		line->x = x;
		line->y = y;
		line->ex = ex;
		line->ey = ey;
		line->isground = ig;
	}
	void CalculateColliderRect()
	{
		colliderRect.left = transform.x+4;
		colliderRect.top = transform.y+15;
		colliderRect.right = transform.x + transform.colliderW-3;
		colliderRect.bottom = transform.y + transform.colliderH;
	}
public:
	bool isGrounded;
	bool jump;
	bool death;
	bool attack;
	int right;
	static bool o_click;
	int menu_x;
	int menu_y;
public:
	static int GetMaxValie() {
		return max_value;
	}
	static int GetValue() {
		return value;
	}
	void Crash() {
		crash = true;
	}
	void SetY(int y_) {
		y = y_;
	}
	void SetPosX(int x)
	{
		transform.x = x;
		CalculateColliderRect();
	}
	void SetPosY(int y)
	{
		transform.y = y;
		CalculateColliderRect();
	}

	void SetPosition(int x, int y)
	{
		transform.x = x;
		transform.y = y;
		CalculateColliderRect();
	}

	void SetPlayPosition(PRECT p) {
		x = p->left-12;
		y = p->top-65;
	}
	void SetPlayPosition2(PRECT p) {
		tx = (p->left + p->right) / 2-12;
		ty = p->top+10;
	}
	RECT* GetColliderRect() {
		return &colliderRect;
	}

	RECT* GetMonsterRect() {
		return &monsterRect;
	}

	LINE* GetLine(int i) {
		return &line[i];
	}
public:
	virtual void Initialize(HDC* _memDC)PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Obj();
	~Obj();
};