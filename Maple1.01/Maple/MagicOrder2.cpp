#include "MagicOrder2.h"
#include "BitMapManager.h"


void MagicOrder2::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(116);
	SelectObject(bitmapDC, myBitMap);
	srand((unsigned int)time(0));
	x = 890;
	y = 408;
	if(num==2){
		nRandom = rand() % 4;
	}
	else {
		nRandom = (rand() % 10)+1;
	}
	
	if (num == 0) {
		s_magicordercount[0] = nRandom;
		bx = 0;
	}
	else if (num == 1) {
		s_magicordercount[1] = nRandom;
		bx = 4;
	}
	else {
		s_magicordercount[2] = nRandom;
		bx = 8;
	}
	t = 0;
	h = 0;
	aniSpeed = 0;
	aniCount = 4;
	move = true;
	bx0 = false;
	by = 0;
	a_click = false;
}

void MagicOrder2::Progress()
{
	if (tx - Player_Width  <= x && tx + Player_Width  >= x && ty - 60 <= y && ty + Player_Height >= y) {
		a_click = true;
	}
	else {
		a_click = false;
	}
	if (GetAsyncKeyState(0x41) & 0x8000&&a_click) {
		bx0 = true;
	}
}

void MagicOrder2::Render()
{
	if (bx0) {
		if (by >= 4) {
			by = 0;
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
			by++;
		}
		if (tx - PICK_UP_DIFF <= x && tx + PICK_UP_DIFF >= x && ty - PICK_UP_DIFF <= y && ty + PICK_UP_DIFF >= y&&crash==false) {
			crash = true;
			if (num == 0) {
				magicordercount[0] = s_magicordercount[0];
			}
			else if (num == 1) {
				magicordercount[1] = s_magicordercount[1];
			}
			else {
				magicordercount[2] = s_magicordercount[2];
			}
		}
	}
	if (aniSpeed >= aniCount) {
		aniSpeed = 0;
		if (y < 409 && move) {
			t += 0.7;
			h = 21 * sin(90 * PI / 180) * t - 0.5 * Gravity * t * t;
			if (y - h >= 409) {
				y = 409;
			}
			else {
				y = y - (int)h;
				x += bx;
			}
		}
		else {
			move = false;
		}
	}
	else {
		aniSpeed++;
	}
	if (nRandom != 0&& crash == false) {
		TransparentBlt(*memDC, x, y, MagicOrder_Width, MagicOrder_Height, bitmapDC, MagicOrder_Width*num, 0, MagicOrder_Width, MagicOrder_Height, RGB(255, 0, 255));
	}
}

void MagicOrder2::Release()
{
}

MagicOrder2::MagicOrder2(int n)
{
	num = n;
}


MagicOrder2::~MagicOrder2()
{
}
