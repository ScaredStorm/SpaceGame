#include "MenuState.h"

MenuState::MenuState(StateManager *stateManager, AudioManager *audioManager)
: _mbStart("Start", 1280/2 - 128/2, 720/2 - 68, 128, 64, 2)
, _mbInfo("Info", 1280/2 - 128/2, 720/2, 128, 64, 2)
, _mbQuit("Quit", 1280/2 - 128/2, 720/2 + 68, 128, 64, 2)
{
    _sManager = stateManager;
    _aManager = audioManager;
}

void MenuState::update()
{
    /* CHECK BUTTONS IF CLICKED */
    if(_mbStart.isClicked())
    {
        _mbStart.setClicked(false);
        _sManager->addState(new GameState(_sManager, _aManager));
    }
}

void MenuState::handleInput(SDL_Event &e)
{
    _mbStart.handleInput(e, _aManager);
    _mbInfo.handleInput(e, _aManager);
    _mbQuit.handleInput(e, _aManager);
}

void MenuState::render(SDL_Renderer *renderer, TextureManager &manager)
{
    /* RENDER LOGO */
    manager.renderTexture("Logo", Vector2(1280/2-447/2, 146), Vector2(447, 146), renderer);
    
    /* RENDER BUTTONS */
    _mbStart.render(renderer, manager);
    _mbInfo.render(renderer, manager);
    _mbQuit.render(renderer, manager);
    SDL_Color col;
	col.r = col.g = col.b = col.a = 255;
    manager.renderText("MainMenuText", "[EARLY-ALPHA]", Vector2(5, 720-16), 0, 8, renderer, col);
}
