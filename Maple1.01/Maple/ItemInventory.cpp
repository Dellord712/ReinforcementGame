#include "ItemInventory.h"
#include "BitMapManager.h"


void ItemInventory::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(115);
	SelectObject(bitmapDC, myBitMap);
	x = 16;
	y = 16;
	bx = 1;
}

void ItemInventory::Progress()
{
	if (GetAsyncKeyState(0x49) & 0x8000) {
		bx = 1;
	}if (GetAsyncKeyState(0x55) & 0x8000) {
		bx = 0;
	}
}

void ItemInventory::Render()
{
	TransparentBlt(*memDC, x, y, ItenInvwn_Width, ItenInvwn_Height, bitmapDC, ItenInvwn_Width*bx, 0, ItenInvwn_Width, ItenInvwn_Height, RGB(255, 0, 255));
	TCHAR str[100];
	wsprintf(str, TEXT("%d"), meso);
	TextOut(*memDC, x+52, y+268, str, lstrlen(str));
}

void ItemInventory::Release()
{
}

ItemInventory::ItemInventory()
{
}


ItemInventory::~ItemInventory()
{
}
