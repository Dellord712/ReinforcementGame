#include "WeaponState.h"
#include "BitMapManager.h"

void WeaponState::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(118);
	SelectObject(bitmapDC, myBitMap);
	x = 16;
	y = 100;
	value = 0;
	bx = 0;
	by = 0;
}

void WeaponState::Progress()
{
	if (value >= 1073741824) {
		value = 1073741824;
	}
	else{
		value = (int)(pow(2, reinforce)*offensepower*1.5) / 10;
	}
}

void WeaponState::Render()
{
	if (getweapon) {
		bx = reinforce % 4;
		by = reinforce / 4;
		TransparentBlt(*memDC, x, y, WeaponState_Width, WeaponState_Height, bitmapDC, bx*WeaponState_Width, by*WeaponState_Height, WeaponState_Width, WeaponState_Height, RGB(255, 0, 255));
		TCHAR str[30];
		wsprintf(str, TEXT("파프니르 사탕무기 (+%d)"), reinforce);
		TextOut(*memDC, x + 33, y + 52, str, lstrlen(str));
		TCHAR str2[30];
		wsprintf(str2, TEXT("공격력 : %d"), offensepower);
		TextOut(*memDC, x + 60, y + 80, str2, lstrlen(str2));
		TCHAR str3[30];
		wsprintf(str3, TEXT("가치 : %d"), value);
		TextOut(*memDC, x + 60, y + 100, str3, lstrlen(str3));
	}
}

void WeaponState::Release()
{
}

WeaponState::WeaponState()
{
}


WeaponState::~WeaponState()
{
}
