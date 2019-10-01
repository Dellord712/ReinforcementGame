#include "Blocks.h"
#include "BitMapManager.h"


Blocks::Blocks(int _x, int _y, int n)
{
	x = _x;
	y = _y;
	num = n;
}


void Blocks::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	if (num == 1) {
		myBitMap = BitMapManager::GetInst()->GetBitMap(102);
	}
	else if (num == 2) {
		myBitMap = BitMapManager::GetInst()->GetBitMap(103);
	}
	else if(num==3){
		myBitMap = BitMapManager::GetInst()->GetBitMap(104);
	}
	else if (num == 4) {
		myBitMap = BitMapManager::GetInst()->GetBitMap(105);
	}
	else if (num == 5) {
		myBitMap = BitMapManager::GetInst()->GetBitMap(106);
	}
	SelectObject(bitmapDC, myBitMap);
	
}

void Blocks::Progress()
{
}

void Blocks::Render()
{
	if (num == 1) {
		TransparentBlt(*memDC, x, y, Block1_Width, Block1_Height, bitmapDC, 0, 0, Block1_Width, Block1_Height, RGB(255, 0, 255));
	}
	else if (num == 2) {
		TransparentBlt(*memDC, x, y, Block2_Width, Block2_Height, bitmapDC, 0, 0, Block2_Width, Block2_Height, RGB(255, 0, 255));
	}
	else if(num == 3) {
		TransparentBlt(*memDC, x, y, Block3_Width, Block3_Height, bitmapDC, 0, 0, Block3_Width, Block3_Height, RGB(255, 0, 255));
	}
	else if (num == 4) {
		TransparentBlt(*memDC, x, y, Block4_Width, Block4_Height, bitmapDC, 0, 0, Block4_Width, Block4_Height, RGB(255, 0, 255));
	}
	else if (num == 5) {
		TransparentBlt(*memDC, x, y, Block5_Width, Block5_Height, bitmapDC, 0, 0, Block5_Width, Block5_Height, RGB(255, 0, 255));
	}
}

void Blocks::Release()
{
}

Blocks::~Blocks()
{
}
