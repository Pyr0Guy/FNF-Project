#include "include/Game.hpp"

#include <raylib.h>

Game::Game(int Width, int Height, const char* title)
{
	InitWindow(Width, Height, title);
}
