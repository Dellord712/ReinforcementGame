#pragma once
#include "Obj.h"
class Number : public Obj
{
private:
	int hour;
	int min,w_min;
	int sec,w_sec;
	int milisec, w_milisec;
	double limit_min;
	static int bx1, bx2, bx3, bx4;
	static int stop_time;
	static int s_hour,s_min, s_sec, s_milisec;
	static int e_hour, e_min, e_sec, e_milisec;
	static int overtime;
	int save_bx1,save_bx2,save_bx3,save_bx4;
private:
	void GetTime();
	void GetWTime();
	void GetStopTime();
	void GetReStartTime();
public:
	virtual void Initialize(HDC* _memDC);
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Number();
	~Number();
};

