#pragma once
#include "State.h"
#include "Image.h"

class MenuState : public State
{
public:
	MenuState(SDL_Renderer*);
	~MenuState();

	void update(SDL_Event&);
	void draw(SDL_Renderer*);
	void reset();

private:
	Image * m_image;
};

