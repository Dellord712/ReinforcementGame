#include "EnhancedMotion.h"
#include "BitMapManager.h"


void EnhancedMotion::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(119);
	SelectObject(bitmapDC, myBitMap);
	bx = 0;
	aniSpeed = 0;
	aniCount = 4;
	ex = 6;
	emotion = false;
}

void EnhancedMotion::Progress()
{
}

void EnhancedMotion::Render()
{
	if (aniSpeed >= aniCount) {
		aniSpeed = 0;
		if (ex <= 5) {
			ex++;
		}
	}
	else {
		aniSpeed++;
	}
	if (ex<=5) {
		TransparentBlt(*memDC, x, y, Enhanced_Width, Enhanced_Height, bitmapDC, ex*Enhanced_Width, success*Enhanced_Height, Enhanced_Width, Enhanced_Height, RGB(255, 0, 255));
	}
}

void EnhancedMotion::Release()
{
}

EnhancedMotion::EnhancedMotion()
{
}


EnhancedMotion::~EnhancedMotion()
{
}
