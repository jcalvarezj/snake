/*
 * 
 * @author J. Alvarez
 */
#include <iostream>
#include <cstring>
#include <vector>
#include "Snake.hpp"
#include "Screen.hpp"
#include "SDL2/SDL.h"

using namespace SnakeGame;

void holdGame(int millis) {
	int startTime = SDL_GetTicks();
	while (SDL_GetTicks() - startTime < millis);
}

int main(int argc, char ** argv) {	
	Screen screen;
	Snake snake;

	if (!screen.init()) {
		SDL_Log("Error initializing screen");
		return -1;
	}

	bool quit = false;
	bool starting = true;

	while (!quit && snake.m_lives > 0) {
		screen.clear();
		snake.draw(screen);
		screen.update();

		if (starting) {
			holdGame(2000);
			starting = false;
		}

		if (!snake.move()) {
			snake.resetPosition();
			starting = true;
		}

		if(!screen.processEvents())
			quit = true;

		if (snake.m_lives == 0) {
			screen.clear();			
			screen.drawGameOver();
			screen.update();

			holdGame(3000);
		}
	}

	screen.close();

	return 0;
}

