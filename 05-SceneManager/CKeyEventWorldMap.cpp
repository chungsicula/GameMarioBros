#include "CKeyEventWorldMap.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "OverWorldScene.h"
#include "Camera.h"
#include "CMarioWorldMap.h"

void CKeyEventWorldMap::OnKeyDown(int KeyCode)
{

	

	CMarioWorldMap* mario = (CMarioWorldMap*)((LPPLAYSCENEE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	switch (KeyCode)
	{
	case DIK_LEFT:
		mario->GoLeft();
		break;
	case DIK_UP:
		mario->GoTop();
		break;
	case DIK_RIGHT:
		mario->GoRight();
		break;
	case DIK_DOWN:
		mario->GoBottom();
		break;
	case DIK_S:
		CGame::GetInstance()->InitiateSwitchScene(2);
		break;
	default:
		break;
	}
}
