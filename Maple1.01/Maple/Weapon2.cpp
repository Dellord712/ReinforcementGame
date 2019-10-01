#include "Weapon2.h"
#include "BitMapManager.h"



void Weapon2::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(120);
	SelectObject(bitmapDC, myBitMap);
	x = 890;
	y = 403;
	t = 0;
	h = 0;
	aniSpeed = 0;
	aniCount = 4;
	tx = 0;
	ty = 0;
	move = true;
	bx0 = false;
	a_click = false;
}

void Weapon2::Progress()
{
	if (tx - Player_Width  <= x && tx + Player_Width >= x && ty - 60 <= y && ty + Player_Height >= y) {
		a_click = true;
	}
	else {
		a_click = false;
	}
	if (GetAsyncKeyState(0x41) & 0x8000&&a_click) {
		bx0 = true;
	}
}

void Weapon2::Render()
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
				if (y - ty <= 4) {
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
		if (tx - PICK_UP_DIFF <= x && tx + PICK_UP_DIFF >= x && ty - PICK_UP_DIFF <= y && ty + PICK_UP_DIFF >= y&&crash==false) {
			crash = true;
			getweapon = true;
		}
	}
	if (aniSpeed >= aniCount) {
		aniSpeed = 0;
		if (y < 404 && move) {
			t += 0.7;
			h = 21 * sin(90 * PI / 180) * t - 0.5 * Gravity * t * t;
			if (y - h >= 404) {
				y = 404;
			}
			else {
				y = y - (int)h;
				x -= 8;
			}
		}
		else {
			move = false;
		}
	}
	else {
		aniSpeed++;
	}
	if (crash == false) {
		TransparentBlt(*memDC, x, y, Weapon_Width, Weapon_Height, bitmapDC, Weapon_Width, 0, Weapon_Width, Weapon_Height, RGB(255, 0, 255));
	}
}

void Weapon2::Release()
{
}

Weapon2::Weapon2()
{
}


Weapon2::~Weapon2()
{
}
