#include "CMarioWorldMap.h"
#include "AssetIDs.h"

void CMarioWorldMap::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	x += vx * dt;
	y += vy * dt;

	for (int i = 0; i < coObjects->size(); i++)
	{
		if (CCollision::GetInstance()->CheckAABB(this, coObjects->at(i)))
		{
			OnCollisionWithStone(coObjects->at(i), coObjects);
		}
	}
}

void CMarioWorldMap::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = ID_SPRITE_MARIO_WORLDMAP;
	animations->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CMarioWorldMap::OnCollisionWithStone(CGameObject* obj, vector<LPGAMEOBJECT>* coObjs)
{
	if (dynamic_cast<CStone*>(obj))
	{
		CStone* stone = dynamic_cast<CStone*>(obj);
		if (currentStone == NULL)
		{
			currentStone = stone;
		}
		if (currentStone == stone)
			return;

		if ((vx > 0 && x >= (stone->x) - 3)||(vx < 0 && x <= (stone->x) - 3))
		{
			vx = 0;
			currentStone = stone; CGame::GetInstance()->InitiateSwitchScene(2);
		}
		if ((vy > 0 && y >= (stone->y) - 3)|| (vy < 0 && y <= (stone->y) - 3))
		{
			vy = 0;
			currentStone = stone; CGame::GetInstance()->InitiateSwitchScene(2);
		}
	}
}

void CMarioWorldMap::GoLeft()
{
	if (currentStone->canLeft && vx == 0 && vy == 0)
	{
		vx = -0.12f;
	}
}

void CMarioWorldMap::GoTop()
{
	if (currentStone->canTop && vx == 0 && vy == 0)
	{
		vy = -0.12f;
	}
}

void CMarioWorldMap::GoRight()
{
	if (currentStone->canRight && vx == 0 && vy == 0)
	{
		vx = 0.12f;
	}
}

void CMarioWorldMap::GoBottom()
{
	if (currentStone->canBottom && vx == 0 && vy == 0)
	{
		vy = 0.12f;
	}
}

void CMarioWorldMap::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = this->x;
	t = this->y;
	r = l + WORLD_MARIO_BBOX_WIDTH;
	b = t + WORLD_MARIO_BBOX_HEIGHT;
}
