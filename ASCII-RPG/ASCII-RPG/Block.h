#pragma once

#include <vector>

#include "Game.h"

class Block
{
public:
	Block();

private:
	Game game;

	int _xCord;
	int _yCord;
	int _Width;
	int _Height;

	std::vector<char> g;
};

