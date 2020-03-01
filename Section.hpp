/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include "Collideable.hpp"
#include "Screen.hpp"
#include "SDL2/SDL.h"

#ifndef SECTION_HPP
#define SECTION_HPP

namespace SnakeGame {

/**
 * This structure represents a section of the snake
 * Its (x,y) position corresponds to the top left pixel
 */
struct Section: Collideable {
	static const unsigned int S_SECTION_WIDTH;

	/**
	 * Default constructor for creating Section instances
	 */
	Section();

	/**
	 * @see Collideable#Collideable(int, int)
	 */
	Section(int x, int y);

	/**
	 * @see Drawable#draw
	 */
	void draw(Screen & screen);

	/**
	 * Moves the section to another position according to a direction
	 * @param direction The direction to move this section to
	 */
	void move(int direction);

	/**
	 * Returns the direction value from this Section to another
	 * @other The other section to calculate direction
	 * @return integer indicating direction from Snake::Direction
	 */
	int calculateDirection(Section & other);

	/**
	 * Show information about this instance on screen
	 */
	void toString();  // TODO Remove
};

} // namespace SnakeGame

#endif // SECTION_HPP
