#include "../include/states/Playstate.hpp"

#include <iostream>

Playstate Playstate::m_PlaystateState;

void Playstate::Init()
{
	m_testObj = new Entity();
}

void Playstate::Destroy()
{
}

void Playstate::Update(Game* game)
{
}

void Playstate::Render()
{
}
