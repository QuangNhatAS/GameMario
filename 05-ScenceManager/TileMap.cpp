#include "TileMap.h"

TileMap::TileMap(int id, int mapWidth, int mapHeight, string mapFile, int tileWidth, int tileHeight)
{
	this->tileSetId = id;
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
	this->mapFile = mapFile;
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;

	mapRow = 0;
	mapColumn = 0;
}

void TileMap::LoadTileSet()
{
	CTextures * textures = CTextures::GetInstance();
	LPDIRECT3DTEXTURE9 mapTex = textures->Get(this->tileSetId);

	CSprites *sprites = CSprites::GetInstance();
	for (int j = 0; j < this->tileHeight; j++)
	{
		for (int i = 0; i < this->tileWidth; i++)
		{
			int num = TILE_SPRITE_START + j * 16 + i;
			sprites->Add(num, i * 16, j * 16, i * 16 + 16, j * 16 + 16, mapTex);
			DebugOut(L"id %d l %d t %d r %d b %d", i * 16, j * 16, i * 16 + 16, j * 16 + 16);
		}
	}

	FILE *fileMap;
	char output[400];

	fileMap = fopen(this->mapFile.c_str(), "r");
	int j = 0;
	int i = 0;

	for (j = 0; fgets(output, sizeof(output), fileMap) != NULL; j++)
	{
		char *pch = strtok(output, " ");
		i = 0;
		while (pch != NULL)
		{
			mapMat[j * 100 + i] = atoi(pch);
			DebugOut(L"%d", atoi(pch));
			i++;
			//token = strtok(NULL, " ");
		}
		DebugOut(L"\n");
	}
	mapRow = j;
	mapColumn = i;
}
