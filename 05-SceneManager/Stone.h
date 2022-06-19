#pragma once
#include "GameObject.h"

#define WORLD_STONE_BBOX_WIDTH	8
#define WORLD_STONE_BBOX_HEIGHT	8

class CStone : public CGameObject
{
	int sceneId;
public:
	bool canLeft, canTop, canRight, canBottom;
	float GetX() {
		return x;
	}
	float GetY() {
		return y;
	}
	CStone(int id, bool left, bool top, bool right, bool bottom);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {};
	void Render();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);

};