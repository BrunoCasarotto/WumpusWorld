#pragma once

#include "GameObject.h"
#include "Direction.h"

class Explorer : public GameObject
{
	int x;
	int y;
	int arrow;
	Direction::Flags direction;
	int score;

public:
	Explorer() : Explorer(0, 0, Direction::East) { }
	Explorer(const int x, const int y, const Direction::Flags flags)
	: x(x), y(y), arrow(1), direction(flags), score(0) { }

	void Update() override;
	void Render() override;

	int X() const { return x; }
	int Y() const { return y; }

	void ApplyScore(int value) { score += value; }
};

