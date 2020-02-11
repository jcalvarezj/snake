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

	if (!screen.init()) {
		SDL_Log("Error initializing screen");
		return -1;
	}

	bool quit = false;

	while (!quit) {
		Uint8 red = 0xFF;
		Uint8 green = 0xCC;
		Uint8 blue = 0x00;

		for (int i = 0; i < 50; i++)
		{
			screen.setPixel(i, 500, red, green, blue);
		}
		
		screen.update();

		if(!screen.processEvents())
			quit = true;
	}

	screen.close();

	return 0;
}
