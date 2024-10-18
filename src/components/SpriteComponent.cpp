#include "../pch.hpp"
#include "../include/components/SpriteComponent.hpp"

SpriteComponent::SpriteComponent(const char* filepath)
    : m_Scale(1.f), m_Rotation(0.f)
{
    m_Texture = LoadTexture(filepath);
    m_Origin = { 0.f, 0.f };
}

SpriteComponent::~SpriteComponent()
{
    UnloadTexture(m_Texture);
}

void SpriteComponent::SetScale(f32 scale)
{
    m_Scale = scale;
}

void SpriteComponent::SetRotation(f32 rotation)
{
    if(m_Rotation >= 360.f)
        m_Rotation -= 360.f;
    
    m_Rotation = rotation;
}

void SpriteComponent::Rotate(f32 rotation)
{
    m_Rotation += rotation;

    if(m_Rotation >= 360.f)
        m_Rotation = 0.f;
}

void SpriteComponent::ChangeTexture(Texture2D &texture)
{
    if(texture.id != 0 && texture.id != m_Texture.id)
        UnloadTexture(m_Texture);

    m_Texture = texture;
}

void SpriteComponent::Draw(const Vector2 &pos)
{
    Rectangle source = { 0.0f, 0.0f, (float)m_Texture.width, (float)m_Texture.height };
    Rectangle dest = { pos.x, pos.y, (float)m_Texture.width*m_Scale, (float)m_Texture.height*m_Scale };
    DrawTexturePro(m_Texture, source, dest, m_Origin, m_Rotation, WHITE);
}

s32 SpriteComponent::GetWidth() const
{
    return m_Texture.width;
}

s32 SpriteComponent::GetHeight() const
{
    return m_Texture.height;
}

f32 SpriteComponent::GetScale() const
{
    return m_Scale;
}

f32 SpriteComponent::GetRotation() const
{
    return m_Rotation;
}