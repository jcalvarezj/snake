/*
 * Snake game program using the SDL library
 *
 * @author J. Alvarez
 */
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <string>

#ifndef SCREEN_HPP
#define SCREEN_HPP

typedef const unsigned int cint;

namespace SnakeGame {

/**
 * This class represents the graphic interface where the particles are shown
 */
class Screen {
public:
	enum Action { QUIT, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, PAUSE };
	static cint S_WIDTH;
	static cint S_HEIGHT;
	static cint S_TEXT_X;
	static cint S_TEXT_Y;
	static cint S_TEXT_RECT_WIDTH;
	static cint S_TEXT_RECT_HEIGHT;
	static const std::string S_SCORE_TEXT;
	static const std::string S_LIVES_TEXT;
private:
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	SDL_Texture * m_texture;
	SDL_Surface * m_textSurface;
	SDL_Texture * m_textTexture;
	TTF_Font * m_sansFont;
	Uint32 * m_mainBuffer;
public:
	/**
	 * Creates a Screen instance and initializes it fields
	 */
	Screen();

	/**
	 * Initializes window, renderer, texture, and buffer
	 * @return boolean indicating success of the initialization process
	 */
	bool init();

	/**
	 * Unstacks events from the event pool and processes them
	 * @return int indicating the action according to the event
	 */
	int processEvents();

	/**
	 * Updates the Screen's elements according to the information in the buffer,
	 * as well as the game's score and lives
	 * @param score The game's score
	 * @param lives The game's lives
	 * @param isGameOver Indicates whether there is Game Over
	 */
	void update(int lives, int score, bool isGameOver);
	
	/**
	 * Sets a pixel in the buffer with the specified (x,y) position, and colors
	 * @param x The x position
	 * @param y The y position
	 * @param red The value of the red color component
	 * @param green The value of the green color component
	 * @param blue The value of the blue color component
	 */
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

	/**
	 * Clears the Screen's main buffer (set it to all zeros)
	 */
	void clear();

	/**
	 * Closes the Screen and cleans memory from all its elements
	 */
	void close();

	/**
	 * Draw game over view on the screen
	 */
	void drawGameOver();

private:
	/**
	 * Creates and returns display text
	 * @param score The score from the game
	 * @param lives The lives from the game
	 */
	std::string createText(int score, int lives);

	/**
	 * Clears memory from text-related elements
	 */
	void freeText();

	/**
	 * Draws text on screen according to game's score and lives
	 * @param score The score from the game
	 * @param lives The lives from the game
	 */
	void drawText(int score, int lives);
};

} // namespace SnakeGame

#endif // SCREEN_HPP

