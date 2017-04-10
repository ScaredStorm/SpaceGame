#include "Gui.h"

Gui::Gui(AudioManager *audioManager)
    : _b(2, 1280-74, 720-74, 64, 64, 0)
{
    _aManager = audioManager;
}

Gui::~Gui()
{
    delete _aManager;
}

void Gui::update(std::vector<std::shared_ptr<Machine>> m)
{
    if(_machines != m)
    {
        _machines = m;
    }
    _b.update();
}

void Gui::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
    // TODO: Render ICONS Per Machine
    // TODO: Button open inv
    // TODO: Render Capacity of machines
    // TODO: Render text
    
    manager.renderTexture("Gui", Vector2(0,0), Vector2(1280, 100), renderer);

	for(int i = 0; i < _machines.size(); i++)
	{
		if(_machines[i]->getInfo().name == "MOTOR")
		{
			manager.renderTextureFrame("Icons", Vector2(16, 720-48*2+8), Vector2(32, 32), Vector2(0,0), renderer);

			SDL_Rect motorRect;
			motorRect.x = 16;
			motorRect.y = 720-48;
			motorRect.w = 150;
			motorRect.h = 32;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(renderer, &motorRect);
		}

		if(_machines[i]->getInfo().name == "ENERGYCELL")
		{
			manager.renderTextureFrame("Icons", Vector2(182, 720-48*2+8), Vector2(32, 32), Vector2(1,0), renderer);
			SDL_Rect energyCell;
			energyCell.x = 182;
			energyCell.y = 720-48;
			energyCell.w = 150;
			energyCell.h = 32;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(renderer, &energyCell);
		}

		if(_machines[i]->getInfo().name == "STORAGE")
		{
			manager.renderTextureFrame("Icons", Vector2(348, 720-48*2+8), Vector2(32, 32), Vector2(2,0), renderer);
			SDL_Rect energyCell;
			energyCell.x = 348;
			energyCell.y = 720-48;
			energyCell.w = 150;
			energyCell.h = 32;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(renderer, &energyCell);
		}
	}

    _b.render(renderer, manager);
}

void Gui::handleInput(SDL_Event &e)
{
    _b.handleInput(e, _aManager);
}