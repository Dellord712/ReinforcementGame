#include "Background.h"
#include "BitMapManager.h"
#include "Menu.h"

void Background::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(101);
	SelectObject(bitmapDC, myBitMap);
}

void Background::Progress()
{
	
}

void Background::Render()
{
	if (max_value <= value&&Menu::mode_limit&&Menu::b_menu==false) {
		max_value = value;
		max_offensepower = offensepower;
		max_reinforce = reinforce;
	}
	TransparentBlt(*memDC, 0, 0, Background_Width , Background_Height, bitmapDC, 0, 338, Background_Width , Background_Height, RGB(255, 0, 255));
	TCHAR str[100];
	wsprintf(str, TEXT("최고의 가치 : %d    현재의 가치 : %d"), max_value, value);
	TCHAR str2[100];
	wsprintf(str2, TEXT("최고의 공격력 : %d(%d강)"), max_offensepower, max_reinforce);
	if (Menu::start) {
		TextOut(*memDC, 400, 10, str, lstrlen(str));
		TextOut(*memDC, 400, 30, str2, lstrlen(str2));
	}
}

void Background::Release()
{
}

Background::Background()
{
}


Background::~Background()
{
}
