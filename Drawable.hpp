#include "SDL2/SDL.h"
#include "Screen.hpp"

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

namespace SnakeGame {

/**
 * This class represents an object that can be drawn on a Screen
 */
struct Drawable {	
	int m_x;
	int m_y;	

	Drawable(int x, int y): m_x(x), m_y(y) {}

	virtual void draw(Screen & screen) = 0;
};

} // namespace SnakeGame

#endif // DRAWABLE_HPP

