#include "MagicOrderState.h"
#include "BitMapManager.h"


void MagicOrderState::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(117);
	SelectObject(bitmapDC, myBitMap);
	o_click = false;
}

void MagicOrderState::Progress()
{
	if (GetAsyncKeyState(0x4F) & 0x0001) {
		if (o_click) {
			o_click = false;
		}
		else {
			o_click = true;
		}
	}
}

void MagicOrderState::Render()
{
	if (num == 0||b_shop||o_click) {
		TransparentBlt(*memDC, x, y, MagicOrderState_Width, MagicOrderState_Height, bitmapDC, 0, 0, MagicOrderState_Width, MagicOrderState_Height, RGB(255, 0, 255));
		TextOut(*memDC, x + 11, y + 12, "파프니르 공격력 주문서 70%", 26);
		TextOut(*memDC, x + 239, y + 12, "파프니르 퍼센트 주문서 30%", 26);
		TextOut(*memDC, x + 495, y + 12, "파프니르 강화 주문서", 20);
	}
	if (num == 0) {
		TextOut(*memDC, x + 60, y + 45, "공격력 +10", 10);
		TextOut(*memDC, x + 288, y + 45, "공격력 +10%", 11);
		TextOut(*memDC, x + 510, y + 45, "강화 +1", 7);
		TCHAR str4[20];
		wsprintf(str4, TEXT("현재확률:%d"), percent);
		TextOut(*memDC, x+570, y+45, str4, lstrlen(str4));
		if (percent == 100) {
			TextOut(*memDC, x + 662, y + 45, "%", 1);
		}
		else if (percent >= 10) {
			TextOut(*memDC, x + 654, y + 45, "%", 1);
		}
		else {
			TextOut(*memDC, x + 646, y + 45, "%", 1);
		}
	}
	if (b_shop || o_click) {
		TextOut(*memDC, 360, 555, "공격력 +10", 10);
		TCHAR str[20];
		wsprintf(str, TEXT("갯수:%d"), magicordercount[0]);
		TextOut(*memDC, 450, 555, str, lstrlen(str));
		TCHAR str4[20];
		wsprintf(str4, TEXT("성공:%d / 실패:%d"), magicsuccess[0],magicfail[0]);
		TextOut(*memDC, 360, 573, str4, lstrlen(str4));
		TextOut(*memDC, 590, 555, "공격력 +10%", 11);
		TCHAR str2[20];
		wsprintf(str2, TEXT("갯수:%d"), magicordercount[1]);
		TextOut(*memDC, 690, 555, str2, lstrlen(str2));
		TCHAR str5[20];
		wsprintf(str5, TEXT("성공:%d / 실패:%d"), magicsuccess[1], magicfail[1]);
		TextOut(*memDC, 590, 573, str5, lstrlen(str5));
		TextOut(*memDC, 815, 555, "강화 +1", 7);
		TCHAR str3[20];
		wsprintf(str3, TEXT("갯수:%d"), magicordercount[2]);
		TextOut(*memDC, 880, 555, str3, lstrlen(str3));
		TCHAR str6[20];
		wsprintf(str6, TEXT("성공:%d / 실패:%d"), magicsuccess[2], magicfail[2]);
		TextOut(*memDC, 815, 573, str6, lstrlen(str6));
	}
}

void MagicOrderState::Release()
{
}

MagicOrderState::MagicOrderState(int _x,int _y,int n)
{
	x = _x;
	y = _y;
	num = n;
}


MagicOrderState::~MagicOrderState()
{
}
