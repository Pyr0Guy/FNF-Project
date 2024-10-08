#pragma once

#include "../Game.hpp"

class GameState
{
public:
	virtual void Init() = 0;
	virtual void Destroy() = 0;

	virtual void Pause() {};
	virtual void Resume() {};

	virtual void Update(Game* game) = 0;
	virtual void Render() = 0;

	inline void ChangeState(Game* game, GameState* state) { game->ChangeState(state); }
	inline void PushState(Game* game, GameState* state) { game->PushState(state); }
	inline void PopState(Game* game) { game->PopState(); }

protected:
	GameState() {}
};