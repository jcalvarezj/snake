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
	static const Uint8 S_SNK_RED = 0x01;
	static const Uint8 S_SNK_GREEN = 0xFF;
	static const Uint8 S_SNK_BLUE = 0x08;
	cint S_N_SECTS = 20;

	int m_speed;

	std::vector<Section> sections;

	Snake();
	void draw(Screen & screen);
	void move();
};

} // namespace SnakeGame

#endif // SNAKE_HPP

