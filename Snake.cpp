/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include "Screen.hpp"
#include "Snake.hpp"
#include <iostream>

namespace SnakeGame {

Snake::Snake(): m_speed(1) {
	for (int i = 0; i < S_N_SECTS; i++)
		sections.push_back(Section(Screen::S_WIDTH/2 - Section::S_SECTION_WIDTH*i, 0, m_speed));
}

void Snake::draw(Screen & screen) {
	for (int i = 0; i < sections.size(); i++)
		sections[i].draw(screen);
}

void Snake::move() {
	for (int i = 0; i < sections.size(); i++) {
		sections[i].move(1);
	}
}

} // namespace SnakeGame
