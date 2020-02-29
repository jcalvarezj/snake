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
const int Snake::S_INITIAL_SPEED = 1;
cint Snake::S_INITIAL_DIRECTION = Snake::Direction::RIGHT;
cint Snake::S_N_SECTS = 8;
cint Snake::S_INITIAL_LIVES = 3;

Snake::Snake(): m_speed(Snake::S_INITIAL_SPEED), m_lives(Snake::S_INITIAL_LIVES),
	m_direction(S_INITIAL_DIRECTION), m_hasUpdated(false) {
	Section * newSection = nullptr;
	for (int i = 0; i < S_N_SECTS; i++) {
		newSection = new Section(Screen::S_WIDTH/2 - i*Section::S_SECTION_WIDTH,
			3*Section::S_SECTION_WIDTH);
		m_sections.push_back(newSection);
	}
}

Snake::~Snake() {
	freeSections();
}

void Snake::draw(Screen & screen) {	
	for (auto section: m_sections)
		section->draw(screen);
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
		) {
		m_direction = direction;
		m_hasUpdated = true;
	}
}

bool Snake::move() {
	for (int i = m_sections.size()-1; i > 0; i--)
		m_sections[i]->move(m_sections[i]->
			calculateDirection(* m_sections[i-1]));

	m_sections[0]->move(m_direction);

	m_hasUpdated = false;

	if (m_sections[0]->m_x >= Screen::S_WIDTH || m_sections[0]->m_x < 0 ||
			m_sections[0]->m_y >= Screen::S_HEIGHT || m_sections[0]->m_y < 0)		
		return false;
	else
		return true;
}

void Snake::die() {
	m_lives--;
}

void Snake::reset() {
	Snake::resetSections();
	Snake::resetDirection();
}

void Snake::freeSections() {
	for (auto section: m_sections)
		delete section;
}

void Snake::resetSections() {
	for(int i = S_N_SECTS; i < m_sections.size(); i++)
		delete m_sections[i];

	m_sections.erase(m_sections.begin() + S_N_SECTS, m_sections.end());

	for (int i = 0; i < S_N_SECTS; i++){
		m_sections[i]->m_x = Screen::S_WIDTH/2 - Section::S_SECTION_WIDTH*i;
		m_sections[i]->m_y = 3*Section::S_SECTION_WIDTH;
	}
}

void Snake::resetDirection() {
	m_direction = S_INITIAL_DIRECTION;
}

bool Snake::collidesWith(Collideable & object) {
	return m_sections[0]->collidesWith(object);
}

void Snake::addSection() {
	const int N = m_sections.size();
	int basePlacement = m_sections[N-2]->calculateDirection(* m_sections[N-1]);

	int x = 0;
	int y = 0;

	switch (basePlacement) {
		case Snake::Direction::UP:
			x = m_sections[N-1]->m_x;
			y = m_sections[N-1]->m_y - Section::S_SECTION_WIDTH;
			break;
		case Snake::Direction::DOWN:
			x = m_sections[N-1]->m_x;
			y = m_sections[N-1]->m_y + Section::S_SECTION_WIDTH;
			break;
		case Snake::Direction::LEFT:
			x = m_sections[N-1]->m_x - Section::S_SECTION_WIDTH;
			y = m_sections[N-1]->m_y;
			break;
		case Snake::Direction::RIGHT:
			x = m_sections[N-1]->m_x + Section::S_SECTION_WIDTH;
			y = m_sections[N-1]->m_y;
			break;
	}
	Section * newSection = new Section(x,y);
	m_sections.push_back(newSection);	
}

void Snake::toString() {  // TODO Remove. For debugging purposes
	SDL_Log("----------------------------------------");
	SDL_Log("The snake is:");
	for (auto section: m_sections)
		section->toString();
	SDL_Log("----------------------------------------");
}

} // namespace SnakeGame
