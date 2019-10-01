#pragma once
#include "Obj.h"
#include "CollisionMgr.h"
class MainGame : public CollisionMgr
{
private:
	HWND* hWnd;
	HDC hdc, memDC;
	RECT crt;
	HBITMAP myBitMap, oldBitMap;
private:
	Obj* background;
	Obj* block1;
	Obj* block2;
	Obj* block2_2;
	Obj* block3;
	Obj* block4;
	Obj* block4_2;
	Obj* block5;
	Obj* block5_2;
	Obj* block5_3;
	Obj* player;
	Obj* line;
	Obj* shop;
	Obj* boss;
	Obj* shopstate;
	Obj* iteminven;
	Obj* magicOrder1;
	Obj* magicOrder2;
	Obj* magicOrder3;
	Obj* magicorderstate;
	Obj* magicorderstate2;
	Obj* weaponstate;
	Obj* weapon;
	Obj* enhanced;
	Obj* meso;
	Obj* weapon2;
	Obj* magicorder1;
	Obj* magicorder2;
	Obj* magicorder3;
	Obj* clock;
	Obj* time;
private:
	int count;
	bool u_click;
	bool i_click;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	MainGame(HWND* _hWnd);
	~MainGame();
};

