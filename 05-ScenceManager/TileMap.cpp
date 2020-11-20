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
			DebugOut(L"id %d l %d t %d r %d b %d \n", i * 16, j * 16, i * 16 + 16, j * 16 + 16);
		}
	}

	FILE *fileMap;
	char output[600];

	fileMap = fopen(this->mapFile.c_str(), "r");
	int j = 0;
	int i = 0;

	for (j = 0; fgets(output, sizeof(output), fileMap) != NULL; j++)
	{
		char *pch = strtok(output, " ");
		i = 0;
		while (pch != NULL)
		{
			mapMat[j * 1000 + i] = atoi(pch);
			DebugOut(L"%d ", atoi(pch));
			i++;
			pch = strtok(NULL, " ");
		}
		DebugOut(L"\n");
	}
	mapRow = j;
	mapColumn = i;
}

void TileMap::Render()
{
	CSprites *sprites = CSprites::GetInstance();
	float camposX;
	float camposY;
	CGame::GetInstance()->GetCamPos(camposX, camposY);

	camposX = camposX / 16;
	camposY = camposY / 16;

	float camposX2 = camposX + (SCREEN_WIDTH / 16);
	float camposY2 = camposY + (SCREEN_HEIGHT / 16);
	if (camposX < 0) camposX = 0;
	if (camposY < 0) camposY = 0;

	for (int i = ceil(camposY) - 2; i < ceil(camposY2) - 1; i++)
	{
		for (int j = floorf(camposX); j < ceil(camposX2); j++)
		{
			sprites->Get(TILE_SPRITE_START + mapMat[i * 1000 + j])->Draw(j * 16, i * 16);
		}
	}
}

void TileMap::GetMapSize(int & width, int & height)
{
	width = mapColumn * TILE_MAP_WIDTH;
	height = mapRow * TILE_MAP_HEIGHT;
}
