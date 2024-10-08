#pragma once

#include <vector>

class GameState;

class Game
{
public:
	Game(int Width, int Height, const char* title);
	Game(const Game&) = delete;

	void Update();
	void Render();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void CleanUp();

	bool GameShouldClose() const;

private:
	std::vector<GameState*> m_States;
};