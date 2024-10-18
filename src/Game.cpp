#include "pch.hpp"

#include "include/Game.hpp"
#include "include/states/Playstate.hpp"

Game::Game(int Width, int Height, const char* title)
{
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	ChangeDirectory(GetApplicationDirectory());
	InitWindow(Width, Height, title);

	ChangeState(Playstate::getState());
}

void Game::Update()
{
	m_States.back()->Update(this);
}

void Game::Render()
{
	BeginDrawing();

	ClearBackground(MAGENTA);
	DrawFPS(0, 0);

	for (auto& state : m_States)
		state->Render();

	EndDrawing();
}

void Game::ChangeState(GameState* state)
{
	while (!m_States.empty())
	{
		m_States.back()->Destroy();
		m_States.pop_back();
	}

	m_States.emplace_back(state);
	m_States.back()->Init();
}

void Game::PushState(GameState* state)
{
	if (!m_States.empty())
		m_States.back()->Pause();

	m_States.emplace_back(state);
	m_States.back()->Init();
}

void Game::PopState()
{
	if (!m_States.empty())
	{
		m_States.back()->Destroy();
		m_States.pop_back();
	}

	if (!m_States.empty())
		m_States.back()->Resume();
}

void Game::CleanUp()
{
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose();
}
