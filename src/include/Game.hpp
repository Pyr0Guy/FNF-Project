#pragma once

class Game
{
	Game(int Width, int Height, const char* title);

	void Update();
	void Render();

	void CleanUp();
}
