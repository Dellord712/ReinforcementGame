#pragma once
#include "Include.h"
class BitMapManager
{
private:
	static BitMapManager* pInst;
public:
	static BitMapManager* GetInst()
	{
		if (pInst == nullptr)
		{
			pInst = new BitMapManager;
		}

		return pInst;
	}
private:
	HINSTANCE* g_hInst;
public:
	void SethInstance(HINSTANCE* hInstance);
	HBITMAP GetBitMap(int index);
public:
	BitMapManager();
	~BitMapManager();
};