#include "Vector2.h"

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(int x, int y)
	: x(x)
	, y(y)
{
}

Vector2 Vector2::zero()
{
	return Vector2(0,0);
}

Vector2 Vector2::operator+(Vector2 &vec)
{
    Vector2 ret = *this;
    ret.x = ret.x + vec.x;
    ret.y = ret.y + vec.y;
    return ret;
}

Vector2 Vector2::operator-(Vector2 &vec)
{
    Vector2 ret = *this;
    ret.x = ret.x - vec.x;
    ret.y = ret.y - vec.y;
    return ret;
}

Vector2 Vector2::operator*(float scalar)
{
    Vector2 ret = *this;
    ret.x = ret.x * scalar;
    ret.y = ret.y * scalar;
    return ret;
}

Vector2 Vector2::operator/(float scalar)
{
    Vector2 ret = *this;
    ret.x = ret.x / scalar;
    ret.y = ret.y / scalar;
    return ret;
}

Vector2& Vector2::operator+=(const Vector2 &vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2 &vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}