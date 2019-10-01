#include "Menu.h"
#include "Background.h"
#include "Blocks.h"
#include "Player.h"
#include "Line.h"
#include "Shop.h"
#include "Monster.h"
#include "WeaponState.h"
#include "Clock.h"
#include "Number.h"
#include "MagicOrderState.h"
#include "Menuboard.h"

bool Menu::b_menu = true;
bool Menu::reaplay = false;
bool Menu::time0 = false;
bool Menu::start = false;
bool Menu::s_time = false;
bool Menu::e_time = false;
bool Menu::mode_limit = true;
void Menu::Initialize()
{
	hdc = GetDC(*hWnd);
	memDC = CreateCompatibleDC(hdc);
	GetClientRect(*hWnd, &crt);
	myBitMap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);
	(HBITMAP)SelectObject(memDC, myBitMap);

	background = new Background;
	background->Initialize(&memDC);
	block1 = new Blocks(750, 430, 1);
	block1->Initialize(&memDC);
	block2 = new Blocks(-20, 300, 2);
	block2->Initialize(&memDC);
	block2_2 = new Blocks(420, 105, 2);
	block2_2->Initialize(&memDC);
	block3 = new Blocks(0, 495, 3);
	block3->Initialize(&memDC);
	block4 = new Blocks(800, 530, 4);
	block4->Initialize(&memDC);
	block4_2 = new Blocks(600, 530, 4);
	block4_2->Initialize(&memDC);
	block5 = new Blocks(650, 365, 5);
	block5->Initialize(&memDC);
	block5_2 = new Blocks(220, 235, 5);
	block5_2->Initialize(&memDC);
	block5_3 = new Blocks(320, 170, 5);
	block5_3->Initialize(&memDC);
	magicorderstate2 = new MagicOrderState(300, 518, 1);
	magicorderstate2->Initialize(&memDC);
	clock = new Clock;
	clock->Initialize(&memDC);
	time = new Number;
	time->Initialize(&memDC);
	menuboard = new Menuboard;
	menuboard->Initialize(&memDC);
	count = 0;
	x = 400;
	y = 50;
	s_time = false;
	e_time = false;
	change = false;
	putf1 = false;
}

void Menu::Progress()
{
	if (((time0 || start == false) && count == 2) || count == 3) {
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {
			if (mode_limit&&change == false) {
				change = true;
			}
			else if (mode_limit&&change) {
				change = false;
			}
			mode_limit = false;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x0001) {
			if (mode_limit == false && change == false) {
				change = true;
			}
			else if (mode_limit == false && change) {
				change = false;
			}
			mode_limit = true;
		}
	}
	if (time0 || start == false) {
		if (mode_limit) {
			menuboard->menu_y = 0;
		}
		else {
			menuboard->menu_y = 1;
		}
		if (GetAsyncKeyState(VK_UP) & 0x0001) {
			if (count == 0) {

			}
			else {
				menuboard->menu_x--;
				count--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			if (count == 2) {

			}
			else {
				menuboard->menu_x++;
				count++;
			}
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
			switch (count)
			{
			case 0:
				reaplay = true;
				break;
			case 1:
				exit(0);
				break;
			default:
				break;
			}
		}
	}
	else {
		if (mode_limit) {
			menuboard->menu_y = 2;
		}
		else {
			menuboard->menu_y = 3;
		}
		if (GetAsyncKeyState(VK_UP) & 0x0001) {
			if (count == 0) {

			}
			else if (count == 1 && change) {

			}
			else {
				menuboard->menu_x--;
				count--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			if (count == 3) {

			}
			else {
				menuboard->menu_x++;
				count++;
			}
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
			switch (count)
			{
			case 0:
				s_time = false;
				e_time = true;
				b_menu = false;
				break;
			case 1:
				reaplay = true;
				break;
			case 2:
				exit(0);
				break;
			default:
				break;
			}
		}
	}
	if (GetAsyncKeyState(VK_F1) & 0x0001) {
		if (putf1) {
			putf1 = false;
		}
		else {
			putf1 = true;
		}
	}
	menuboard->Progress();
}

void Menu::Render()
{
	FillRect(memDC, &crt, (HBRUSH)GetStockObject(WHITE_BRUSH));
	background->Render();
	block1->Render();
	block3->Render();
	block2->Render();
	block2_2->Render();
	block4->Render();
	block4_2->Render();
	block5->Render();
	block5_2->Render();
	block5_3->Render();
	clock->Render();
	time->Render();
	menuboard->Render();
	if (time0 || start == false) {
		if (start) {
			Obj::o_click = true;
		}
		magicorderstate2->Render();
		TCHAR str[30];
		wsprintf(str, TEXT("������ġ : %d"), Obj::GetValue());
		if (start) {
			TextOut(memDC, x, y, str, lstrlen(str));
		}
	}
	else {
		magicorderstate2->Render();
	}
	TextOut(memDC, 10, 10, "<����(F1)>", lstrlen("<����(F1)>"));
	if (putf1) {
		TextOut(memDC, 10, 26, "�̵� : ��,��", lstrlen("�̵� : ��,��"));
		TextOut(memDC, 10, 42, "���� : ��", lstrlen("���� : ��"));
		TextOut(memDC, 10, 58, "���� : space", lstrlen("���� : space"));
		TextOut(memDC, 10, 74, "�Ʒ����� : space +��", lstrlen("�Ʒ����� : space +��"));
		TextOut(memDC, 10, 90, "���� : ctrl", lstrlen("���� : ctrl"));
		TextOut(memDC, 10, 106, "�������ݱ� : A", lstrlen("�������ݱ� : A"));
		TextOut(memDC, 10, 122, "�������� : S", lstrlen("�������� : S"));
		TextOut(memDC, 10, 138, "�Һ�â���� : I", lstrlen("�Һ�â���� : I"));
		TextOut(memDC, 10, 154, "���â���� : U", lstrlen("���â���� : U"));
		TextOut(memDC, 10, 170, "�ֹ���â���� : O", lstrlen("�ֹ���â���� : O"));
		TextOut(memDC, 10, 186, "<�߰�����>", lstrlen("<�߰�����>"));
		TextOut(memDC, 10, 202, "����:PC-WinAPI.1.1", lstrlen("����:PC-WinAPI.1.1"));
		TextOut(memDC, 10, 218, "������ : �����", lstrlen("������ : �����"));
		TextOut(memDC, 10, 234, "������Ʈ��¥ : 2019-09-20", lstrlen("������Ʈ��¥ : 2019-09-20"));

	}
	BitBlt(hdc, crt.left, crt.top, crt.right, crt.bottom, memDC, 0, 0, SRCCOPY);
}

void Menu::Release()
{
	DeleteDC(memDC);
	ReleaseDC(*hWnd, hdc);
}

Menu::Menu(HWND* _hWnd)
{
	hWnd = _hWnd;
}


Menu::~Menu()
{
}
