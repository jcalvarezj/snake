/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include "Screen.hpp"
#include "Snake.hpp"
#include <iostream>

namespace SnakeGame {

const Uint8 Snake::S_SNK_RED = 0x01;
const Uint8 Snake::S_SNK_GREEN = 0xFF;
const Uint8 Snake::S_SNK_BLUE = 0x08;
const double Snake::S_INITIAL_SPEED = 0.05;
cint Snake::S_INITIAL_DIRECTION = Snake::Direction::RIGHT;
cint Snake::S_N_SECTS = 6;
cint Snake::S_INITIAL_LIVES = 3;

Snake::Snake(): m_speed(Snake::S_INITIAL_SPEED), m_lives(Snake::S_INITIAL_LIVES),
	m_direction(S_INITIAL_DIRECTION) {
	for (int i = 0; i < S_N_SECTS; i++)
		m_sections.push_back(
			Section(Screen::S_WIDTH/2 - Section::S_SECTION_WIDTH*i, 0, m_speed)
		);
}

void Snake::draw(Screen & screen) {
	for (int i = 0; i < m_sections.size(); i++)
		m_sections[i].draw(screen);
}

void Snake::updateDirection(int direction) {
	if (
			(m_direction == Snake::Direction::UP || m_direction ==
			Snake::Direction::DOWN) && (direction == Snake::Direction::LEFT ||
			direction == Snake::Direction::RIGHT)
			||
			(m_direction == Snake::Direction::LEFT || m_direction ==
			Snake::Direction::RIGHT) && (direction == Snake::Direction::UP ||
			direction == Snake::Direction::DOWN)
		)
		m_direction = direction;
}

bool Snake::move() {
	for (int i = S_N_SECTS; i > 0; i--)
		m_sections[i].move(m_sections[i].calculateDirection(m_sections[i-1]));

	m_sections[0].move(m_direction);

	if (m_sections[0].m_x + Section::S_SECTION_WIDTH >= Screen::S_WIDTH ||
			m_sections[0].m_x - Section::S_SECTION_WIDTH < 0 ||
			m_sections[0].m_y + Section::S_SECTION_WIDTH >= Screen::S_HEIGHT ||
			m_sections[0].m_y + Section::S_SECTION_WIDTH < 0) {
		m_lives -= 1;
		return false;
	}
	else
		return true;
}

void Snake::reset() {
	Snake::resetPosition();
	Snake::resetDirection();
}

void Snake::resetPosition() {
	for (int i = 0; i < S_N_SECTS; i++){
		m_sections[i].m_x = Screen::S_WIDTH/2 - Section::S_SECTION_WIDTH*i;
		m_sections[i].m_y = 0;
	}
}

void Snake::resetDirection() {
	m_direction = S_INITIAL_DIRECTION;
}

void Snake::toString() {  // TODO Remove . For debugging purposes
	SDL_Log("----------------------------------------");
	SDL_Log("The snake is:");
	for (auto section: m_sections) {
		section.toString();
	}
	SDL_Log("----------------------------------------");
}

} // namespace SnakeGame
