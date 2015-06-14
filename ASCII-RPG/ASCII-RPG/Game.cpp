#include "Game.h"

Game::Game()
{

}


void Game::init()
{
	// Create block size
	gWidth = 5;
	gHeight = 2;

	for (int i = 0; i < (gWidth + gHeight); i++) {
		g.push_back('H');
	}
}

void Game::update()
{
	// Clear screen and graphics array
	clearScreen();

	char input = _getch();

	if (input == 'w') yCord--;
	if (input == 's') yCord++;
	if (input == 'a') xCord--;
	if (input == 'd') xCord++;

	if (xCord <= 0) xCord = 0;
	if (yCord <= 0) yCord = 0;
	
	if ((xCord + gWidth) >= _WIDTH) {
		xCord = _WIDTH - gWidth;
	}

	if ((yCord + gHeight) >= _HEIGHT) {
		yCord = _HEIGHT - gHeight;
	}

	fillGraphics(xCord, yCord, gWidth, gHeight, g);

	render();


}

void Game::render()
{
	// Render graphics to screen
	for (int y = 0; y < _HEIGHT; y++) {
		for (int x = 0; x < _WIDTH; x++) {
			graphicsString += graphicsArray[y][x];
		}
		graphicsString += "\n";
	}
	printf("%s", graphicsString.c_str());
	//std::cout << graphicsString;
}

void Game::clearScreen()
{
	// Clear graphics array
	for (int y = 0; y < _HEIGHT; y++) {
		for (int x = 0; x < _WIDTH; x++) {
			graphicsArray[y][x] = '.';
		}
	}

	// Clear graphics string
	graphicsString = "";
}

void Game::fillGraphics(int x, int y, int width, int height, std::vector<char> g)
{
	for (int gy = 0; gy < height; gy++) {
		for (int gx = 0; gx < width; gx++) {
			graphicsArray[gy + y][gx + x] = g[gy + gx];
		}
	}
}