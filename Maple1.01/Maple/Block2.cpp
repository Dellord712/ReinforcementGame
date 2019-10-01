#include "Block2.h"
#include "BitMapManager.h"

void Block2::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(103);
	SelectObject(bitmapDC, myBitMap);
}

void Block2::Progress()
{
}

void Block2::Render()
{
	TransparentBlt(*memDC, x, y, Block2_Width, Block2_Height, bitmapDC, 0, 0, Block2_Width, Block2_Height, RGB(255, 0, 255));
}

void Block2::Release()
{
}

Block2::Block2(int x_, int y_)
{
	x = x_;
	y = y_;
}


Block2::~Block2()
{
}

