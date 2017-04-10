#include "Machine.h"

Machine::Machine(int x, int y)
    : _x(x)
    , _y(y)
{
}

Machine::Machine(Vector2 pos)
    : _x(pos.x)
    , _y(pos.y)
{
}

Machine::~Machine()
{
}

int Machine::getX()
{
    return _x;
}

int Machine::getY()
{
    return _y;
}

MACHINE_INFO Machine::getInfo()
{
	return info;
}