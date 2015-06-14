#include "GameEngine.h"

GameEngine::GameEngine()
{
}

void GameEngine::init()
{
	_playing = true;

	update();
}

void GameEngine::update()
{
	_lastTime = timer.getTime();
	game.init();
	while (_playing) {
		_currentTime = timer.getTime();
		_deltaTime = _currentTime - _lastTime;
		_lastTime = _currentTime;
		_acc += _deltaTime;

		if (_acc >= _fps) {
			if (_kbhit() == 1) {
				_input = _getch();
			}
			else {
				_input = ' ';
			}

			game.update(_acc, _input);
			graphics.render();

			_acc -= _fps;
		}
	}
}
