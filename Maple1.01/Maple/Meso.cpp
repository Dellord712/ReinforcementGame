#include "Meso.h"
#include "BitMapManager.h"
#include "Menu.h"

void Meso::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(121);
	SelectObject(bitmapDC, myBitMap);
	srand((unsigned int)time(0));
	nRandom = rand() % 4;
	x = 890; 
	y = 403;
	bx = 0;
	t = 0;
	h = 0;
	aniSpeed = 0;
	aniCount = 7;
	num = 0;
	tx = 0;
	ty = 0;
	move = true;
	crash = false;
	bx0 = false;
	a_click = false;
	meso = 0;
	if (Menu::mode_limit == false) {
		s_meso = 100000000;
		by = 3;
	}
	else {
		switch (nRandom)
		{
		case 0:
			s_meso = 500000;
			by = 0;
			break;
		case 1:
			s_meso = 700000;
			by = 1;
			break;
		case 2:
			s_meso = 1000000;
			by = 2;
			break;
		case 3:
			s_meso = 2000000;
			by = 3;
			break;
		default:
			break;
		}
	}
}

void Meso::Progress()
{
	if (tx - Player_Width <= x && tx + Player_Width >= x&&ty-60<=y&&ty+Player_Height>=y) {
		a_click = true;
	}
	else {
		a_click = false;
	}
	if (GetAsyncKeyState(0x41) & 0x8000&&a_click) {
		bx0 = true;
	}
}

void Meso::Render()
{
	if (bx0) {
		if (num >= 4) {
			num = 0;
			if (tx > x) {
				x += PICK_UP_ITEM;
			}
			else if (tx < x) {
				x -= PICK_UP_ITEM;
			}
			if (ty > y) {
				if (ty - y <= 4) {
					y++;
				}
				else {
					y += PICK_UP_ITEM;
				}
			}
			else if (ty < y) {
				if (y-ty <= 4) {
					y--;
				}
				else {
					y -= PICK_UP_ITEM;
				}
			}
		}
		else {
			num++;
		}
		if (tx- PICK_UP_DIFF <= x && tx + PICK_UP_DIFF >= x && ty - PICK_UP_DIFF <= y && ty + PICK_UP_DIFF >= y&&crash==false) {
			crash = true;
			meso = s_meso;
		}
	}
	if (num >= 4) {
		num = 0;
		if (y < 404&&move) {
			t += 0.7;
			h = 21 * sin(90 * PI / 180) * t - 0.5 * Gravity * t * t;
			if (y - h >= 404) {
				y = 404;
			}
			else {
				y = y - (int)h;
				x -= 4;
			}
		}
		else {
			move = false;
		}
	}
	else {
		num++;
	}
	
	if (aniSpeed >= aniCount) {
		aniSpeed = 0;
		if (bx >= 3) {
			bx = 0;
		}
		else {
			bx++;
		}
	}
	else {
		aniSpeed++;
	}
	if (crash == false) {
		TransparentBlt(*memDC, x, y, Meso_Width, Meso_Height, bitmapDC, bx*Meso_Width, by*Meso_Height, Meso_Width, Meso_Height, RGB(255, 0, 255));
	}
}

void Meso::Release()
{
}

Meso::Meso()
{
}


Meso::~Meso()
{
}
