#pragma once
#include "Textures.h"
#include "Utils.h"
#include "Sprites.h"
#include "Game.h"

#define TILE_MAP_WIDTH 16
#define TILE_MAP_HEIGHT 16

#define TILE_SPRITE_START 1000

class TileMap
{
private:
	int tileSetId;

	int mapWidth, mapHeight;
	int tileWidth, tileHeight;

	int mapRow;
	int mapColumn;
	string mapFile;

	unordered_map<int, int> mapMat;
public:
	TileMap(int id, int mapWidth, int mapHeight, string mapFile, int tileWidth, int tileHeight);
	void LoadTileSet();
	void Render();
	void GetMapSize(int &width, int &height);
};

