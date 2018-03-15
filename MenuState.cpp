#include "stdafx.h"
#include "MenuState.h"
#include <iostream>

MenuState::MenuState(SDL_Renderer* renderer)
{
	m_image = new Image("res/lake_mountain.jpg", renderer);
	m_image->setWidth(128);
	m_image->setHeight(128);
}

MenuState::~MenuState()
{
	std::cout << "Deleted menu state !" << std::endl;
	delete m_image;
}

void MenuState::update(SDL_Event& event)
{
	std::cout << "here !" << std::endl;
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_RIGHT)
			m_image->setX(m_image->getX() + 2);
		else if (event.key.keysym.sym == SDLK_LEFT)
			m_image->setX(m_image->getX() - 2);

		if (event.key.keysym.sym == SDLK_DOWN)
			m_image->setY(m_image->getY() + 2);
		else if (event.key.keysym.sym == SDLK_UP)
			m_image->setY(m_image->getY() - 2);
	}
}

void MenuState::draw(SDL_Renderer* renderer)
{
	m_image->draw();
}

void MenuState::reset()
{

}
