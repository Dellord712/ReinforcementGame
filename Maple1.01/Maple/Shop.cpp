#include "Shop.h"
#include "BitMapManager.h"

void Shop::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(111);
	SelectObject(bitmapDC, myBitMap);
	x = 880;
	y = 16;
	bx = 0;
	aniSpeed = 0;
	aniCount = 20;
}

void Shop::Progress()
{

}

void Shop::Render()
{
	if (aniSpeed >= aniCount) {
		if (bx >= Shop_ANI_COUNT) {
			bx = 0;
		}
		else {
			bx++;
		}
		aniSpeed = 0;
	}
	else {
		aniSpeed++;
	}
	TransparentBlt(*memDC, x, y, Shop_Width, Shop_Height, bitmapDC, bx*Shop_Width, 0, Shop_Width, Shop_Height, RGB(255, 0, 255));
}

void Shop::Release()
{
}

Shop::Shop()
{
}


Shop::~Shop()
{
}
