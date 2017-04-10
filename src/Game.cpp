#include "Game.h"

/*
 TODO:
 - OPTIONS PANEL STUFF
  - Screensize
  - Fullscreen?
 */

Game::Game(const std::string &title, int width, int height)
	: _TITLE(title)
	, _WIDTH(width)
    , _HEIGHT(height)
{
    if(initGame())
		_isRunning = true;
}

Game::~Game()
{
	if(_window != nullptr)
	{
		SDL_DestroyWindow(_window);
	}

	if(_renderer != nullptr)
	{
		SDL_DestroyRenderer(_renderer);
	}

	SDL_Quit();
}

bool Game::initGame()
{
	// -- Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::printf("Init error: %s\n", SDL_GetError());
		return false;
	}

	_window = SDL_CreateWindow(_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _WIDTH, _HEIGHT, SDL_WINDOW_SHOWN);
	if(_window == nullptr)
	{
		SDL_Quit();
		std::printf("Window creation error: %s\n", SDL_GetError());
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(_renderer == nullptr)
	{
		SDL_DestroyWindow(_window);
		SDL_Quit();
		std::printf("Renderer creation error: %s\n", SDL_GetError());
		return false;
	}

	if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
		std::printf("Init error: %s\n", IMG_GetError());
		return false;
	}

	if(TTF_Init() != 0)
	{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
		std::printf("Init error: %s\n", TTF_GetError());
		return false;
	}
    
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
    {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
        SDL_Quit();
        std::printf("Init error: %s\n", Mix_GetError());
        return false;
    }
    
	SDL_SetRenderDrawColor(_renderer, 74, 74, 74, 255);
	//SDL_RenderSetScale(_renderer, 4, 4);
    initAssets();
    
    _stateManager.addState(new SplashState(&_stateManager, &_audManager));
    
	return true;
}

void Game::initAssets()
{
    // Load all textures
    _texManager.addTexture("Unit", getResourcePath("/Assets/Graphics/Unit.png"), _renderer);
    _texManager.addTexture("Tile", getResourcePath("/Assets/Graphics/Tile.png"), _renderer);
    _texManager.addTexture("Gui", getResourcePath("/Assets/Graphics/GUI.png"), _renderer);
    _texManager.addTexture("Cylinder", getResourcePath("/Assets/Graphics/Cilinder.png"), _renderer);
    _texManager.addTexture("Motor", getResourcePath("/Assets/Graphics/Motor.png"), _renderer);
    _texManager.addTexture("Prefab", getResourcePath("/Assets/Graphics/Prefab.png"), _renderer);
    _texManager.addTexture("Storage", getResourcePath("/Assets/Graphics/Storage.png"), _renderer);
    _texManager.addTexture("Worker", getResourcePath("/Assets/Graphics/Worker.png"), _renderer);
    _texManager.addTexture("InventorySlot", getResourcePath("/Assets/Graphics/InventorySlot.png"), _renderer);
    _texManager.addTexture("Logo", getResourcePath("/Assets/Graphics/Logo.png"), _renderer);
    _texManager.addTexture("Button", getResourcePath("/Assets/Graphics/Button.png"), _renderer);
    _texManager.addTexture("SplashScreen", getResourcePath("/Assets/Graphics/Splash.png"), _renderer);
    _texManager.addTexture("ButtonNorm", getResourcePath("/Assets/Graphics/ButtonNormal.png"), _renderer);
    _texManager.addTexture("Icons", getResourcePath("/Assets/Graphics/Icons.png"), _renderer);
    _texManager.addTexture("ButtonMenu", getResourcePath("/Assets/Graphics/ButtonMenu.png"), _renderer);
    _texManager.addTexture("EnergyCell", getResourcePath("/Assets/Graphics/EnergyFrame.png"), _renderer);
    
    // Load all fonts
    _texManager.addFont("MainMenuText", getResourcePath("/Assets/Graphics/PixArial.TTF"), 8, _renderer);
    _texManager.addFont("ButtonText", getResourcePath("/Assets/Graphics/PixArial.TTF"), 16, _renderer);
    
    // Load all audio
    _audManager.addSound("ButtonHover", getResourcePath("/Assets/Audio/buttonHover.wav"));
    _audManager.addSound("ButtonPress", getResourcePath("/Assets/Audio/buttonPress.wav"));
    _audManager.addSound("UnitShoot", getResourcePath("/Assets/Audio/unitShoot.wav"));
	_audManager.addMusic("BackgroundMs", getResourcePath("/Assets/Audio/music.mp3"));
}

void Game::run()
{
	while(_isRunning)
	{
		handleInput();
		update();
		render();
	}
}

void Game::update()
{
    _stateManager.update();
}

void Game::render()
{
	SDL_RenderClear(_renderer);
    
    _stateManager.render(_renderer, _texManager);
    
	SDL_SetRenderDrawColor(_renderer, 74, 74, 74, 255);
	SDL_RenderPresent(_renderer);
}

void Game::handleInput()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
			_isRunning = false;
        
        _stateManager.handleInput(e);
	}
}

std::string Game::getResourcePath(const std::string &path)
{
    std::string basePath;
    if(basePath.empty())
    {
        char* base = SDL_GetBasePath();
        if(base)
        {
            basePath = base;
            SDL_free(base);
        }
        else
        {
            std::printf("Error getting base: %s\n", SDL_GetError());
            return "";
        }
        basePath.append(path);
    }
    return basePath;
}