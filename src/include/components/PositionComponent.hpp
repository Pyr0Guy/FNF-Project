#pragma once

class PositionComponent
{
public:    
    PositionComponent() = default;
    PositionComponent(const PositionComponent&) = default;
    PositionComponent(Vector2 pos)
        : m_Position(pos) {}

    PositionComponent(float x, float y) { m_Position.x = x; m_Position.y = y; }

    void SetPosition(Vector2 newPos);
    void SetPosition(float x, float y);

    void Move(Vector2 move);
    void Move(float x, float y);

    Vector2 GetPosition() const;
private:
    Vector2 m_Position;
};