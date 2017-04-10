#include "Cylinder.h"

Cylinder::Cylinder(int x, int y)
    : Machine(x, y)
{
    _frameRate = 100;
    _frame = rand()%5;
    _totalFrame = 5;
    _oldTime = SDL_GetTicks();

	info.name = "CYLINDER";
	info.maxEnergy = 0;
	info.maxEnergyGeneration = 0;
	info.maxEnergyUsage = 0;
	info.maxFuel = 5;
	info.maxFuelUsage = 5;
}

Cylinder::~Cylinder()
{
}

void Cylinder::update()
{
    // -- Animate
    if(_oldTime + _frameRate < SDL_GetTicks())
    {
        _oldTime = SDL_GetTicks();
        _frame++;
        if(_frame > _totalFrame)
            _frame = 0;
    }
}

void Cylinder::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
    manager.renderTextureFrame("Cylinder", Vector2(_x - camera.getX(), _y - camera.getY()), Vector2(32, 32), Vector2(_frame, 0), renderer);
}

void Cylinder::handleInput(SDL_Event &e, Camera &cam)
{
}