#include "stdafx.h"
#include "GameLevel.h"

#include <iostream>
#include "NormalLevel.h"
using namespace std;
int main()
{
	GameLevel::LoadGameLevel(new NormalLevel("C:\\Users\\jairluiz\\Source\\Repos\\WumpusWorld\\map.txt"));

	//while (true)
	//{
		//GameLevel::activeGameLevel->Update();
		GameLevel::activeGameLevel->Render();
	//}

	_gettch();
    return 0;
}

