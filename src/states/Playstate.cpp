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

	if(IsKeyPressed(1))
		m_Registry.get<AnimationComponent>(testEnt).Play("idle");
	
	if(IsKeyPressed(2))
		m_Registry.get<AnimationComponent>(testEnt).Play("down");

	if(IsKeyPressed(3))
		m_Registry.get<AnimationComponent>(testEnt).Play("right");

	if(IsKeyPressed(4))
		m_Registry.get<AnimationComponent>(testEnt).Play("up");

	if(IsKeyPressed(2))
		m_Registry.get<AnimationComponent>(testEnt).Play("yeah");

	if(IsKeyPressed(2))
		m_Registry.get<AnimationComponent>(testEnt).Play("miss");
}

void Playstate::Render()
{
	m_Registry.get<AnimationComponent>(testEnt).Draw(
		m_Registry.get<PositionComponent>(testEnt).GetPosition()
	);
}
