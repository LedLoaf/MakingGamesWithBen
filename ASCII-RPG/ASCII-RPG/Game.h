#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <ctime>
#include <Windows.h>

class Game
{
public:
	Game();

	void init();
	void update();
	void fillGraphics(int x, int y, int widht, int height, std::vector<char> g);

private:
	// Width and Height of game (in characters)
	const static int _WIDTH = 24;
	const static int _HEIGHT = 24;

	// Graphics will be stored in an array as it's
	// easier to update and modify
	char graphicsArray[_HEIGHT][_WIDTH];

	int xCord = 0;
	int yCord = 0;
	int gWidth = 2;
	int gHeight = 2;
	std::vector<char> g;

	// Above array will be converted to string for
	// better rendering performance
	std::string graphicsString;

	// Private functions
	void render();
	void clearScreen();
	void clearWindow();
};

