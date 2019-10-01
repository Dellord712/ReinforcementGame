#include "Monster.h"
#include "BitMapManager.h"


void Monster::Initialize(HDC * _memDC)
{
	memDC = _memDC;
	bitmapDC = CreateCompatibleDC(*memDC);
	myBitMap = BitMapManager::GetInst()->GetBitMap(113);
	SelectObject(bitmapDC, myBitMap);
	x = 870;
	y = 339;
	bx = 2;
	by = 0;
	aniSpeed = 0;
	aniCount = 12;
	Monster_Ani_count = 7;
	diff = Monster2_Height - Monster_Height;
	Mon_transform.x = x;
	Mon_transform.y = y;
	Mon_transform.colliderW = x + Monster_Width;
	Mon_transform.colliderH = y + Monster_Height;
	death = false;
}

void Monster::Progress()
{
	monsterRect.left = Mon_transform.x;
	monsterRect.top = Mon_transform.y+10;
	monsterRect.right = Mon_transform.colliderW-2;
	monsterRect.bottom = Mon_transform.colliderH;
	if (death) {
		if (Monster_Ani_count == 7) {
			bx = 0;
		}
		by = 1;
		Monster_Ani_count = 6;
	}
}

void Monster::Render()
{
	if (aniSpeed >= aniCount) {
		if (bx >= Monster_Ani_count) {
			if (Monster_Ani_count == 7) {
				bx = 2;
			}
		}
		else {
			bx++;
		}
		aniSpeed = 0;
	}
	else {
		aniSpeed++;
	}
	//Rectangle(*memDC,monsterRect.left, monsterRect.top, monsterRect.right,monsterRect.bottom);
	if (by == 0) {
		TransparentBlt(*memDC, Mon_transform.x, Mon_transform.y, Monster_Width, Monster_Height, bitmapDC, bx*Monster_Width, 0, Monster_Width, Monster_Height, RGB(255, 0, 255));
	}
	else {
		TransparentBlt(*memDC, Mon_transform.x, Mon_transform.y-diff, Monster2_Width, Monster2_Height, bitmapDC, bx*Monster2_Width, Monster_Height, Monster2_Width, Monster2_Height, RGB(255, 0, 255));
	}
}

void Monster::Release()
{
}

Monster::Monster()
{
}


Monster::~Monster()
{
}
