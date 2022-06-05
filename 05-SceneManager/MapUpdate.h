
#pragma once

#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Sprites.h"
#include "Textures.h"
#include "Game.h"


class MapUpdate
{
	CSprites* sprites = CSprites::GetInstance();
	LPCWSTR MapFilePath; //url texture map
	int NumRowsMapRender, NumColsMapRender; // number row column map render 
	int numrowtexture, numcoltexture; //number of row column map texture
	int Tile_Width, Tile_Height;
	int Id;

	int tilemap[300][300];

public:
	bool IsWorldMap; //check world map
	MapUpdate(int ID, LPCWSTR FilePath_data, int NumRowMap, int  NumColumnMap, int NumRowTex, int NumColumnTex, int map_width = 16, int map_height = 16);
	~MapUpdate();
	void Load();
	void LoadMap();
	void Draw();
	int GetMapWidth() { return NumColsMapRender * Tile_Width; }
	int GetMapHeight() { return NumRowsMapRender * Tile_Height + 50; } //add space brick
};


