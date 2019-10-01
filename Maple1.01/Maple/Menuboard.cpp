#include "Menuboard.h"
#include "BitMapManager.h"

void Menuboard::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(124);
	SelectObject(bitmapDC, myBitMap);
	x = 400;
	y = 210;
	menu_x = 0;
	menu_y = 0;
}

void Menuboard::Progress()
{
}

void Menuboard::Render()
{
	TransparentBlt(*memDC, x, y, Menu_Width, Menu_Height, bitmapDC, menu_x*Menu_Width,menu_y*Menu_Height, Menu_Width, Menu_Height, RGB(255, 0, 255));
}

void Menuboard::Release()
{
}

Menuboard::Menuboard()
{
}


Menuboard::~Menuboard()
{
}
