#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include "BitMapManager.h"
#include "Menu.h"

int Number::stop_time = 0;
int Number::s_hour = 0;
int Number::s_min = 0;
int Number::s_sec = 0;
int Number::s_milisec = 0;
int Number::e_hour = 0;
int Number::e_min = 0;
int Number::e_sec = 0;
int Number::e_milisec = 0;
int Number::bx1 = 0;
int Number::bx2 = 0;
int Number::bx3 = 0;
int Number::bx4 = 0;
int Number::overtime = 0;
void Number::GetTime()
{
	struct timeb timebuffer;
	struct tm *curr_tm;
	time_t ltime;
	int mili;
	ftime(&timebuffer);
	ltime = timebuffer.time;
	mili= timebuffer.millitm;
	curr_tm = localtime(&ltime);
	hour = curr_tm->tm_hour;
	min = curr_tm->tm_min;
	sec = curr_tm->tm_sec;
	milisec = mili/100;
}

void Number::GetWTime()
{
	struct timeb timebuffer;
	struct tm *curr_tm;
	time_t ltime;
	int mili;
	ftime(&timebuffer);
	ltime = timebuffer.time;
	mili = timebuffer.millitm;
	curr_tm = localtime(&ltime);
	if (hour-curr_tm->tm_hour==23) {
		diff = 36000 * (24 - hour) + 600 * (curr_tm->tm_min - min) + 10*(curr_tm->tm_sec - sec)+(mili/100-milisec/100);
	}
	else {
		diff = 36000 * (curr_tm->tm_hour - hour) + 600 * (curr_tm->tm_min - min) + 10*(curr_tm->tm_sec - sec) + (mili/100 - milisec/100);
	}
	w_min =((int)(limit_min * 600) +overtime-diff)/ 600;
	w_sec =((int)(limit_min * 600) +overtime - diff) /10-w_min*60;
	w_milisec = ((int)(limit_min * 600)+ overtime - diff) % 10;
}

void Number::GetStopTime()
{
	struct timeb timebuffer;
	struct tm *curr_tm;
	time_t ltime;
	int mili;
	ftime(&timebuffer);
	ltime = timebuffer.time;
	mili = timebuffer.millitm;
	curr_tm = localtime(&ltime);
	s_hour = curr_tm->tm_hour;
	s_min = curr_tm->tm_min;
	s_sec = curr_tm->tm_sec;
	s_milisec = mili / 100;
}

void Number::GetReStartTime()
{
	struct timeb timebuffer;
	struct tm *curr_tm;
	time_t ltime;
	int mili;
	ftime(&timebuffer);
	ltime = timebuffer.time;
	mili = timebuffer.millitm;
	curr_tm = localtime(&ltime);
	e_hour = curr_tm->tm_hour;
	e_min = curr_tm->tm_min;
	e_sec = curr_tm->tm_sec;
	e_milisec = mili / 100;
}

void Number::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(123);
	SelectObject(bitmapDC, myBitMap);
	GetTime();
	diff = 0;
	limit_min = 1.5;
	x = 207;
	y = 15;
	bx1 = 0;
	bx2 = 0;
	bx3 = 0;
	bx4 = 0;
	stop_time = 0;
	overtime = 10 + stop_time;
}

void Number::Progress()
{
}

void Number::Render()
{
	if (Menu::b_menu&&Menu::time0 == false && Menu::start&&Menu::s_time==false) {
		Menu::s_time = true;
		GetStopTime();
		save_bx1 = bx1;
		save_bx2 = bx2;
		save_bx3 = bx3;
		save_bx4 = bx4;
	}
	if (Menu::e_time) {
		Menu::e_time = false;
		GetReStartTime();
		if (e_hour - s_hour == 23) {
			stop_time =stop_time+ 36000 * (24 - s_hour) + 600 * (e_min - s_min) + 10 * (e_sec - s_sec) + (e_milisec - s_milisec);
		}
		else {
			stop_time=stop_time+36000 * (e_hour-s_hour) + 600 * (e_min - s_min) + 10 * (e_sec - s_sec) + (e_milisec - s_milisec);
		}
		overtime = 10 + stop_time;
	}
	if (Menu::start == false||Menu::mode_limit==false) {
		bx1 = bx2 = bx3 = bx4 = 0;
	}else if (diff<(int)(600*limit_min)+ overtime) {
		GetWTime();
		if (Menu::b_menu == false) {
			bx1 = w_min / 10;
			bx2 = w_min % 10;
			bx3 = w_sec / 10;
			bx4 = w_sec % 10;
		}
		if (diff >= (int)(600 * limit_min)+ overtime) {
			Menu::b_menu = true;
			Menu::time0 = true;
		}
	}
	/*
	TCHAR str[100];
	wsprintf(str, TEXT("%d:%d:%d:%d"), s_min,s_sec,s_milisec,stop_time);
	TextOut(*memDC, 0, 0, str, lstrlen(str));
	TCHAR str2[100];
	wsprintf(str2, TEXT("%d:%d:%d"), e_min, e_sec, e_milisec);
	TextOut(*memDC, 0, 20, str2, lstrlen(str2));
	*/
	TransparentBlt(*memDC, x, y, Number_Width, Number_Height, bitmapDC, bx1*Number_Width, 0, Number_Width, Number_Height, RGB(255, 0, 255));
	TransparentBlt(*memDC, x+40, y, Number_Width, Number_Height, bitmapDC, bx2*Number_Width, 0, Number_Width, Number_Height, RGB(255, 0, 255));
	TransparentBlt(*memDC, x+92, y, Number_Width, Number_Height, bitmapDC, bx3*Number_Width, 0, Number_Width, Number_Height, RGB(255, 0, 255));
	TransparentBlt(*memDC, x+132, y, Number_Width, Number_Height, bitmapDC, bx4*Number_Width, 0, Number_Width, Number_Height, RGB(255, 0, 255));
}

void Number::Release()
{
}

Number::Number()
{
}


Number::~Number()
{
}
