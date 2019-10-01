#include "Line.h"



void Line::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	SetLine(&line[0], 0, 563, 400, 563,true);
	SetLine(&line[1], 355, 565, 450, 500, true);
	SetLine(&line[2], 450, 500, 1000, 500, true);
	SetLine(&line[3], 758, 435, 1000, 435, false);
	SetLine(&line[4], 650, 370, 709, 370, false);
	SetLine(&line[5], 0, 305, 580, 305, false);
	SetLine(&line[6], 220, 240, 279, 240, false);
	SetLine(&line[7], 320, 175, 379, 175, false);
	SetLine(&line[8], 420, 110, 1000,110, false);
}

void Line::Progress()
{
}

void Line::Render()
{
	/*
	for (int i = 0; i < 9; i++) {
	
		TCHAR str[100];
		wsprintf(str, TEXT("¼± °ª:(%d,%d,%d,%d,%d)"),line[i].x, line[i].y, line[i].ex, line[i].ey,line[i].isground);
		TextOut(*memDC, 5, 25+i*20, str, lstrlen(str));
	
		MoveToEx(*memDC, line[i].x, line[i].y, NULL);
		LineTo(*memDC, line[i].ex, line[i].ey);
	}*/
}

void Line::Release()
{
}

Line::Line()
{
}


Line::~Line()
{
}
