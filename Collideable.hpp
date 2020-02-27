#include "SDL2/SDL.h"
#include "Screen.hpp"
#include "Drawable.hpp"

#ifndef COLLIDEABLE_HPP
#define COLLIDEABLE_HPP

namespace SnakeGame {

/**
 * This class represents an object that can collide with others
 * The most basic collision is implemented: objects have same size, so if they
 * are in the same position a collision is assumed
 */
struct Collideable: Drawable {
	Collideable(int x, int y);

	bool collidesWith(Collideable & other);
};

} // namespace SnakeGame

#endif // COLLIDEABLE_HPP