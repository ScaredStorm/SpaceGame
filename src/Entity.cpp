#include "Entity.h"

Entity::Entity(int x, int y)
    :_x(x)
    ,_y(y)
    ,_minHp(10)
    ,_maxHp(10)
{
}

Entity::Entity(Vector2 pos)
    :_x(pos.x)
    ,_y(pos.y)
    ,_minHp(10)
    ,_maxHp(10)
{
}

Entity::~Entity()
{
}

float Entity::getX()
{
    return _x;
}

float Entity::getY()
{
    return _y;
}