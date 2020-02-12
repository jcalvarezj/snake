/*
 * Compile with g++ *.cpp -IC:\SDL\include -LC:\SDL\i686-w64-mingw32\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2
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

void drawSnake(const Snake & snake);

int main(int argc, char ** argv) {	
	Screen screen;
	Snake snake;

	if (!screen.init()) {
		SDL_Log("Error initializing screen");
		return -1;
	}

	bool quit = false;

	while (!quit) {
		screen.clear();

		snake.move();
		snake.draw(screen);

		screen.update();

		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
