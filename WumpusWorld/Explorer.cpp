#include "stdafx.h"
#include "Explorer.h"

void Explorer::Update()
{
	// anda e toma decis�es
	--score;
}

void Explorer::Render()
{
	// desenha o filha da puta
	MoveCursor(x, y);
	putchar(direction);
}