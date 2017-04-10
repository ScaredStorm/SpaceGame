#include "Storage.h"

Storage::Storage(int x, int y)
: Machine(x, y)
{
    _frameRate = 200;
    _frame = 0;
    _totalFrame = 16;
    _oldTime = SDL_GetTicks();

	info.name = "STORAGE";
	info.maxEnergy = 5;
	info.maxEnergyGeneration = 0;
	info.maxEnergyUsage = 10;
	info.maxFuel = 0;
	info.maxFuelUsage = 0;
}

Storage::~Storage()
{
}

void Storage::update()
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

void Storage::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
    manager.renderTextureFrame("Storage", Vector2(_x - camera.getX(), _y - camera.getY()), Vector2(32, 32), Vector2(_frame, 0), renderer);
}

void Storage::handleInput(SDL_Event &e, Camera &cam)
{
}