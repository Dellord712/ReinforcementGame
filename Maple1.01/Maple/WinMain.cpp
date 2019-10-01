#include "MainGame.h"
#include "Menu.h"
#include "BitMapManager.h"

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
const char* lpszClass = "GAME";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmpParam, int nCmdShow)
{
	HWND hWnd;
	MSG message;
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)wndProc;
	wndClass.lpszClassName = lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW || CS_VREDRAW;

	RegisterClass(&wndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		0, 0,1000, 638,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	DWORD dwTime = GetTickCount();

	BitMapManager::GetInst()->SethInstance(&hInstance);

	MainGame game(&hWnd);
	game.Initialize();
	Menu menu(&hWnd);
	menu.Initialize();
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE|SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (true)
	{
		
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				PostQuitMessage(0);
				break;
			}
			else
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
		else
		{
			if (dwTime +10 < GetTickCount())
			{
				if (GetAsyncKeyState(VK_ESCAPE) & 0x0001&&menu.change==false&&menu.start&&menu.time0==false&&menu.count!=3) {
					if (menu.b_menu) {
						menu.b_menu=false;
						menu.s_time = false;
						menu.e_time = true;
					}
					else {
						menu.b_menu=true;
					}
				}
				if (menu.b_menu) {
					menu.Progress();
					menu.Render();
					if (menu.reaplay) {
						game.Initialize();
						menu.Initialize();
						menu.b_menu = false;
						menu.reaplay = false;
						menu.time0 = false;
						menu.start = true;
					}
				}
				else {
					game.Progress();
					game.Render();
				}
				dwTime = GetTickCount();
			}
		}
	}
	game.Release();
	PlaySound(NULL, 0, 0);
	return message.wParam;
}

LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}