#include "Grid.h"

void Grid::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	for(int x = 0; x < 1280/tileSizeX; ++x)
	{
		SDL_RenderDrawLine(renderer, 0+(tileSizeX*x), 0, 0+(tileSizeX*x), 720);	
	}
	for(int y = 0; y < 720/tileSizeY; ++y)
	{
		SDL_RenderDrawLine(renderer, 0, 0+(tileSizeY*y), 1280, 0+(tileSizeY*y));	
	}
}

int Grid::getPosX(int gridPos)
{
    return gridPos * tileSizeX;
}

int Grid::getPosY(int gridPos)
{
    
    return gridPos * tileSizeY;
}

int Grid::getMachinePosX(int gridPos)
{
    return (gridPos * tileSizeX) + 16;
}

int Grid::getMachinePosY(int gridPos)
{
    return (gridPos * tileSizeX) - 8;
}