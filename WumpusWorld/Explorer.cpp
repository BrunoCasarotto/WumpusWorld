#include "stdafx.h"
#include "Explorer.h"

void Explorer::Update()
{
	// anda e toma decisões
	--score;
}

void Explorer::Render()
{
	// desenha o filha da puta
	MoveCursor(x, y);
	putchar(direction);
}