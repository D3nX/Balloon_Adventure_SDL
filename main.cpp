#include "stdafx.h"
#include <iostream>
#include <memory>
#include "Game.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game(new Game());

	game->run();

	return 0;
}

