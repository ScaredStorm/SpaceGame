#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(int x, int y)
    : Entity(x, y)
{
    _frameRate = 200;
    _frame = rand()%4;
    _totalFrame = 3;
    _oldTime = SDL_GetTicks();
    destination = Vector2(_x, _y);
}

EnemyUnit::~EnemyUnit()
{
}

void EnemyUnit::setPath(Vector2 position)
{
    destination = position;
}


void EnemyUnit::update(std::vector<std::shared_ptr<Entity>> entitys)
{
    // -- Movement
	findClosest(entitys);

    int xx = destination.x - _x;
    int yy = destination.y - _y;
    float distance = sqrtf(xx*xx + yy*yy);

    if(distance > 0 && distance < 400)
    {
		if(distance > 8)
		{
			_x += (destination.x - _x)/distance;
			_y += (destination.y - _y)/distance;
		}
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

void EnemyUnit::findClosest(std::vector<std::shared_ptr<Entity>> entitys)
{
	if(entitys.size() > 0)
	{
		Entity *e = (entitys[0].get() == this)?entitys[1].get():entitys[0].get();
		float distance = sqrtf((e->getX() - _x)*(e->getX() - _x) + (e->getY() - _y)*(e->getY() - _y));

		std::printf("Current: %f\n", distance);

		for(int i = 0; i < entitys.size(); i++)
		{
			if(entitys[i].get() != this && dynamic_cast<EnemyUnit*>(entitys[i].get()) == nullptr)
			{
				float dst = sqrtf((entitys[i].get()->getX() - _x)*(entitys[i].get()->getX() - _x) + (entitys[i].get()->getY() - _y)*(entitys[i].get()->getY() - _y));
				if(dst < distance)
				{
					std::printf("Found enemy: %f with id: %d\n", dst, i);
					e = entitys[i].get();
					distance = dst;
				}
			}
		}

		destination.x = e->getX();
		destination.y = e->getY();
	}
}

void EnemyUnit::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
    manager.renderTextureFrame("Worker", Vector2(_x - camera.getX(), _y - camera.getY()), Vector2(32, 32), Vector2(_frame, 1), renderer);
}

void EnemyUnit::handleInput(SDL_Event &e, Camera &cam)
{
}