#pragma once

#include "GameState.hpp"

class Playstate
	: public GameState
{
public:
	void Init() override;
	void Destroy() override;
	void Update(Game* game) override;
	void Render() override;

	static Playstate* getState()
	{
		return &m_PlaystateState;
	}

protected:
	Playstate() {}
private:
	static Playstate m_PlaystateState;
};