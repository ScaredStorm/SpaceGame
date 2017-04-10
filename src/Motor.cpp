#include "Motor.h"

Motor::Motor(int x, int y)
    : Machine(x, y)
{
    _type = MOTOR_BASIC;
    
    info.name = "MOTOR";
	info.maxEnergy = 0;
	info.maxEnergyGeneration = 15;
	info.maxEnergyUsage = 10;
	info.maxFuel = (12 * (_type+1))*5;
	info.maxFuelUsage = 5;

    _maxCyl = 12 * (_type+1);
}

Motor::Motor(int x, int y, MotorType type)
    : Machine(x, y)
    , _type(type)
{
	info.name = "MOTOR";
	info.maxEnergy = 0;
	info.maxEnergyGeneration = 15;
	info.maxEnergyUsage = 10;
	info.maxFuel = (12 * (_type+1))*5;
	info.maxFuelUsage = 5;

    _maxCyl = 12 * (_type+1);
}

Motor::~Motor()
{
}

void Motor::update()
{
}

void Motor::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
    manager.renderTexture("Motor", Vector2(_x - camera.getX(), _y - camera.getY()), Vector2(32, 32), renderer);
}

void Motor::handleInput(SDL_Event &e, Camera &cam)
{
}

/*int Motor::getEnergyUsage() const
{
    return _maxEnergyUsage;
}

int Motor::getFuelUsage() const
{
    return _maxFuelUsage;
}
*/
int Motor::getCylCount() const
{
    return _totalCyl;
}

int Motor::getMaxCylCount() const
{
    return _maxCyl;
}

void Motor::increaseCylCount(int inc)
{
    if(_totalCyl < _maxCyl)
        _totalCyl++;
}

void Motor::decreaseCylCount(int dec)
{
    if(_totalCyl > 0)
        _totalCyl--;
}



