#include "Weapon.h"
#include "BitMapManager.h"


void Weapon::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(120);
	SelectObject(bitmapDC, myBitMap);
	x = 26;
	y = 70;
	getweapon = false;
}

void Weapon::Progress()
{
}

void Weapon::Render()
{
	if (getweapon) {
		TransparentBlt(*memDC, x, y, Weapon_Width, Weapon_Height, bitmapDC, Weapon_Width, 0, Weapon_Width, Weapon_Height, RGB(255, 0, 255));
	}
}

void Weapon::Release()
{
}

Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}
