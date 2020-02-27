#include "SDL2/SDL.h"
#include "Screen.hpp"
#include "Drawable.hpp"

#ifndef COLLIDEABLE_HPP
#define COLLIDEABLE_HPP

namespace SnakeGame {

/**
 * This class represents an object that can collide with others
 */
struct Collideable: Drawable {
	Collideable(int x, int y);

	bool collidesWith(Collideable & other);
};

} // namespace SnakeGame

#endif // COLLIDEABLE_HPP