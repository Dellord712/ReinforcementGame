#include "Block4.h"
#include "BitMapManager.h"

void Block4::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	if (num == 5) {
		myBitMap = BitMapManager::GetInst()->GetBitMap(106);
	}
	else {
		myBitMap = BitMapManager::GetInst()->GetBitMap(105);
	}
	SelectObject(bitmapDC, myBitMap);
}

void Block4::Progress()
{
}

void Block4::Render()
{
	if (num == 5){
		TransparentBlt(*memDC, x, y, Block5_Width, Block5_Height, bitmapDC, 0, 0, Block5_Width, Block5_Height, RGB(255, 0, 255));
	}
	else {
		TransparentBlt(*memDC, x, y, Block4_Width, Block4_Height, bitmapDC, 0, 0, Block4_Width, Block4_Height, RGB(255, 0, 255));
	}
}

void Block4::Release()
{
}

Block4::Block4(int _x,int _y,int n)
{
	x = _x;
	y = _y;
	num = n;
}


Block4::~Block4()
{
}
