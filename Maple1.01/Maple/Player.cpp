#include "Player.h"
#include "BitMapManager.h"


void Player::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(107);
	SelectObject(bitmapDC, myBitMap);
	transform.colliderW = Player_Width;
	transform.colliderH = Player_Height;

	x = 0;
	y = 500;
	bx = 0;
	by = 0;
	aniSpeed = 0;
	aniCount = 12;
	h = 0.0;
	right = 0;
	shapechange = 0;
	move = true;
	jump = false;
	isGrounded = false;
	crash = false;
	currentY = y;
	SetPosition(x, y);
	bx0 = true;
	attack = false;
}

void Player::Progress()
{
	by = 0;
	attack = false;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000&&move)
	{
		SetPosX(transform.x - 3);
		by = 2;
		right = 0;
		diff = Player3_Width - Player_Width;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000&&move)
	{
		SetPosX(transform.x + 3);
		by = 2;
		right = 1;
		diff = 0;
	}
	
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_SPACE) & 0x8000) {

	}
	else if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !jump&&move&&!jumping)
	{
		by = 1;
		bx = 0;
		currentY = y;
		t = 0.0;
		h = 0.0;
		jump = true;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000&&!jump) {
		move = false;
		shapechange = 1;
		if (GetAsyncKeyState(VK_LCONTROL) & 0x8000) {
			attack = true;
			bx = 1;
		}
		else {
			bx = 0;
		}

		if (right == 0) {
			by = 3;
		}
		else {
			by = 4;
		}
	}
	else {
		move = true;
		shapechange = 0;
	}
	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000&&move) {
		attack = true;
		shapechange = 2;
		by = 5;
		aniCount = 6;
		move = false;
		if (bx0) {
			bx = 0;
			bx0 = false;
		}
	}
	else {
		aniCount = 12;
		bx0 = true;
	}

	if (crash) {
		move = false;
		SetPosX(transform.x - 100);
		crash = false;
	}

	if (jump) {
		by = 1;
		t += 0.25;
		h = Vo * sin(90 * PI / 180) * t - 0.5 * Gravity * t * t;
		SetPosY(currentY - (int)h);
	}
	else{
		if (isGrounded)
		{
			jumping = false;
			t = 0.0;
		}
		else
		{
			shapechange = 0;
			jumping = true;
			by = 1;
			bx = 0;
			t += 0.08;
		}

		h = 0.5 * Gravity * t * t;
		SetPosY(transform.y + (int)h);
	}

	CalculateColliderRect();
}

void Player::Render()
{
	if (aniSpeed >= aniCount) {
		switch (by)
		{
		case 0:
			if (bx >= PLAYER_ANI_COUNT) {
				bx = 0;
			}
			else {
				bx++;
			}
			break;
		case 2:
			if (bx >= PLAYER_ANI_COUNT2) {
				bx = 0;
			}
			else {
				bx++;
			}
			break;
		case 5:
			if (bx >= 8) {
				bx = 0;
			}
			else {
				bx++;
			}
			break;
		default:
			break;
		}
		aniSpeed = 0;
	}
	else {
		aniSpeed++;
	}
	if (bx > PLAYER_ANI_COUNT && by == 0) {
		bx = 0;
	}
	/*
	TCHAR str[100];
	wsprintf(str, TEXT("캐릭터 좌표값(L,U,R,D)=(%d,%d,%d,%d)"), colliderRect.left, colliderRect.top, colliderRect.right, colliderRect.bottom);
	TextOut(*memDC, 5, 5, str, lstrlen(str)); */
	//Rectangle(*memDC, colliderRect.left, colliderRect.top, colliderRect.right, colliderRect.bottom);
	if (shapechange == 0) {
		TransparentBlt(*memDC, transform.x, transform.y, Player_Width, Player_Height, bitmapDC, bx*Player_Width, (by + 3 * right)*Player_Height, Player_Width, Player_Height, RGB(255, 0, 255));
	}
	else if (shapechange == 1) {
		TransparentBlt(*memDC, transform.x, transform.y+40, Player2_Width, Player2_Height, bitmapDC, bx*Player2_Width, 480+(by-3)*Player2_Height, Player2_Width, Player2_Height, RGB(255, 0, 255));
	}
	else if(shapechange==2){
		TransparentBlt(*memDC, transform.x-diff, transform.y,Player3_Width, Player3_Height, bitmapDC, bx*Player3_Width,560+right*Player3_Height, Player3_Width, Player3_Height, RGB(255, 0, 255));
	}
}


void Player::Release()
{
}


Player::Player()
{
}


Player::~Player()
{
}
