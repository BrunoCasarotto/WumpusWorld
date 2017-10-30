#include "stdafx.h"
#include "NormalLevel.h"

NormalLevel::~NormalLevel()
{
	if (map) delete map;

	if (wumpuses.size()) for each (auto wumpus in wumpuses) delete wumpus;

	if (explorers.size()) for each (auto explorer in explorers) delete explorer;
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

void NormalLevel::ToggleWumpusFlag(Wumpus* wumpus)
{
	auto land = map->GetLand(wumpus->X() - 1, wumpus->Y());	// esquerda
	land.flags = static_cast<Land::Flags>(land.flags ^ Land::Stench);

	land = map->GetLand(wumpus->X() + 1, wumpus->Y());		// direita
	land.flags = static_cast<Land::Flags>(land.flags ^ Land::Stench);

	land = map->GetLand(wumpus->X(), wumpus->Y() - 1);		// cima
	land.flags = static_cast<Land::Flags>(land.flags ^ Land::Stench);

	land = map->GetLand(wumpus->X(), wumpus->Y() + 1);		// baixo
	land.flags = static_cast<Land::Flags>(land.flags ^ Land::Stench);
}

void NormalLevel::Update()
{
	for each (auto wumpus in wumpuses)
	{
		ToggleWumpusFlag(wumpus);
		wumpus->Update();
		ToggleWumpusFlag(wumpus);
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

}