#include "BoxHidden.h"
#include "debug.h"

void BoxHidden::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - BOX_HIDDEN_BBOX_WIDTH / 2;
	top = y - BOX_HIDDEN_BBOX_HEIGHT / 2;
	right = left + BOX_HIDDEN_BBOX_WIDTH;
	bottom = top + BOX_HIDDEN_BBOX_HEIGHT;
}

void BoxHidden::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += BOX_HIDDEN_BOX_GRAVITY * dt;
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void BoxHidden::OnNoCollision(DWORD dt)
{
	x += vx + dt;
	y += vy * dt;
}

void BoxHidden::OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
{
	if (!e->obj->IsBlocking()) return;
	if (e->ny < 0 && e->obj->IsBlocking())
	{
		vy = 0;
	}
}
