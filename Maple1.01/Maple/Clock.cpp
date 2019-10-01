#include "Clock.h"
#include "BitMapManager.h"


void Clock::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(122);
	SelectObject(bitmapDC, myBitMap);
	x = 196;
	y = 10;
}

void Clock::Progress()
{
}

void Clock::Render()
{
	TransparentBlt(*memDC, x, y, Clock_Width, Clock_Height, bitmapDC, 0, 0, Clock_Width, Clock_Height, RGB(255, 0, 255));
}

void Clock::Release()
{
}

Clock::Clock()
{
}


Clock::~Clock()
{
}
