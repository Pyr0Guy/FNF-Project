#include "../include/states/Playstate.hpp"

#include "../include/components/PositionComponent.hpp"
#include "../include/components/SpriteComponent.hpp"

#include <iostream>
#include <raylib.h>

Playstate Playstate::m_PlaystateState;

Texture2D texture;

void Playstate::Init()
{
	testEnt = m_Registry.create();

	texture = LoadTexture("assets/images/test2.png");

	m_Registry.emplace<PositionComponent>(testEnt, 30.f, 40.f);
	m_Registry.emplace<SpriteComponent>(testEnt, "assets/images/test.png");
}

void Playstate::Destroy()
{

}

void Playstate::Update(Game* game)
{
	if(IsKeyPressed(KEY_A))
	{
		m_Registry.get<SpriteComponent>(testEnt).ChangeTexture(texture);
		m_Registry.get<SpriteComponent>(testEnt).SetScale(0.1f);
	}

	m_Registry.get<SpriteComponent>(testEnt).Rotate(1.f);
	
	std::cout << m_Registry.get<SpriteComponent>(testEnt).GetRotation() << "\n";
}

void Playstate::Render()
{
	//Vector2 pos = 
	m_Registry.get<SpriteComponent>(testEnt).Draw(
		m_Registry.get<PositionComponent>(testEnt).GetPosition()
	);
}
