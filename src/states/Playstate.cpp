#include "../include/states/Playstate.hpp"

#include "../include/components/PositionComponent.hpp"
#include "../include/components/SpriteComponent.hpp"
#include "../include/components/AnimationComponent.hpp"

#include <iostream>
#include <raylib.h>

Playstate Playstate::m_PlaystateState;

void Playstate::Init()
{
	testEnt = m_Registry.create();

	m_Registry.emplace<PositionComponent>(testEnt, 30.f, 40.f);
	m_Registry.emplace<AnimationComponent>(testEnt, "assets/images/testbuddy", 0.5f);
	m_Registry.get<AnimationComponent>(testEnt).Play("idle");
}

void Playstate::Destroy()
{

}

void Playstate::Update(Game* game)
{
	m_Registry.get<AnimationComponent>(testEnt).Update();

	if(IsKeyPressed(KEY_Z))
		m_Registry.get<AnimationComponent>(testEnt).Play("idle");
	
	if(IsKeyPressed(KEY_X))
		m_Registry.get<AnimationComponent>(testEnt).Play("down");

	if(IsKeyPressed(KEY_C))
		m_Registry.get<AnimationComponent>(testEnt).Play("right");

	if(IsKeyPressed(KEY_V))
		m_Registry.get<AnimationComponent>(testEnt).Play("up");

	if(IsKeyPressed(KEY_B))
		m_Registry.get<AnimationComponent>(testEnt).Play("yeah");

	if(IsKeyPressed(KEY_N))
		m_Registry.get<AnimationComponent>(testEnt).Play("miss");

	std::cout << m_Registry.get<AnimationComponent>(testEnt).GetAnimation() << std::endl;
}

void Playstate::Render()
{
	m_Registry.get<AnimationComponent>(testEnt).Draw(
		m_Registry.get<PositionComponent>(testEnt).GetPosition()
	);
}
