#pragma once
#include "Include.h"
class CollisionMgr
{
public:
	//사각형과 선의 충돌
	bool CollisionCheck(RECT* rect, LINE* line) {
		int rectmid = (rect->left + rect->right) / 2;
		if (line->y == line->ey) {
			if (line->y <= rect->bottom&&line->x<=rectmid&&line->ex>=rectmid){
				return true;
			}
		}
		else {
			if (rect->bottom+5>=((line->ey-line->y)*(rectmid-line->x))/(line->ex-line->x)+line->y&& 
				line->x <= rectmid && line->ex >= rectmid) {
				return true;
			}
		}
		return false;
	}
	//사각형과 사각형의 충돌
	bool CollisionCheck(PRECT rect1, PRECT rect2) {
		if (((rect1->left>=rect2->left&&rect1->left<=rect2->right)||(rect1->right>=rect2->left&&rect1->right<=rect2->right))&&
			((rect1->bottom<=rect2->bottom&&rect1->bottom>=rect2->top)||(rect1->top>=rect2->top&&rect1->top<=rect2->bottom))) {
			return true;
		}
		return false;
	}
public:
	CollisionMgr();
	~CollisionMgr();
};

