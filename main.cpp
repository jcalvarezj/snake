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

bool holdGame(Screen & screen, int millis) {
	int startTime = SDL_GetTicks();
	bool quit = false;
	while (SDL_GetTicks() - startTime < millis && !quit) {
		if(!screen.processEvents())
			quit = true;
	}
	return quit;
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
			quit = holdGame(screen, 1500);
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

			holdGame(screen, 3000);
		}
	}

	screen.close();

	return 0;
}