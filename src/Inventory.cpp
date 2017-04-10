#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::setItem(int id)
{
	//
}

void Inventory::update()
{
	//
}

void Inventory::render(SDL_Renderer *renderer, TextureManager &manager, Camera &cam)
{
	for(int i = 0; i < _items.size(); ++i)
	{
		_items[i]->render(renderer, manager, cam);
	}
}