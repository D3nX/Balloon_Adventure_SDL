#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "StateManager.h"

Game::Game()
{
	std::cout << "Created !" << std::endl;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		m_width = 640;
		m_height = 480;
		m_title = "Ballon Adventure";
		// m_surface = SDL_Create
		m_window = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);

		if (!m_window)
			throw SDL_Error;

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);

		if (!m_renderer)
			throw SDL_Error;

		// We initialize the state manager
		StateManager::initialize(m_renderer);

		m_isRunning = true;
	}
	else
	{
		m_isRunning = false;
		std::cout << "Error: Unnable to load SDL!" << std::endl;
	}
}

void Game::update()
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
			m_isRunning = false;

	StateManager::update(event);
}

void Game::draw()
{
	SDL_RenderClear(m_renderer);
	StateManager::draw(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Game::run()
{
	const int fps = 60;
	const int delayTime = 1000 / fps;

	Uint32 startTime;
	int currentTime;
	while (m_isRunning)
	{
		startTime = SDL_GetTicks();

		update();
		draw();

		currentTime = SDL_GetTicks() - startTime;

		if (currentTime < delayTime)
			SDL_Delay(delayTime - currentTime);
	}
}

Game::~Game()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	std::cout << "Deleted !!!" << std::endl;
}
