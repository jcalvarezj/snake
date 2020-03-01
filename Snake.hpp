#include "SDL2/SDL.h"
#include <vector>
#include "Section.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

typedef const unsigned int cint;

namespace SnakeGame {

/**
 * This structure represents the snake that the player controls
 */
struct Snake {
	static const Uint8 S_SNK_RED;
	static const Uint8 S_SNK_GREEN;
	static const Uint8 S_SNK_BLUE;
	static cint S_N_SECTS;
	static cint S_INITIAL_LIVES;
	static cint S_INITIAL_DIRECTION;
	static const int S_INITIAL_SPEED;

	enum Direction { UP, DOWN, LEFT, RIGHT };

	int m_speed;
	int m_lives;
	int m_direction;
	bool m_hasUpdated;

	std::vector<Section *> m_sections;

	/**
	 * Default constructor of Snake to create instances
	 */
	Snake();

	/**
	 * Destructor for Snake that cleans up sections
	 */
	~Snake();

	/**
	 * @see Drawable#draw
	 */
	void draw(Screen & screen);

	/**
	 * Updates the direction of the snake
	 * @direction The direction of the snake according to Snake::Direction
	 */
	void updateDirection(int direction);

	/**
	 * Moves the snake, which implies moving all its sections
	 * @return true if movement is within Screen's area, false otherwise
	 */
	bool move();

	/**
	 * Removes one life from the snake
	 */
	void die();

	/**
	 * Resets snake to its initial state (except for lives)
	 */
	void reset();

	/**
	 * Checks whether the snake (it's head section) collides with another object
	 */
	bool collidesWith(Collideable & object);

	/**
	 * Adds a new section to the end of the snake
	 */
	void addSection();

	/**
	 * Show information about this instance on screen
	 */
	void toString();  // TODO Remove . For debugging purposes
	
private:
	/**
	 * Frees memory from snake's sections
	 */
	void freeSections();

	/**
	 * Resets the snake's sections to the initial state (initial number and
	 * position)
	 */
	void resetSections();

	/**
	 * Resets the snake's direction to the initial direction
	 */
	void resetDirection();
};

} // namespace SnakeGame

#endif // SNAKE_HPP

