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
#include "Wall.hpp"
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
		int action = screen.processEvents();
		switch (action) {
			case Screen::Action::QUIT:
				quit = true;
				break;
			case Screen::Action::PAUSE:
				pause = false;
				break;
		}

	}
	return action;
}

void createWalls(std::vector<Wall> & walls) {
	const int N_HORIZONTAL = Screen::S_WIDTH / Wall::S_WALL_WIDTH;
	const int N_VERTICAL = Screen::S_HEIGHT / Wall::S_WALL_WIDTH - 2;

	for (int i = 0; i < N_HORIZONTAL; i++) {
		walls.push_back(Wall(i * Wall::S_WALL_WIDTH, 0));
		walls.push_back(
			Wall(i * Wall::S_WALL_WIDTH, 
				Screen::S_HEIGHT - 2 * Wall::S_WALL_WIDTH)
		);
	}
	for (int i = 1; i < N_VERTICAL - 1; i++) {
		walls.push_back(Wall(0, i * Wall::S_WALL_WIDTH));
		walls.push_back(Wall(Screen::S_WIDTH - Wall::S_WALL_WIDTH, i * Wall::S_WALL_WIDTH));
	}
}

void drawWalls(std::vector<Wall> & walls, Screen & screen) {
	for (auto wall: walls)
		wall.draw(screen);
}

int main(int argc, char ** argv) {
	srand(time(NULL));

	Screen screen;
	Snake snake;
	Food food;
	std::vector<Wall> walls;
	createWalls(walls);

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
		drawWalls(walls, screen);
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

		if (pause)
			pauseGame(screen, pause);

		int elapsed = SDL_GetTicks();

		if (elapsed % 4 == 0) {
			if (!snake.move()) {
				snake.reset();
				food = Food();
				starting = true;
			}
			else {
				if (snake.collidesWith(food)) {
					food = Food();
					score += Food::S_VALUE;
					SDL_Log("Score! Now you have %d points", score);
					snake.addSection();
				}

				for (auto wall: walls)
					if (snake.collidesWith(wall)) {
						snake.die();
						snake.reset();
						food = Food();
						starting = true;
					}

				for (int i = 1; i < snake.m_sections.size(); i++)
					if (snake.collidesWith(snake.m_sections[i])) {
						snake.die();
						snake.reset();
						food = Food();
						starting = true;
					}
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