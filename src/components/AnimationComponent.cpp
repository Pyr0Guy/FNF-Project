#include "../include/components/AnimationComponent.hpp"
#include "../include/tinyxml2.h"

#include <sstream>
#include <fstream>
#include <iostream>

AnimationComponent::AnimationComponent(const char *filename, f32 animationSpeed)
    : m_AnimSpeed(animationSpeed), m_curAnim(""), m_MaxFrames(0), m_CurFrame(0.f)
{
    {
        std::stringstream ss;
        ss << filename << ".png";

        std::string TexturePath = ss.str();
        m_Texture = LoadTexture(TexturePath.c_str());
    }

    {
        std::stringstream ss;
        ss << filename << ".xml";
        std::string XMLPath = ss.str();
        LoadAllAnimations(XMLPath);
    }
}

AnimationComponent::~AnimationComponent()
{
    UnloadTexture(m_Texture);
}

void AnimationComponent::Update()
{
    if(m_curAnim != "")
    {
        m_CurFrame += m_AnimSpeed;

        if(m_CurFrame >= m_MaxFrames)
            m_CurFrame = 0.f;
        
        m_CurFrameRect = m_Animations[m_curAnim][m_CurFrame];
    }
}

void AnimationComponent::SetAnimationSpeed(f32 speed)
{
    m_AnimSpeed = speed;
}

void AnimationComponent::Draw(const Vector2& pos)
{
    DrawTextureRec(m_Texture, m_CurFrameRect, pos, WHITE);
}

//Automatic loading of all animations
void AnimationComponent::LoadAllAnimations(std::string XMLPath)
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile(XMLPath.c_str());

    tinyxml2::XMLElement* rootElement = doc.FirstChildElement("TextureAtlas");

    for (tinyxml2::XMLElement* subElement = rootElement->FirstChildElement("SubTexture"); subElement != nullptr; subElement = subElement->NextSiblingElement("SubTexture"))
    {
        std::string name = subElement->Attribute("name");
        size_t start = name.find(" ") + 1;
        size_t end = name.find("0") - start;
        name = name.substr(start, end);

        const char* xPos = subElement->Attribute("x");
		int x = std::atoi(xPos);

		const char* yPos = subElement->Attribute("y");
		int y = std::atoi(yPos);

		const char* frameWidth = subElement->Attribute("width");
		int Width = std::atoi(frameWidth);

		const char* frameHeight = subElement->Attribute("height");
		int Height = std::atoi(frameHeight);

        Rectangle frame;
        frame.x = x;
        frame.y = y;
        frame.width = Width;
        frame.height = Height;

        m_Animations[name].push_back(frame);
    }
}

void AnimationComponent::Play(std::string animName)
{
    if(animName != m_curAnim)
    {
        m_curAnim = animName;
        m_CurFrame = 0;
        m_MaxFrames = m_Animations[m_curAnim].size();
    }
}

bool AnimationComponent::IsAnimationExsists(std::string& name) const
{
    return (m_Animations.find(name) != m_Animations.end());
}