#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include "GLSProgram.h"
#include "Sprite.h"


enum class GameState{PLAY, EXIT};

class MainVidGame
{
public:
	MainVidGame();
	~MainVidGame();

	void run();


private:

	void initSystems();
	void initShaders();
	void gameLoop();
	void processInput();
	void drawGame();

private:
	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;

	GLSProgram _colorProgram;

};

