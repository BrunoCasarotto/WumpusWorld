#include "stdafx.h"
#include "Wumpus.h"

void Wumpus::Update()
{
	// andar
}

void Wumpus::Render()
{
	// desenha
	MoveCursor(x, y);
	putchar('m');
}