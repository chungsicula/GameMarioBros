#pragma once
#include "Animations.h"
#include "Sprites.h"
#include "debug.h"
#define BACKGROUND_TYPE	1
#define CURTAIN_TYPE	2
#define MARIO_BROS3_BLACK_TYPE	3
#define MARIO_BROS3_MAIN_TYPE	4


#define ID_SPRITE_BACKGROUND_TYPE	190720
#define ID_SPRITE_CURTAIN_TYPE	180721
#define ID_SPRITE_MARIO_BROS3_BLACK_TYPE	180722
#define ID_SPRITE_MARIO_BROS3_MAIN_TYPE	180723
#define ID_ANI_MARIO_BROS3_NUMBER_TYPE	18072000
#define ID_SPRITE_MARIO_BROS3_CHOOSE_PLAYER1_TYPE	180728
#define ID_SPRITE_MARIO_BROS3_CHOOSE_PLAYER2_TYPE	180729

#define START_Y	8

class ObjectForRenderOverWorld
{
public:
	bool isAllowRender, isAllowUpdate;
	int type;
	float x, y, vx, vy;
	ObjectForRenderOverWorld(float x, float y, int Type)
	{
		this->x = x;
		this->y = y;
		vx = vy = 0;
		isAllowRender = isAllowUpdate = false;
		type = Type;
	}

	void Update(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
		if (type == MARIO_BROS3_BLACK_TYPE)
		{
			if (vy > 0)
			{
				if (y >= 188 / 2)
				{
					vy = 0.0f;
					y = 188.0f / 2;
				}
			}
		}
	}
	void setSpeed(float Vx, float Vy) {
		this->vx = Vx;
		this->vy = Vy;
	}
	void Render()
	{
		if (type == BACKGROUND_TYPE)
		{
			if (CSprites::GetInstance()->Get(ID_SPRITE_BACKGROUND_TYPE))
				CSprites::GetInstance()->Get(ID_SPRITE_BACKGROUND_TYPE)->Draw(x, y);
		}
		else if (type == CURTAIN_TYPE)
		{
			if (CSprites::GetInstance()->Get(ID_SPRITE_CURTAIN_TYPE))
				CSprites::GetInstance()->Get(ID_SPRITE_CURTAIN_TYPE)->Draw(x, y + START_Y);
		}
		else if (type == MARIO_BROS3_BLACK_TYPE)
		{
			if (CSprites::GetInstance()->Get(ID_SPRITE_MARIO_BROS3_BLACK_TYPE))
				CSprites::GetInstance()->Get(ID_SPRITE_MARIO_BROS3_BLACK_TYPE)->Draw(x, y + START_Y);
		}
		else if (type == MARIO_BROS3_MAIN_TYPE)
		{
			if (CSprites::GetInstance()->Get(ID_SPRITE_MARIO_BROS3_MAIN_TYPE))
				CSprites::GetInstance()->Get(ID_SPRITE_MARIO_BROS3_MAIN_TYPE)->Draw(x, y + START_Y);
		}
		
	}
};

