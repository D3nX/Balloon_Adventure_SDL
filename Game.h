#pragma once
#include "stdafx.h"
#include <iostream>
#include <memory.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Image.h"

using uint = unsigned int;

class Game
{
public:
	Game();
	~Game();
	void update();
	void draw();
	void run();

private:

	// Char stuff
	char const * m_title;

	// Integer stuff
	uint m_width, m_height;

	// Bool stuff
	bool m_isRunning;

	// SDL stuff
	SDL_Event event;
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;

	// Test variables
	
};

