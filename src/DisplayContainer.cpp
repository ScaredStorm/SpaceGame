#include "DisplayContainer.h"

DisplayContainer::DisplayContainer(const int size, const int rX, const int rY, const int rowCount, const int columnCount)
	: _x(rX)
	, _y(rY)
	, _rowCount(rowCount)
	, _columnCount(columnCount)
	, _size(size)
{
}

DisplayContainer::~DisplayContainer()
{
}

void DisplayContainer::setRenderX(int x)
{
	_x = x;
}

void DisplayContainer::setRenderY(int y)
{
	_y = y;
}

void DisplayContainer::update()
{
}

void DisplayContainer::handleInput(SDL_Event &e, Camera &cam)
{
}

void DisplayContainer::render(SDL_Renderer *renderer, TextureManager &manager, Camera &cam)
{
	for(int y = 0; y < _columnCount; ++y)
	{
		for(int x = 0; x < _rowCount; ++x)
		{
			manager.renderTexture("InventorySlot", Vector2(_x + (50*x), _y + (50 * y)), Vector2(48,48), renderer, SDL_FLIP_NONE);
		}
	}
}