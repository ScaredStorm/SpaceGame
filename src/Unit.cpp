#include "Unit.h"

Unit::Unit(int x, int y)
    : Entity(x, y)
	, _inv(4, x, y, 4, 1)
{
    _frameRate = 200;
    _frame = rand()%4;
    _totalFrame = 3;
    _oldTime = SDL_GetTicks();
    destination = Vector2(_x, _y);
    _selected = false;
	_showInventory = false;
}

Unit::~Unit()
{
}

void Unit::setPath(Vector2 position)
{
    destination = position;
}

bool Unit::isSelected()
{
    return _selected;
}

void Unit::update(std::vector<std::shared_ptr<Entity>> entitys)
{
    // -- Movement
    int xx = destination.x - _x;
    int yy = destination.y - _y;
    float distance = sqrtf(xx*xx + yy*yy);
    
    if(distance > 0)
    {
        _x += (destination.x - _x)/distance;
        _y += (destination.y - _y)/distance;
    }
    
	// -- Inventory
	if(_showInventory)
	{
		_inv.setRenderX(10);
		_inv.setRenderY(100);
	}

	if(!_selected)
	{
		_showInventory = false;
	}

    // -- Animate
    if(_oldTime + _frameRate < SDL_GetTicks())
    {
        _oldTime = SDL_GetTicks();
        _frame++;
        if(_frame > _totalFrame)
            _frame = 0;
    }
}

void Unit::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
    manager.renderTextureFrame("Worker", Vector2(_x - camera.getX(), _y - camera.getY()), Vector2(32, 32), Vector2(_frame, 0), renderer);
    
    if(_selected)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect;
        rect.x = (_x - camera.getX());
        rect.y = (_y - camera.getY());
        rect.w = 32;
        rect.h = 32;
        SDL_RenderDrawRect(renderer, &rect);
    }

	if(_showInventory)
		_inv.render(renderer, manager, camera);
}

void Unit::handleInput(SDL_Event &e, Camera &cam)
{
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        int x = e.button.x;
        int y = e.button.y;
        
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            // check if mouse is inside the unit
            if((x > (_x - cam.getX())) && (x < (_x - cam.getX() + 32)) && (y > (_y - cam.getY())) && (y < (_y - cam.getY() + 32)))
            {
                _selected = !_selected;
            }
        }
        
        if(e.button.button == SDL_BUTTON_RIGHT)
        {
            if(_selected)
            {
				if((x > (_x - cam.getX())) && (x < (_x - cam.getX() + 32)) && (y > (_y - cam.getY())) && (y < (_y - cam.getY() + 32)))
				{
					_showInventory = !_showInventory;
					_inv.setRenderX(x + 48);
					_inv.setRenderY(y);
				}
				else
				{
					destination.x = Grid::getPosX((x + cam.getX())/tileSizeX)+16;
					destination.y = Grid::getPosY((y + cam.getY())/tileSizeY)-8;
				}
			}
        }
    }
}