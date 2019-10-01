#include "MagicOrder.h"
#include "BitMapManager.h"


void MagicOrder::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(116);
	SelectObject(bitmapDC, myBitMap);
	srand((unsigned int)time(0));
	bx = 35;
	by = 84;
	aniSpeed = 0;
	aniCount = 30;
	nRandom = 0;
	for (int i = 0; i < 3; i++) {
		magicordercount[i] = 0;
		magicsuccess[i] = 0;
		magicfail[i] = 0;
	}
	offensepower = 0;
	reinforce = 0;
	percent = 100;
	success = 0;
}

void MagicOrder::Progress()
{
	if (aniSpeed <= aniCount) {
		aniSpeed++;
	}
	
	if(aniSpeed > aniCount) {
		switch (num)
		{
		case 0:
			if (GetAsyncKeyState(0x5A) & 0x0001) {
				if (meso >= 1000 && b_shop) {
					magicordercount[0]++;
					meso -= 1000;
				}
			}
			if (GetAsyncKeyState(0x56) & 0x0001) {
				if (b_shop&&magicordercount[0]>0) {
					magicordercount[0]--;
					meso += 1000;
				}
			}
			if (GetAsyncKeyState(0x51) & 0x0001) {
				nRandom = rand() % 100;
				if (magicordercount[0] > 0) {
					magicordercount[0]--;
					ex = 0;
					aniSpeed = 0;
					if (nRandom < 70) {
						magicsuccess[0]++;
						if (nRandom < 14) {
							offensepower += 20;
							success = 2;
						}
						else {
							offensepower += 10;
							success = 0;
						}
					}
					else {
						magicfail[0]++;
						success = 1;
					}
				}
			}
			break;
		case 1:
			if (GetAsyncKeyState(0x58) & 0x0001) {
				if (meso >= 5000 && b_shop) {
					magicordercount[1]++;
					meso -= 5000;
				}
			}
			if (GetAsyncKeyState(0x42) & 0x0001) {
				if (b_shop&&magicordercount[1] > 0) {
					magicordercount[1]--;
					meso += 5000;
				}
			}
			if (GetAsyncKeyState(0x57) & 0x0001) {
				nRandom = rand() % 100;
				if (magicordercount[1] > 0) {
					magicordercount[1]--;
					ex = 0;
					aniSpeed = 0;
					if (nRandom < 30) {
						magicsuccess[1]++;
						if (nRandom < 6) {
							offensepower =(int)(offensepower*1.2);
							success = 2;
						}
						else {
							offensepower = (int)(offensepower*1.1);
							success = 0;
						}
					}
					else {
						magicfail[1]++;
						success = 1;
					}
				}
			}
			break;
		case 2:
			if (GetAsyncKeyState(0x43) & 0x0001) {
				if (meso >= 8000 && b_shop) {
					magicordercount[2]++;
					meso -= 8000;
				}
			}
			if (GetAsyncKeyState(0x4E) & 0x0001) {
				if (b_shop&&magicordercount[2] > 0) {
					magicordercount[2]--;
					meso += 8000;
				}
			}
			if (GetAsyncKeyState(0x45) & 0x0001) {
				nRandom = rand() % 100;
				if (magicordercount[2] > 0 && reinforce <= 24) {
					magicordercount[2]--;
					ex = 0;
					aniSpeed = 0;
					if (nRandom < percent) {
						magicsuccess[2]++;
						reinforce++;
						success = 0;
						if (reinforce <= 18) {
							percent = 100 - 5 * reinforce;
						}
						else if (reinforce <= 21) {
							percent = percent - 2;
						}
						else if (reinforce <= 25) {
							percent = percent - 1;
						}
					}
					else {
						magicfail[2]++;
						success = 1;
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void MagicOrder::Render()
{
	TransparentBlt(*memDC, x, y, MagicOrder_Width, MagicOrder_Height, bitmapDC, MagicOrder_Width*num, 0, MagicOrder_Width, MagicOrder_Height, RGB(255, 0, 255));
	switch (num)
	{
	case 0:
		TCHAR str[100];
		wsprintf(str, TEXT("%d"), magicordercount[0]);
		TextOut(*memDC, bx, by, str, lstrlen(str));
		break;
	case 1:
		TCHAR str2[100];
		wsprintf(str2, TEXT("%d"), magicordercount[1]);
		TextOut(*memDC, bx+35, by, str2, lstrlen(str2));
		break;
	case 2:
		TCHAR str3[100];
		wsprintf(str3, TEXT("%d"), magicordercount[2]);
		TextOut(*memDC, bx+70,by, str3, lstrlen(str3));
		break;
	default:
		break;
	}
}

void MagicOrder::Release()
{
}

MagicOrder::MagicOrder(int _x, int _y, int n)
{
	x = _x;
	y = _y;
	num = n;
}


MagicOrder::~MagicOrder()
{
}
