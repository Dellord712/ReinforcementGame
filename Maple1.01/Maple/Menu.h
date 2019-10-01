#pragma once
#include "Obj.h"

class Menu
{
private:
	int x, y;
	bool putf1;
public:
	int count;
	bool change;
	static bool mode_limit;
	static bool time0;
	static bool b_menu;
	static bool reaplay;
	static bool start;
	static bool s_time;
	static bool e_time;
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
	Obj* clock;
	Obj* time;
	Obj* magicorderstate2;
	Obj* menuboard;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	Menu(HWND* _hWnd);
	~Menu();
};

