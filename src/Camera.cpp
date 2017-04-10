#include "Camera.h"

Camera::Camera(int x, int y, int width, int height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}

void Camera::setX(int x)
{
    _x = x;
}

void Camera::setY(int y)
{
    _y = y;
}

void Camera::setPosition(Vector2 position)
{
    _x = position.x;
    _y = position.y;
}

int Camera::getX()
{
    return _x;
}

int Camera::getY()
{
    return _y;
}

Vector2 Camera::getPosition()
{
    return Vector2(_x, _y);
}