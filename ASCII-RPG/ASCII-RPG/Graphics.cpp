#include "Graphics.h"



Graphics::Graphics()
{
}

void Graphics::drawString(std::string str, int x, int y)
{
	// Store string to char vector
	std::vector<char> charVect(str.begin(), str.end());
	// Graphics vector
	std::vector<char> graphics;

	// Fill graphics array with char vector
	for (int i = 0; i < charVect.size(); i++) {
		if ((x + i) >= 0 && (x + i) <= _WIDTH && (y + i) >= 0 && (y + i) <= _HEIGHT) {
			graphics.push_back(charVect[i]);
		}
	}

	fillGraphicsArray(x, y, g.size(), 1, graphics);

	charVect.clear();
	graphics.clear();
}

void Graphics::drawTile()
{

}

void Graphics::clearScreen(char fill)
{
	// Clear graphics array
	for (int y = 0; y < _HEIGHT; y++) {
		for (int x = 0; x < _WIDTH; x++) {
			graphicsArray[y][x] = ' ';
		}
	}

	// Clear graphics string
	graphicsString = "";
}

void Graphics::gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Graphics::fillGraphicsArray(int x, int y, int width, int height, std::vector<char> g)
{
	for (int gy = 0; gy < height; gy++) {
		for (int gx = 0; gx < width; gx++) {
			graphicsArray[gy + y][gx + x] = g[gy + gx];
		}
	}
}

void Graphics::render()
{
	gotoxy(0, 0);
	
	// Render graphics to screen
	for (int y = 0; y < _HEIGHT; y++) {
		for (int x = 0; x < _WIDTH; x++) {
			graphicsString += graphicsArray[y][x];
		}
		graphicsString += "\n";
	}
	printf("%s", graphicsString.c_str());
}
