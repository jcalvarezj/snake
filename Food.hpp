#include "Drawable.hpp"
#include "Screen.hpp"
#include "SDL2/SDL.h"

#ifndef FOOD_HPP
#define FOOD_HPP

namespace SnakeGame {

/**
 * This structure represents a food item
 * Its (x,y) position corresponds to the top left pixel
 */
struct Food: Drawable {
	static const Uint8 S_FOOD_RED;
	static const Uint8 S_FOOD_GREEN;
	static const Uint8 S_FOOD_BLUE;

	static const unsigned int S_FOOD_WIDTH;
	static const int S_VALUE;

	Food();

	void draw(Screen & screen);
};

} // namespace SnakeGame

#endif // FOOD_HPP