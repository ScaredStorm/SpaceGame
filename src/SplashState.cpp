#include "SplashState.h"

SplashState::SplashState(StateManager *stateManger, AudioManager *audioManager)
{
    _sManager = stateManger;
    _aManager = audioManager;
    
    _oldTime = SDL_GetTicks();
    _timeCountDown = 5000;
}

void SplashState::update()
{
    if(_oldTime + _timeCountDown < SDL_GetTicks())
    {
        _sManager->addState(new MenuState(_sManager, _aManager));
    }
}

void SplashState::render(SDL_Renderer *renderer, TextureManager &manager)
{
    manager.renderTexture("SplashScreen", Vector2(0, 0), Vector2(1280, 720), renderer);
}

void SplashState::handleInput(SDL_Event &e)
{
    // Do Nothing
}