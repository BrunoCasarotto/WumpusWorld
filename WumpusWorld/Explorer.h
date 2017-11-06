#pragma once

#include "GameObject.h"
#include "Direction.h"
#include "Map.h"

class Explorer : public GameObject
{
	Map* map;
	struct Position last;
	struct Position pos;
	int arrow;
	Direction::Flags direction;
	int score;

public:
	Explorer() : Explorer(0, 0, Direction::East, nullptr) { }
	Explorer(const int x, const int y, const Direction::Flags flags, Map* map)
		: map(map), last({ 0, 0 }), pos({ x, y }), arrow(1), direction(flags), score(0)
	{
	}

	void Update() override;
	void Render() override;

	int X() const { return pos.x; }
	int Y() const { return pos.y; }

	void ApplyScore(int value) { score += value; }
};

