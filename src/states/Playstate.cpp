#include "../pch.hpp"

#include "../include/states/Playstate.hpp"

#include "../include/components/PositionComponent.hpp"
#include "../include/components/SpriteComponent.hpp"
#include "../include/components/AnimationComponent.hpp"

Playstate Playstate::m_PlaystateState;

std::vector<std::string> allTestAnim;
int anim = 0;

void Playstate::Init()
{
	testEnt = m_Registry.create();

	m_Registry.emplace<PositionComponent>(testEnt, 150.f, 150.f);
	m_Registry.emplace<SpriteComponent>(testEnt,"assets/images/test.png");

	/*
	m_Registry.emplace<AnimationComponent>(testEnt, "assets/images/BOYFRIEND", 0.5f);
	m_Registry.get<AnimationComponent>(testEnt).Play("idle");
	m_Registry.get<AnimationComponent>(testEnt).SetScale(0.5f);
	allTestAnim = m_Registry.get<AnimationComponent>(testEnt).GetAllAnimations();
	*/
}

void Playstate::Destroy()
{

}

void Playstate::Update(Game* game)
{
	/*
	auto& osakaANim = m_Registry.get<AnimationComponent>(testEnt);

	osakaANim.Update();

	osakaANim.Rotate(1.f);

	if(IsKeyPressed(KEY_RIGHT))
	{
		anim++;

		if(anim >= allTestAnim.size())
			anim = 0;

		std::cout << allTestAnim[anim] << std::endl;

		osakaANim.Play(allTestAnim[anim]);
	}

	if(IsKeyPressed(KEY_LEFT))
	{
		anim--;

		if(anim < 0)
			anim = allTestAnim.size() - 1;

		std::cout << allTestAnim[anim] << std::endl;

		osakaANim.Play(allTestAnim[anim]);
	}
	*/

	auto& spr = m_Registry.get<SpriteComponent>(testEnt);

	spr.Rotate(1.f);
}

void Playstate::Render()
{
	m_Registry.get<SpriteComponent>(testEnt).Draw(
		m_Registry.get<PositionComponent>(testEnt).GetPosition()
	);
	/*
	m_Registry.get<AnimationComponent>(testEnt).Draw(
		m_Registry.get<PositionComponent>(testEnt).GetPosition()
	);
	*/
}
