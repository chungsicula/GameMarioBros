#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
#include "FirePiranhaPlant.h"
#include "Leaf.h"
#include "MushroomGreen.h"
//#include "Koopas.h"


class CPlayScene : public CScene
{
protected:
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;

	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> Pipes;
	vector<LPGAMEOBJECT> Pipes2;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void _ParseSection_MAP(string line);

	void LoadAssets(LPCWSTR assetFile);

public:
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() { return player; }

	void AddItemToQBrick(LPGAMEOBJECT obj, int index) {
		QuestionBrick* QBrick = dynamic_cast<QuestionBrick*>(obj);
		CMario* mario = dynamic_cast<CMario*>(player);
		float BrickX, BrickY;
		obj->GetPosition(BrickX, BrickY);

		if (QBrick->readyInnitItem)
		{
			if (QBrick->Item==2)
			{
				if (mario->GetMarioLevel() == MARIO_LEVEL_SMALL)
				{
					Mushroom* mushroom = new Mushroom(BrickX, BrickY);
					mushroom->SetState(MUSHROOOM_STATE_BEING_INNITED);
					objects[index] = mushroom;
					objects.push_back(QBrick);
				}
				else
				{
					Leaf* leaf = new Leaf(BrickX, BrickY);
					leaf->SetState(LEAF_STATE_INNIT);
					objects.push_back(leaf);
				}
			}
			else if (QBrick->Item == 3) {
				if (mario->GetMarioLevel() == MARIO_LEVEL_RACOON)
				{
					MushroomGreen* mushroomGreen = new MushroomGreen(BrickX, BrickY);
				
					mushroomGreen->SetState(MUSHROOOM_STATE_BEING_INNITED);
					objects[index] = mushroomGreen;
					objects.push_back(QBrick);
				}
			}
			else QBrick->InitCoin = true;

			QBrick->innitItemSuccess = true;

		}
	}

	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};

typedef CPlayScene* LPPLAYSCENE;

