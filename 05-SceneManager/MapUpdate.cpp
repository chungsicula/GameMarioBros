#include "MapUpdate.h"
#include "Camera.h"
#include"debug.h"

MapUpdate::MapUpdate(int ID, LPCWSTR FilePath_data, int Map_rows, int  Map_cols, int Num_row_tex, int Num_col_tex, int Tile_width, int Tile_height)
{
	this->Id = ID;
	this->MapFilePath = FilePath_data;
	this->NumRowsMapRender = Map_rows;
	this->NumColsMapRender= Map_cols;
	this->numrowtexture = Num_row_tex;
	this->numcoltexture = Num_col_tex;
	this->Tile_Width = Tile_width;
	this->Tile_Height = Tile_height;

	LoadMap();
	Load();
}
void MapUpdate::Load()
{
	ifstream f;
	f.open(MapFilePath);
	if (f.fail())
	{
		f.close();
		return;
	}
	for (int i = 0; i < NumRowsMapRender; i++)
	{
		for (int j = 0; j < NumColsMapRender; j++)
			f >> tilemap[i][j];
	}

	
	f.close();
}

void MapUpdate::LoadMap()
{
	CTextures* texture = CTextures::GetInstance();
	LPTEXTURE texMap = texture->Get(Id);
	int id_sprite = 1;
	for (int i = 0; i < numrowtexture; i++)
	{
		for (int j = 0; j < numcoltexture; j++)
		{
			int id_Sprite = Id + id_sprite;
			sprites->Add(id_Sprite, 16 * j, 16 * i, 16 * (j + 1), 16 * (i + 1), texMap);
			id_sprite = id_sprite + 1; //update id
		}
	}

}

void MapUpdate::Draw()
{
	if (!IsWorldMap) //check world map
	{
		int beginVertical = (int)Camera::GetInstance()->GetCamPosX() / 16;
		if (beginVertical < 0) { beginVertical = 0; }
		int endVertical = ((int)Camera::GetInstance()->GetCamPosX() + CGame::GetInstance()->GetBackBufferWidth()) / 16+1;

		int beginHorizon = (int)Camera::GetInstance()->GetCamPosY() / 16;
		int endHorizon = ((int)Camera::GetInstance()->GetCamPosY() + CGame::GetInstance()->GetBackBufferWidth()) / 16+1;
		for (int i = beginHorizon; i < endHorizon; i++)
		{
			for (int j = beginVertical; j < endVertical; j++)
			{
				float x = 16 * (float)j + 16 / 2;
				float y = 16 * (float)i + 16 / 2;
				if (tilemap[i][j])
					sprites->Get(tilemap[i][j] + Id)->Draw(x, y);
			}
		}
	}
	

}


MapUpdate::~MapUpdate()
{
}