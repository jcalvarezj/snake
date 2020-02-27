#include "Drawable.hpp"
#include "Screen.hpp"
#include "SDL2/SDL.h"

#ifndef SECTION_HPP
#define SECTION_HPP

namespace SnakeGame {

/**
 * This structure represents a section of the snake
 * Its (x,y) position corresponds to the top left pixel
 */
struct Section: Drawable {
	static const unsigned int S_SECTION_WIDTH;

	Section(int x, int y);
	void draw(Screen & screen);
	void move(int direction);
	int calculateDirection(Section & other);
	void toString();  // TODO Remove
};

} // namespace SnakeGame

#endif // SECTION_HPP