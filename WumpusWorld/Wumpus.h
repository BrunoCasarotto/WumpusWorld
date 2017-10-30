#pragma once

#include "GameObject.h"

class Wumpus : public GameObject
{
	int x;
	int y;

public:
	Wumpus() : Wumpus(0, 0) {}
	Wumpus(int x, int y) : x(x), y(y) {}

	void Update() override;
	void Render() override;

	int X() const { return x; }
	int Y() const { return y; }
};