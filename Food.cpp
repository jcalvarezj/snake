/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include "Screen.hpp"
#include "Food.hpp"

namespace SnakeGame {

const Uint8 Food::S_FOOD_RED = 0xCC;
const Uint8 Food::S_FOOD_GREEN = 0xAF;
const Uint8 Food::S_FOOD_BLUE = 0x68;

const unsigned int Food::S_FOOD_WIDTH = 20;

const int Food::S_VALUE = 50;

Food::Food(): Collideable(0, 0) {
	m_x = (int) ((Screen::S_WIDTH / S_FOOD_WIDTH - 2.0) * (1.0 * rand() / RAND_MAX) + 1) * S_FOOD_WIDTH;
	m_y = (int) ((Screen::S_HEIGHT / S_FOOD_WIDTH - 4.0) * (1.0 * rand() / RAND_MAX) + 1) * S_FOOD_WIDTH;
}

void Food::draw(Screen & screen) {
	for (int i = 0; i < S_FOOD_WIDTH; i++)
		for (int j = 0; j < S_FOOD_WIDTH; j++)
			screen.setPixel((int) m_x + i, (int) m_y + j, Food::S_FOOD_RED,
				Food::S_FOOD_GREEN, Food::S_FOOD_BLUE);
}

} // namespace SnakeGame
