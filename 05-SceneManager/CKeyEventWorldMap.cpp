#include "CKeyEventWorldMap.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "OverWorldScene.h"
#include "Camera.h"

void CKeyEventWorldMap::OnKeyDown(int KeyCode)
{

	CMario* mario = (CMario*)((LPPLAYSCENEE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	switch (KeyCode)
	{
	
	case DIK_1:
		CGame::GetInstance()->SwitchSceneUpdate(2);
		break;
	default:
		break;
	}
}
