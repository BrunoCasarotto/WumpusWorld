#include "stdafx.h"
#include "Map.h"

enum Map::Type : unsigned char;

Map::Map() : width(0), height(0), map(nullptr)
{
}

Map::~Map()
{
	if (map == nullptr)
		return;

	for (auto i = 0; i < height; i++)
	{
		delete[] map[i];
	}

	delete[] map;
}

void Map::Load(string name)
{

}

void Map::Generate()
{

}

Land& Map::GetLand(int x, int y)
{
	static Land garbage;

	if (x >= width || x < 0 || y >= height || y < 0)
		return garbage;

	return map[y][x];
}