#include "../pch.hpp"

#include "../include/components/AnimationComponent.hpp"
#include "../include/tinyxml2.h"

AnimationComponent::AnimationComponent(const char *filename, f32 animationSpeed)
    : m_AnimSpeed(animationSpeed), m_curAnim(""), m_MaxFrames(0), m_CurFrame(0.f), m_Scale(1.f), m_Rotation(0.f)
{
    m_Origin = { 0.f, 0.f };

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

void AnimationComponent::SetScale(f32 scale)
{
    m_Scale = scale;
}

void AnimationComponent::SetRotation(f32 rotation)
{
    if(rotation >= 360.f)
        rotation -= 360.f;

    m_Rotation = rotation;
}

void AnimationComponent::Draw(const Vector2& pos)
{
    //DrawTextureRec(m_Texture, m_CurFrameRect, pos, WHITE);
    Rectangle dest = { pos.x, pos.y, (float)m_CurFrameRect.width * m_Scale, (float)m_CurFrameRect.height * m_Scale };
    DrawTexturePro(m_Texture, m_CurFrameRect, dest, m_Origin, m_Rotation, WHITE);
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

void AnimationComponent::Rotate(f32 amount)
{
    m_Rotation += amount;

    if(m_Rotation >= 360.f)
        m_Rotation = 0.f;
}

void AnimationComponent::Play(std::string animName)
{
    if (IsAnimationExsists(animName) == false)
    {
        std::cout << "No such animation with name: " << animName << std::endl;
        return;
    }

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

std::string AnimationComponent::GetCurrentAnimation() const
{
    return m_curAnim;
}

std::vector<std::string> AnimationComponent::GetAllAnimations() const
{
    std::vector<std::string> animations;

    for(const auto& animName : m_Animations)
        animations.push_back(animName.first);

    return animations;
}