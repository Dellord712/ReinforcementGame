#include "MainGame.h"
#include "Background.h"
#include "Blocks.h"
#include "Player.h"
#include "Line.h"
#include "Shop.h"
#include "Monster.h"
#include "ShopState.h"
#include "ItemInventory.h"
#include "MagicOrder.h"
#include "MagicOrderState.h"
#include "WeaponState.h"
#include "Weapon.h"
#include "EnhancedMotion.h"
#include "Meso.h"
#include "Weapon2.h"
#include "MagicOrder2.h"
#include "Clock.h"
#include "Number.h"
#include "Menu.h"

void MainGame::Initialize()
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
	block2 = new Blocks(-20,300,2);
	block2->Initialize(&memDC);
	block2_2 = new Blocks(420, 105,2);
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

	player = new Player;
	player->Initialize(&memDC);
	line = new Line;
	line->Initialize(&memDC);
	shop = new Shop;
	shop->Initialize(&memDC);
	boss = new Monster;
	boss->Initialize(&memDC);
	shopstate = new ShopState;
	shopstate->Initialize(&memDC);
	iteminven = new ItemInventory;
	iteminven->Initialize(&memDC);
	u_click = false;
	i_click = false;

	magicOrder1 = new MagicOrder(26,70,0);
	magicOrder1->Initialize(&memDC);
	magicOrder2 = new MagicOrder(62, 70, 1);
	magicOrder2->Initialize(&memDC);
	magicOrder3 = new MagicOrder(98, 70, 2);
	magicOrder3->Initialize(&memDC);
	magicorderstate = new MagicOrderState(16,100,0);
	magicorderstate->Initialize(&memDC);
	magicorderstate2 = new MagicOrderState(300, 518, 1);
	magicorderstate2->Initialize(&memDC);
	weaponstate = new WeaponState;
	weaponstate->Initialize(&memDC);
	weapon = new Weapon;
	weapon->Initialize(&memDC);
	enhanced = new EnhancedMotion;
	enhanced->Initialize(&memDC);
	meso = new Meso;
	meso->Initialize(&memDC);
	weapon2 = new Weapon2;
	weapon2->Initialize(&memDC);
	magicorder1 = new MagicOrder2(0);
	magicorder1->Initialize(&memDC);
	magicorder2 = new MagicOrder2(1);
	magicorder2->Initialize(&memDC);
	magicorder3 = new MagicOrder2(2);
	magicorder3->Initialize(&memDC);
	clock = new Clock;
	clock->Initialize(&memDC);
	time = new Number;
	time->Initialize(&memDC);
	
}

void MainGame::Progress()
{
	player->Progress();
	boss->Progress();
	magicOrder1->Progress();
	magicOrder2->Progress();
	magicOrder3->Progress();
	shopstate->Progress();
	weaponstate->Progress();
	magicorderstate2->Progress();
	if (boss->death) {
		meso->Progress();
		weapon2->Progress();
		magicorder1->Progress();
		magicorder2->Progress();
		magicorder3->Progress();
	}
	
	if (player->GetColliderRect()->bottom < 110) {
		line->GetLine(8)->isground = true;
		count = 8;
	}
	else if (player->GetColliderRect()->bottom < 175 && player->GetColliderRect()->bottom > 140) {
		line->GetLine(7)->isground = true;
		line->GetLine(8)->isground = false;
		count = 7;
	}
	else if (player->GetColliderRect()->bottom < 240 && player->GetColliderRect()->bottom > 205) {
		line->GetLine(6)->isground = true;
		line->GetLine(7)->isground = false;
		count = 6;
	}
	else if (player->GetColliderRect()->bottom < 305 && player->GetColliderRect()->bottom > 270) {
		line->GetLine(5)->isground = true;
		line->GetLine(6)->isground =false;
		count = 5;
	}
	else if (player->GetColliderRect()->bottom < 370 && player->GetColliderRect()->bottom >335) {
		line->GetLine(4)->isground = true;
		line->GetLine(5)->isground = false;
		count = 4;
	}
	else if (player->GetColliderRect()->bottom < 435&& player->GetColliderRect()->bottom > 400) {
		line->GetLine(3)->isground = true;
		line->GetLine(4)->isground = false;
		count = 3;
	}
	else if (player->GetColliderRect()->bottom > 470) {
		line->GetLine(3)->isground = false;
		count = 3;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_SPACE) & 0x8000&&player->isGrounded==true) {
		line->GetLine(count)->isground = false;
	}

	if (GetAsyncKeyState(0x49) & 0x0001) {
		if (i_click) {
			i_click = false;
		}
		else {
			iteminven->Progress();
			i_click = true;
			u_click = false;
		}
	}

	if (GetAsyncKeyState(0x55) & 0x0001) {
		if (u_click) {
			u_click = false;
		}
		else {
			iteminven->Progress();
			u_click = true;
			i_click = false;
		}
	}
}

void MainGame::Render()
{
	enhanced->SetPlayPosition(player->GetColliderRect());
	meso->SetPlayPosition2(player->GetColliderRect());
	magicorder1->SetPlayPosition2(player->GetColliderRect());
	magicorder2->SetPlayPosition2(player->GetColliderRect());
	magicorder3->SetPlayPosition2(player->GetColliderRect());
	weapon2->SetPlayPosition2(player->GetColliderRect());
	bool collider = false;
	for (int i = 0; i < 9; i++) {
		if (CollisionCheck(player->GetColliderRect(), line->GetLine(i)) && line->GetLine(i)->isground == true) {
			collider = true;
			if (i != 1) {
				player->SetPosY(line->GetLine(i)->y - Player_Height);
				player->SetY(line->GetLine(i)->y - Player_Height);
			}
			else {
				int rectmid = (player->GetColliderRect()->left + player->GetColliderRect()->right) / 2;
				player->SetPosY(((line->GetLine(i)->ey - line->GetLine(i)->y)*(rectmid - line->GetLine(i)->x)) / (line->GetLine(i)->ex - line->GetLine(i)->x) + line->GetLine(i)->y - Player_Height);
				player->SetY(((line->GetLine(i)->ey - line->GetLine(i)->y)*(rectmid - line->GetLine(i)->x)) / (line->GetLine(i)->ex - line->GetLine(i)->x) + line->GetLine(i)->y - Player_Height);
			}
		}
	}
	
	if (collider)
	{
		player->jump = false;
		player->isGrounded = true;
	}
	else
	{
		player->isGrounded = false;
	}
	
	if (CollisionCheck(player->GetColliderRect(), boss->GetMonsterRect())) {
		//TextOut(hdc, 5, 50, "Ãæµ¹", 4);
		//player->Crash();
	}

	if (((player->GetColliderRect()->right >= 855&&player->right==1)||(player->GetColliderRect()->right >= 900 && player->right == 0)) 
		&& player->GetColliderRect()->bottom <= 435
		&& player->GetColliderRect()->bottom >= 370 && player->attack == true) {
		boss->death = true;
	}
	FillRect(memDC, &crt, (HBRUSH)GetStockObject(WHITE_BRUSH));
	background->Render();
	clock->Render();
	time->Render();
	block1->Render();
	block3->Render();
	block2->Render();
	block2_2->Render();
	block4->Render();
	block4_2->Render();
	block5->Render();
	block5_2->Render();
	block5_3->Render();
	boss->Render();
	player->Render();
	line->Render();
	shop->Render();
	shopstate->Render();
	enhanced->Render();
	magicorderstate2->Render();
	if (boss->death) {
		meso->Render();
		magicorder1->Render();
		magicorder2->Render();
		magicorder3->Render();
		weapon2->Render();
	}
	
	if (u_click || i_click) {
		iteminven->Render();
		if (i_click) {
			magicOrder1->Render();
			magicOrder2->Render();
			magicOrder3->Render();
			magicorderstate->Render();
		}
		if (u_click) {
			weaponstate->Render();
			weapon->Render();
		}
	}
	
	BitBlt(hdc, crt.left, crt.top, crt.right, crt.bottom, memDC, 0, 0, SRCCOPY);
}

void MainGame::Release()
{
	DeleteDC(memDC);
	ReleaseDC(*hWnd, hdc);
}

MainGame::MainGame(HWND * _hWnd)
{
	hWnd = _hWnd;
}

MainGame::~MainGame()
{
}