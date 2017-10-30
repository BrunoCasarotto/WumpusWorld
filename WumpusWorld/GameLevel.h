#pragma once

#include <vector>
#include "GameObject.h"

class GameLevel : public GameObject
{
public:
	static GameLevel* activeGameLevel;

	void LoadGameLevel(GameLevel* gameLevel);

	virtual void Load() = 0;
	
};