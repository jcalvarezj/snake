#include "Drawable.hpp"
#include "Screen.hpp"
#include "SDL2/SDL.h"

#ifndef SECTION_HPP
#define SECTION_HPP

namespace SnakeGame {

/**
 * This structure represents a section of the snake (2px x 2px)
 * Its (x,y) position corresponds to the top left pixel
 */
struct Section: Drawable {
	Section(int x, int y);
	void draw(Screen & screen);
};

} // namespace SnakeGame

#endif // SECTION_HPP