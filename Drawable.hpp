#include "SDL2/SDL.h"
#include "Screen.hpp"

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

namespace SnakeGame {

/**
 * This class represents an object that can be drawn on a Screen
 */
struct Drawable {
	virtual void draw(Screen & screen) = 0;
	double m_x;
	double m_y;

	Drawable(double x, double y): m_x(x), m_y(y) {}
};

} // namespace SnakeGame

#endif // DRAWABLE_HPP

