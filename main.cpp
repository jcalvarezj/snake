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
		if(screen.processEvents() == Screen::Action::QUIT)
			quit = true;
	}
	return quit;
}

int pauseGame(Screen & screen, bool & pause) {
	int startTime = SDL_GetTicks();
	bool quit = false;
	int action = Screen::Action::PAUSE;
	while (!quit && pause) {
		switch (screen.processEvents()) {
			case Screen::Action::QUIT:
				quit = true;
				break;
			case Screen::Action::CONTINUE:
				pause = false;
				break;
		}

	}
	return action;
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
	bool pause = false;

	while (!quit && snake.m_lives > 0) {
		screen.clear();
		snake.draw(screen);
		screen.update();

		if (starting) {
			quit = holdGame(screen, 1500);
			starting = false;
		}

		switch (screen.processEvents()) {
			case Screen::Action::QUIT:
				quit = true;
				break;
			case Screen::Action::PAUSE:
				pause = true;
				break;
			case Screen::Action::CONTINUE:
				pause = false;
				break;
			case Screen::Action::MOVE_UP:
				snake.updateDirection(Section::Direction::UP);
				break;
			case Screen::Action::MOVE_DOWN:
				snake.updateDirection(Section::Direction::DOWN);
				break;
			case Screen::Action::MOVE_LEFT:
				snake.updateDirection(Section::Direction::LEFT);
				break;
			case Screen::Action::MOVE_RIGHT:
				snake.updateDirection(Section::Direction::RIGHT);
				break;
		}

		if (pause) {
			pauseGame(screen, pause);
		}

		if (!snake.move()) {
			snake.resetPosition();
			starting = true;
		}


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