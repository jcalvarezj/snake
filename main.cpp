/*
 * 
 * @author J. Alvarez
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Snake.hpp"
#include "Food.hpp"
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
	srand(time(NULL));

	Screen screen;
	Snake snake;
	Food food;
	int score = 0;

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
		food.draw(screen);
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
				snake.updateDirection(Snake::Direction::UP);
				break;
			case Screen::Action::MOVE_DOWN:
				snake.updateDirection(Snake::Direction::DOWN);
				break;
			case Screen::Action::MOVE_LEFT:
				snake.updateDirection(Snake::Direction::LEFT);
				break;
			case Screen::Action::MOVE_RIGHT:
				snake.updateDirection(Snake::Direction::RIGHT);
				break;
		}

		if (pause) {
			pauseGame(screen, pause);
		}

		int elapsed = SDL_GetTicks();

		if (elapsed % 4 == 0) {
			//snake.toString();
			if (!snake.move()) {
				snake.reset();
				starting = true;
			}
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