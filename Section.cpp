/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include "Screen.hpp"
#include "Section.hpp"

namespace SnakeGame {

Section::Section(int x, int y): Drawable(x, y) {}

void Section::draw(Screen & screen) {
	screen.setPixel(m_x, m_y, 0xFF, 0x00, 0x88);
	screen.setPixel(m_x + 1, m_y, 0xFF, 0x00, 0x88);
	screen.setPixel(m_x, m_y + 1, 0xFF, 0x00, 0x88);
	screen.setPixel(m_x + 1, m_y + 1, 0xFF, 0x00, 0x88);
}

} // namespace SnakeGame
