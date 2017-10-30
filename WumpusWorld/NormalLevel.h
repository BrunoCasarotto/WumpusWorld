#pragma once

#include "GameLevel.h"
#include "Explorer.h"
#include "Map.h"
#include "Wumpus.h"

class NormalLevel : public GameLevel
{
	vector<Explorer*> explorers;
	vector<Wumpus*> wumpuses;
	Map* map;
	string filename;

	bool ApplyExplorerPosition(Explorer* explorer) const;
	void ToggleWumpusFlag(Wumpus* wumpus);

public:
	NormalLevel(string filename) : filename(filename) {}
	~NormalLevel();

	void Load() override { if (map) map->Load(filename); }
	void Update() override;
	void Render() override;
};

