#include "block3.h"
#include "BitMapManager.h"

void block3::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(102);
	SelectObject(bitmapDC, myBitMap);
}

void block3::Progress()
{
}

void block3::Render()
{
	TransparentBlt(*memDC, 0, 495, Block3_Width, Block3_Height, bitmapDC, 0, 0, Block3_Width, Block3_Height, RGB(255, 0, 255));
}

void block3::Release()
{
}

block3::block3()
{
}


block3::~block3()
{
}
