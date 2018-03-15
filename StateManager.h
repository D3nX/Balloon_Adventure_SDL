#pragma once
#include <iostream>
#include <memory>
#include <map>
#include "State.h"
// Including all the states
#include "MenuState.h"

namespace StateManager
{
	namespace
	{
		const char * state;
		std::map<const char *, std::unique_ptr<State> > states;
	}

	void initialize(SDL_Renderer*);
	void update(SDL_Event&);
	void draw(SDL_Renderer*);
}