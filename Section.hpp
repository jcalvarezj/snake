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
	enum Direction { UP, DOWN, LEFT, RIGHT };

	double m_speed;
	int m_currentDirection;
	int m_previousDirection;

	Section(double x, double y, double speed, int direction);
	void draw(Screen & screen);
	void move(int direction);
};

} // namespace SnakeGame

#endif // SECTION_HPP