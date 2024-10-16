#pragma once

#include <raylib.h>

#include "types.hpp"

class Entity
{
public:
    Entity();
    virtual ~Entity() {};

    inline Vector2 GetPosition() const  { return m_Position;    }
    inline u32 GetID() const            { return m_id;          }

    void Draw();
private:
    u32 m_id;
    Vector2 m_Position;
};