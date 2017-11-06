#include "stdafx.h"
#include "NormalLevel.h"
#include <fstream>

NormalLevel::~NormalLevel()
{
	if (map) delete map;

	DeleteWumpuses();

	DeleteExplorers();
}

void NormalLevel::Load()
{
	ifstream stream(filename);
	string buff;

	map = new Map();

	getline(stream, buff);
	map->Width() = stoi(buff.c_str());
	getline(stream, buff);
	map->Height() = stoi(buff);

	map->Initialize();

	DeleteWumpuses();
	DeleteExplorers();
	wumpuses.clear();
	explorers.clear();

	for (auto i = 0; i < map->Height(); i++)
	{
		getline(stream, buff);
		for (auto x = 0; x < map->Width(); x++)
		{
			auto l = &map->GetLand(x, i);

			switch (buff[x])
			{
			case '-':
				break;
			case 'm':
				wumpuses.push_back(new Wumpus(x, i));
				ToggleFlag(x, i, Land::Stench);
				break;
			case 'c':
				l->type = Map::Chest;
				ToggleFlag(x, i, Land::Glow);
				break;
			case 'h':
				l->type = Map::Hole;
				ToggleFlag(x, i, Land::Breeze);
				break;
			case 'w':
				l->type = Map::Wall;
				break;
			case '1':
				explorers.push_back(new Explorer(x, i, Direction::North, map));
				break;
			case '2':
				explorers.push_back(new Explorer(x, i, Direction::South, map));
				break;
			case '4':
				explorers.push_back(new Explorer(x, i, Direction::West, map));
				break;
			case '8':
				explorers.push_back(new Explorer(x, i, Direction::East, map));
				break;
			}
		}
	}
}

bool NormalLevel::ApplyExplorerPosition(Explorer* explorer) const
{
	auto land = map->GetLand(explorer->X(), explorer->Y());

	if (land.type & Map::Hole) // caiu no buraco
	{
		explorer->ApplyScore(Score::Hole);
		return false;
	}

	if (land.type & Map::Chest)
	{
		explorer->ApplyScore(Score::Chest);
		return true;
	}

	if (land.type & Map::Wall)
	{
		// resolve depois
	}

	return true;
}

void NormalLevel::ToggleFlag(int x, int y, Land::Flags flag) const
{
	auto land = map->GetLand(x - 1, y);	// esquerda
	land.flags = static_cast<Land::Flags>(land.flags ^ flag);

	land = map->GetLand(x + 1, y);		// direita
	land.flags = static_cast<Land::Flags>(land.flags ^ flag);

	land = map->GetLand(x, y - 1);		// cima
	land.flags = static_cast<Land::Flags>(land.flags ^ flag);

	land = map->GetLand(x, y + 1);		// baixo
	land.flags = static_cast<Land::Flags>(land.flags ^ flag);
}

void NormalLevel::Update()
{
	for each (auto wumpus in wumpuses)
	{
		ToggleFlag(wumpus->X(), wumpus->Y(), Land::Stench);
		wumpus->Update();
		ToggleFlag(wumpus->X(), wumpus->Y(), Land::Stench);
	}

	for each (auto explorer in explorers)
	{
		explorer->Update(); // muda de lugar

		// testar colisão com algum wumpus

		ApplyExplorerPosition(explorer);
	}
}

void NormalLevel::Render()
{
	MoveCursor(0, 0);
	for (auto y = 0; y < map->Height(); y++)
	{
		for (auto x = 0; x < map->Width(); x++)
		{
			putchar(map->GetLand(x, y).type);
		}
		putchar('\n');
	}

	for (auto explorer : explorers) explorer->Render();

	for (auto wumpus : wumpuses) wumpus->Render();
}