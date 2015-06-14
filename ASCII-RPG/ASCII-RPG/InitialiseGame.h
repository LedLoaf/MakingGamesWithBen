#pragma once

#include "Game.h"

class InitialiseGame
{
public:
	InitialiseGame();
private:
	// Playing
	bool _playing = false;

	// Main loop
	void update(Game &game);
};

