#include "Collideable.hpp"
#include "Screen.hpp"
#include "SDL2/SDL.h"

#ifndef WALL_HPP
#define WALL_HPP

namespace SnakeGame {

/**
 * This structure represents a single wall, which kills the snake on collision
 * Its (x,y) position corresponds to the top left pixel
 */
struct Wall: Collideable {
	static const Uint8 S_WALL_RED;
	static const Uint8 S_WALL_GREEN;
	static const Uint8 S_WALL_BLUE;

	static const unsigned int S_WALL_WIDTH;

	/**
	 * @see Collideable#Collideable(int, int)
	 */
	Wall(int x, int y);

	/**
	 * @see Drawable#draw
	 */
	void draw(Screen & screen);
};

} // namespace SnakeGame

#endif // WALL_HPP
