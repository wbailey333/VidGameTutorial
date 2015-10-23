#include "MainVidGame.h"
#include "Errors.h"

#include <iostream>
#include <string>


// Constructor, just intializes prvate member veriables
MainVidGame::MainVidGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;

}

//Destructor
MainVidGame::~MainVidGame()
{
}


//This runs the game
void MainVidGame::run() {
	initSystems();

	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

	gameLoop();

}

void MainVidGame::initSystems(){

	// Init everything
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("SDL Window could not be create!");
	}

	SDL_GLContext glContex = SDL_GL_CreateContext(_window);
	if (glContex == nullptr) {
		fatalError("SDL_GL context could not be create!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initalize glew");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	initShaders();

}


void MainVidGame::initShaders() {
	_colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.linkShader();
}

void MainVidGame::gameLoop() {

	while (_gameState != GameState::EXIT) {
		processInput();
		drawGame();
	}

}

void MainVidGame::processInput() {

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;

			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
		}
	}
	

}

void MainVidGame::drawGame() {
	glClearDepth(1.0);
	// Clears the color and depth buffers getting it ready for the next frame to pring
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_colorProgram.user();

	_sprite.draw();

	_colorProgram.unuse();

	// Swap our buffers and draw everything to the screen
	SDL_GL_SwapWindow(_window);

}
