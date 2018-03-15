#include "stdafx.h"
#include "StateManager.h"

namespace StateManager
{
	void initialize(SDL_Renderer* renderer)
	{
		state = "menu";
		states["menu"] = std::unique_ptr<State>(new MenuState(renderer));
	}

	void update(SDL_Event& event)
	{
		states[state]->update(event);
	}

	void draw(SDL_Renderer* renderer)
	{
		states[state]->draw(renderer);
	}
}