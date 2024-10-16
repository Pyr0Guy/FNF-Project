#include "include/Entity.hpp"
#include "include/globals.hpp"

Entity::Entity()
{
    m_id = id++;
    m_Position.x = 0;
    m_Position.y = 0;

}