#include "EnergyCell.h"

EnergyCell::EnergyCell(int x, int y)
	: Machine(x, y)
{
	info.name = "ENERGYCELL";
	info.maxEnergy = 20;
	info.maxEnergyGeneration = 0;
	info.maxEnergyUsage = 0;
	info.maxFuel = 0;
	info.maxFuelUsage = 0;
}

EnergyCell::~EnergyCell()
{
}

void EnergyCell::update()
{
}

void EnergyCell::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
	manager.renderTexture("EnergyCell", Vector2(_x - camera.getX(), _y - camera.getY()), Vector2(32, 32), renderer);
}

void EnergyCell::handleInput(SDL_Event &e, Camera &cam)
{

}