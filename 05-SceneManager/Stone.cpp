#include "Stone.h"

#include "debug.h"

CStone::CStone(int id, bool left, bool top, bool right, bool bottom,bool isStation)
{
	sceneId = id;
	canLeft = left;
	canTop = top;
	canRight = right;
	canBottom = bottom;
	isStation = isStation;
}
void CStone::Render()
{
	DebugOut(L">>> Rendered >>> \n");
	RenderBoundingBox();
}
void CStone::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - WORLD_STONE_BBOX_WIDTH / 2;
	top = y - WORLD_STONE_BBOX_HEIGHT / 2;
	right = left + WORLD_STONE_BBOX_WIDTH;
	bottom = top + WORLD_STONE_BBOX_HEIGHT;
}
