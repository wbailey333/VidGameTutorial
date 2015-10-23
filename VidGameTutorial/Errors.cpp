#include "Errors.h"

#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>

void fatalError(std::string errorString) {

	//Prints out an error message and exits the game
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit....";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(3);

}
