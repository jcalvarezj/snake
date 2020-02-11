/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include "Screen.hpp"
#include "Snake.hpp"

namespace SnakeGame {

void Snake::draw(Screen & screen) {
	for (int i = 0; i < sections.size(); i++)
	{
		sections[i].draw(screen);
	}
}

} // namespace SnakeGame
