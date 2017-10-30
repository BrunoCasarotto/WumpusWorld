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
	Explorer();
	~Explorer();

	void Update() override;
	void Render() override;

	int X() const { return x; }
	int Y() const { return y; }

	void ApplyScore(int value) { score += value; }
};

