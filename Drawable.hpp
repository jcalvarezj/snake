/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
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

	/**
	 * Initialices Drawable object with a position
	 * @param x X position of this object
	 * @param y Y position of this object
	 */
	Drawable(int x, int y): m_x(x), m_y(y) {}

	/**
	 * Draws on screen this object
	 * @screen Reference to screen to draw on
	 */
	virtual void draw(Screen & screen) = 0;
};

} // namespace SnakeGame

#endif // DRAWABLE_HPP

