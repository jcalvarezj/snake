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
	static const double S_INITIAL_SPEED;

	enum Direction { UP, DOWN, LEFT, RIGHT };

	double m_speed;
	int m_lives;
	int m_direction;

	std::vector<Section> m_sections;

	Snake();
	void draw(Screen & screen);
	void updateDirection(int direction);
	bool move();
	void reset();
private:
	void resetPosition();
	void resetDirection();
};

} // namespace SnakeGame

#endif // SNAKE_HPP

