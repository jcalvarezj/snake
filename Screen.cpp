#include "Screen.hpp"
#include <iostream>
#include <cstring>

namespace SnakeGame {

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL),
	m_mainBuffer(NULL) {}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL graphics" << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Particle Simulation Program",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, 
		SDL_WINDOW_SHOWN);

	if (!m_window) {
		SDL_Log("Could not create the window. ");
		SDL_Log(SDL_GetError());
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1,
		SDL_RENDERER_PRESENTVSYNC);

	if (!m_renderer) {
		SDL_Log("Could not create the renderer. ");
		SDL_Log(SDL_GetError());
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, S_WIDTH, S_HEIGHT);

	if (!m_texture) {
		SDL_Log("Could not create the texture. ");
		SDL_Log(SDL_GetError());
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_mainBuffer = new Uint32[S_WIDTH * S_HEIGHT];

	clear();

	return true;
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event))
		if (event.type == SDL_QUIT)
			return false;

	return true;
}

void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_mainBuffer, S_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if (x >= 0 && x < S_WIDTH && y >= 0 && y < S_HEIGHT) {
		Uint32 color = 0;
		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;
		m_mainBuffer[y * S_WIDTH + x] = color;
	}
}

void Screen::clear() {
	memset(m_mainBuffer, 0, S_WIDTH * S_HEIGHT * sizeof(Uint32));
}

void Screen::close() {
	delete [] m_mainBuffer;

	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} // namespace SnakeGame
