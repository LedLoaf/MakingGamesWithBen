#include "InitialiseGame.h"



InitialiseGame::InitialiseGame()
{
	_playing = true;

	// Game object
	Game game;

	update(game);
}

void InitialiseGame::update(Game &game)
{
	game.init();
	while (_playing) {
		game.update();
	}
}
