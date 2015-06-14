#pragma once

#include "Timer.h"
#include "Game.h"
#include "Graphics.h"

class GameEngine
{
public:
	GameEngine();
	void init();
private:
	// Playing
	bool _playing = false;

	// Input
	char _input = ' ';
	
	// Objects
	Game game;
	Graphics graphics;
	
	// Timer
	Timer timer;

	// Obtain deltaTime
	float _currentTime;
	float _lastTime;
	float _deltaTime;

	// Limit update intervals
	float _fps = (float)1 / 60;
	float _acc = 0;

	// Testing variables
	unsigned int _counter = 0;
	unsigned int _accumulator = 0;

	// Main loop
	void update();
};

