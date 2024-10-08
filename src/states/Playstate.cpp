#include "../include/states/Playstate.hpp"

#include <iostream>

Playstate Playstate::m_PlaystateState;

void Playstate::Init()
{
}

void Playstate::Destroy()
{
}

void Playstate::Update(Game* game)
{
	std::cout << "fff" << std::endl;
}

void Playstate::Render()
{
}
