#include "ShopState.h"
#include "BitMapManager.h"


void ShopState::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(114);
	SelectObject(bitmapDC, myBitMap);
	x = 680;
	y = 26;
	b_shop = false;
}

void ShopState::Progress()
{
	if (GetAsyncKeyState(0x53) & 0x0001) {
		if (b_shop) {
			b_shop = false;
		}
		else {
			b_shop = true;
		}
	}
}

void ShopState::Render()
{
	if (b_shop) {
		TransparentBlt(*memDC, x, y, ShopState_Width, ShopState_Height, bitmapDC, 0, 0, ShopState_Width, ShopState_Height, RGB(255, 0, 255));
		TCHAR str[100];
		wsprintf(str, TEXT("%d"), meso);
		TextOut(*memDC, 826, 324, str, lstrlen(str));
	}
}

void ShopState::Release()
{
}

ShopState::ShopState()
{
}


ShopState::~ShopState()
{
}
