#pragma once
#pragma once
#include "Game.h"
#include"Mario.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Coin.h"
#include "Platform.h"
#include "Camera.h"
#include "Map.h"
#include "Goomba.h"
#include "ObjectRender.h"
#define Sequence1MaxTime	1400
#define SequencePlusTime	1500

#define START_RENDER_X 128
#define START_RENDER_Y 94
#define START_RENDER_Y_CHOOSEPLAYER 154
#define START_RENDER_Y_NUMBER 124
#define START_RENDER_Y_BACKGROUND 120

#define CURTAIN_SPEED 0.07f
#define MARIO_BROS_3_BLACK_SPEED 0.25f
#define GREENMARIO_JUMP_SPEED	0.5f
#define GREENMARIO_SPEED_VX_RUN_OUT_SCENE	0.02f
#define REDMARIO_MAXVX	0.15f

#define POINT_TO_JUMP_REDMARIO	150
#define REDMARIO_JUMP_SPEED	0.5f

#define GREENMARIO_OUT_SCENE_X	24
#define GREENMARIO_OUT_SCENE_Y	180

#define SECTION_2	2
#define SECTION_4	4

class IntroScene :
	public CScene
{
protected:
	// A play scene has to have player, right? 

	vector<LPGAMEOBJECT> objects;




	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);


	void LoadAssets(LPCWSTR assetFile);

public:
	CMario* redMario;
	CMario* greenMario;
	
	CPlatform* platform;
	ObjectForRender* background = new ObjectForRender(START_RENDER_X, START_RENDER_Y_BACKGROUND, BACKGROUND_TYPE);
	
	ULONGLONG SequenceTime;
	IntroScene(int id, LPCWSTR filePath);
	bool isDoneSeq1, isDoneSeq2, isFirstJump;
	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
	int i = 1;
	void ScriptIntro()
	{

		if (SequenceTime == 0)
			SequenceTime = GetTickCount64();
		if (!isDoneSeq1)
		{
			if (GetTickCount64() - SequenceTime >= Sequence1MaxTime)
				isDoneSeq1 = true;
			
		
		}
		if (isDoneSeq1 && !isDoneSeq2)
		{
			float vx, vy;
			redMario->GetSpeed(vx, vy);
			if (vx == 0 && i == 1)
			{
				redMario->SetState(MARIO_STATE_WALKING_RIGHT);
				greenMario->SetState(MARIO_STATE_WALKING_LEFT);
			}
			if (GetTickCount64() - SequenceTime >= Sequence1MaxTime + SequencePlusTime && !isFirstJump)
			{
				redMario->SetState(MARIO_STATE_JUMP);
				isFirstJump = true;
			}
			
		}
		
	}
	void Clear();
	void PurgeDeletedObjects();

};

typedef IntroScene* LPINTROSCENE;