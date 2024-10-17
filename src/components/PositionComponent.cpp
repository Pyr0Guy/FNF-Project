#include "../include/components/PositionComponent.hpp"

void PositionComponent::SetPosition(Vector2 newPos)
{
    m_Position = newPos;
}

void PositionComponent::SetPosition(float x, float y)
{
    m_Position.x = x;
    m_Position.y = y;
}

void PositionComponent::Move(Vector2 move)
{
    m_Position.x += move.x;
    m_Position.y += move.y;
}

void PositionComponent::Move(float x, float y)
{
    m_Position.x += x;
    m_Position.y += y;
}

Vector2 PositionComponent::GetPosition() const
{
    return m_Position;
}
