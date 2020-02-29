#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#ifndef SCREEN_HPP
#define SCREEN_HPP

typedef const unsigned int cint;

namespace SnakeGame {

/**
 * This class represents the graphic interface where the particles are shown
 */
class Screen {
public:
	enum Action { QUIT, CONTINUE, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, PAUSE };
	static cint S_WIDTH = 800;
	static cint S_HEIGHT = 600;
private:
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	SDL_Texture * m_texture;
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
	 * Updates the Screen's elements according to the information in the buffer
	 */
	void update();
	
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
};

} // namespace SnakeGame

#endif // SCREEN_HPP

