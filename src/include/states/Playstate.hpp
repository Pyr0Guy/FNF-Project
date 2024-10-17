#pragma once

#include "GameState.hpp"
#include "../entt/entt.hpp"

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

	entt::registry m_Registry;
	entt::entity testEnt;
};