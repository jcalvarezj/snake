/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include <stdlib.h>
#include "Screen.hpp"
#include "Wall.hpp"

namespace SnakeGame {

const Uint8 Wall::S_WALL_RED = 0xFC;
const Uint8 Wall::S_WALL_GREEN = 0x0F;
const Uint8 Wall::S_WALL_BLUE = 0x08;

const unsigned int Wall::S_WALL_WIDTH = 20;

Wall::Wall(int x, int y): Collideable(x, y) {}

void Wall::draw(Screen & screen) {
	for (int i = 0; i < S_WALL_WIDTH; i++)
		for (int j = 0; j < S_WALL_WIDTH; j++)
			screen.setPixel((int) m_x + i, (int) m_y + j, Wall::S_WALL_RED,
				Wall::S_WALL_GREEN, Wall::S_WALL_BLUE);
}

} // namespace SnakeGame
