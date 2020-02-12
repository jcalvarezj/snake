/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include "Screen.hpp"
#include "Section.hpp"
#include "Snake.hpp"

namespace SnakeGame {

const unsigned int Section::S_SECTION_WIDTH = 5;

Section::Section(int x, int y, int speed): Drawable(x, y), m_speed(speed) {}

void Section::draw(Screen & screen) {
	for (int i = 0; i < S_SECTION_WIDTH; i++)
		for (int j = 0; j < S_SECTION_WIDTH; j++)
			screen.setPixel(m_x + i, m_y + j, Snake::S_SNK_RED, Snake::S_SNK_GREEN, Snake::S_SNK_BLUE);
}

void Section::move(int direction) {
	m_x += S_SECTION_WIDTH;
}

} // namespace SnakeGame
