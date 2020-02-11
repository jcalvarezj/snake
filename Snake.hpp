#include "SDL2/SDL.h"
#include <vector>
#include "Section.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

namespace SnakeGame {

/**
 * This structure represents the snake that the player controls
 */
struct Snake {
	int speedX;
	int speedY;

	std::vector<Section> sections;

	Snake();
	~Snake();
	void draw(Screen & screen);
};

} // namespace SnakeGame

#endif // SNAKE_HPP

