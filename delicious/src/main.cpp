#include <memory>

#include "game.h"

#ifndef RAYGUI_IMPLEMENTATION
	#define RAYGUI_IMPLEMENTATION
#endif

#include "raygui.h"

int main ()
{
	std::unique_ptr<Game> game = std::make_unique<Game>("Delicious Adventure", 1280, 800);
	game->Start();

	return 0;
}
