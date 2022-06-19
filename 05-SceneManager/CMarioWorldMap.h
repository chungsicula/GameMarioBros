#pragma once
#include "GameObject.h"
#include "Stone.h"

#define WORLD_MARIO_BBOX_WIDTH	14
#define WORLD_MARIO_BBOX_HEIGHT	16
#define ID_SPRITE_MARIO_WORLDMAP 100001
class CMarioWorldMap : public CGameObject
{
	CStone* currentStone = NULL;

public:

	CStone* GetCurrentStone() { return currentStone; }
	void SetCurrentStone(CStone* stone) { currentStone = stone; }

	CMarioWorldMap(float x, float y) : CGameObject(x, y)
	{

	}

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void OnCollisionWithStone(CGameObject* obj, vector<LPGAMEOBJECT>* coObjs);
	void GoLeft();
	void GoTop();
	void GoRight();
	void GoBottom();
};
