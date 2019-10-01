#include "BitMapManager.h"

BitMapManager* BitMapManager::pInst = nullptr;

void BitMapManager::SethInstance(HINSTANCE * hInstance)
{
	if (g_hInst == nullptr)
	{
		g_hInst = hInstance;
	}
}

HBITMAP BitMapManager::GetBitMap(int index)
{
	return  LoadBitmap(*g_hInst, MAKEINTRESOURCE(index));
}

BitMapManager::BitMapManager()
{
	g_hInst = nullptr;
}


BitMapManager::~BitMapManager()
{
}