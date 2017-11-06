#include "stdafx.h"
#include "Explorer.h"

void Explorer::Update()
{
	auto land = map->GetLand(pos.x, pos.y);

	if (land.flags & Land::Glow)
	{
		auto ahead = GetAhead(pos, direction);

		if (map->GetLand(ahead.x, ahead.y).type & Map::Chest) // anda para a frente
		{
			last = pos;
			pos = ahead;
		}
		else
		{
			TurnRight(direction);
		}
	}

	// anda e toma decisões
	--score;
}

void Explorer::Render()
{
	// desenha o filha da puta
	MoveCursor(pos.x, pos.y);
	putchar(direction);
}