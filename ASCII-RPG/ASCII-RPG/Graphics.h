#pragma once

#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>

class Graphics
{
public:
	Graphics();
	void drawString(std::string str, int x, int y);
	void drawTile();
	void clearScreen(char fill);
	void render();
private:
	// Height and Width of game
	// 78 and 24 are divisible by 3 (Size of tiles)
	const static int _WIDTH = 78;
	const static int _HEIGHT = 24;

	// Tiles will be stored in graphics array
	char graphicsArray[_HEIGHT][_WIDTH];

	// Above array will be converted to string for
	// better rendering performance
	std::string graphicsString;

	// Prevent flickering
	void gotoxy(int x, int y);

	// Fill graphics array
	void fillGraphicsArray(int x, int y, int width, int height, std::vector<char> g);
};

