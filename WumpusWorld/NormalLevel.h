#pragma once

#include "GameLevel.h"
#include "Explorer.h"
#include "Map.h"
#include "Wumpus.h"
#include <vector>

class NormalLevel : public GameLevel
{
	vector<Explorer*> explorers;
	vector<Wumpus*> wumpuses;
	Map* map;
	string filename;

	bool ApplyExplorerPosition(Explorer* explorer) const;
	void ToggleFlag(int x, int y, Land::Flags flag) const;

	void DeleteWumpuses() { if (wumpuses.size()) for each (auto wumpus in wumpuses) delete wumpus; }
	void DeleteExplorers() { if (explorers.size()) for each (auto explorer in explorers) delete explorer; }

public:
	NormalLevel(string filename) : filename(filename) {}
	~NormalLevel();

	void Load() override;
	void Update() override;
	void Render() override;
};

