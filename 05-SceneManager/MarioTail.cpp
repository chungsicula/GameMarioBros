#include "MarioTail.h"
#include "Goomba.h"
#include "Koopas.h"
#include "PiranhaPlant.h"
void MarioTail::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (IsActive)
	{
		left = x - TAIL_BBOX_WIDTH / 2;
		top = y - TAIL_BBOX_HEIGHT / 2;
		right = x + TAIL_BBOX_WIDTH;
		bottom = y + TAIL_BBOX_HEIGHT;
	}
}

void MarioTail::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	for (int i = 0; i < coObjects->size(); i++)
	{
		if (CCollision::GetInstance()->CheckAABB(this, coObjects->at(i)))
		{
			if (dynamic_cast<CGoomba*>(coObjects->at(i)))
				OnCollisionWithGoomba(coObjects->at(i));
			
			else if (dynamic_cast<Koopas*>(coObjects->at(i)))
				OnCollisionWithKoopas(coObjects->at(i));
			
			else if (dynamic_cast<PiranhaPlant*>(coObjects->at(i)))
			{
				PiranhaPlant* plant = dynamic_cast<PiranhaPlant*>(coObjects->at(i));
				if (!plant->isInPipe)
					plant->Delete();
			}
		}
	}
}

void MarioTail::Render()
{

}

void MarioTail::OnCollisionWithGoomba(LPGAMEOBJECT& obj)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(obj);
	if (goomba->GetState() != GOOMBA_STATE_DIEBYSHELL)
	{
		goomba->nx = nx;
		goomba->SetState(GOOMBA_STATE_DIEBYSHELL);
	}
	IsActive = false;
}



void MarioTail::OnCollisionWithKoopas(LPGAMEOBJECT& obj)
{
	Koopas* koopas = dynamic_cast<Koopas*>(obj);
	koopas->nx = nx;
	if (koopas->level == PARA_KOOPAS) koopas->level = NORMAL_KOOPAS;
	koopas->SetState(KOOPAS_STATE_ATTACKED_BY_TAIL);
	IsActive = false;
}

