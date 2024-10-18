#include "../pch.hpp"

#include "../include/states/Playstate.hpp"

#include "../include/components/PositionComponent.hpp"
#include "../include/components/SpriteComponent.hpp"
#include "../include/components/AnimationComponent.hpp"

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
	auto& osakaANim = m_Registry.get<AnimationComponent>(testEnt);

	osakaANim.Update();

	if (IsKeyDown(KEY_Z))
		osakaANim.Play("idle");

	if (IsKeyDown(KEY_X))
		osakaANim.Play("up");

	if (IsKeyDown(KEY_C))
		osakaANim.Play("down");

	if (IsKeyDown(KEY_V))
		osakaANim.Play("right");

	if (IsKeyDown(KEY_B))
		osakaANim.Play("left");

	if (IsKeyDown(KEY_N))
		osakaANim.Play("yeah");

	if (IsKeyDown(KEY_M))
		osakaANim.Play("miss");

	//std::cout << m_Registry.get<AnimationComponent>(testEnt).GetAnimation() << std::endl;
}

void Playstate::Render()
{
	m_Registry.get<AnimationComponent>(testEnt).Draw(
		m_Registry.get<PositionComponent>(testEnt).GetPosition()
	);
}
