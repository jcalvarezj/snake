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

Section::Section(double x, double y, double speed, int direction):
	Drawable(x, y), m_speed(speed), m_currentDirection(direction),
	m_previousDirection(direction) {}

void Section::draw(Screen & screen) {
	for (int i = 0; i < S_SECTION_WIDTH; i++)
		for (int j = 0; j < S_SECTION_WIDTH; j++)
			screen.setPixel((int) m_x + i, (int) m_y + j, Snake::S_SNK_RED,
				Snake::S_SNK_GREEN, Snake::S_SNK_BLUE);
}

void Section::move(int direction) {
	switch (direction) {
		case Section::Direction::UP:
			m_y -= S_SECTION_WIDTH * m_speed;
			break;
		case Section::Direction::DOWN:
			m_y += S_SECTION_WIDTH * m_speed;
			break;
		case Section::Direction::LEFT:
			m_x -= S_SECTION_WIDTH * m_speed;
			break;
		case Section::Direction::RIGHT:
			m_x += S_SECTION_WIDTH * m_speed;
			break;
	}

}

} // namespace SnakeGame
