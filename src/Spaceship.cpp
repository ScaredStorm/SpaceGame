#include "Spaceship.h"

Spaceship::Spaceship(AudioManager *audioManager)
: _gui(audioManager)
{
    _aManager = audioManager;
	// -- create default spaceship
    std::printf("Creating default ship...\n");
    createDefault();
}

Spaceship::Spaceship(AudioManager *audioManager, const std::string &file, const std::string &machineFile)
: _gui(audioManager)
{
	// -- load spaceship from file
    _aManager = audioManager;
    std::string save;
    
	std::ifstream f(file, std::fstream::in);
    if(f.is_open())
    {
        while(std::getline(f, save))
        {
            _save.push_back(save);
        }
        f.close();
    }
    else
    {
        std::printf("Error: Save does not exists\nCreating default ship...");
        createDefault();
        return;
    }
    
    std::string msave;
    std::ifstream fm(machineFile, std::fstream::in);
    if(fm.is_open())
    {
        std::printf("Machine Save Found...\n");
        while(std::getline(fm, msave))
        {
            _machineSave.push_back(msave);
        }
    }
    
    constructFromSave();
}

void Spaceship::constructFromSave()
{
    if(_save.empty())
    {
        std::printf("Error: empty save!\n");
        return;
    }
    else
    {
        std::printf("Preparing save...\n");
        
        for(int y = 0; y < _save.size(); y++)
        {
            std::vector<Tile> xrow;
            for(int x = 0; x < _save[y].length(); x++)
            {
                if(_save[y][x] == '1')
                {
                    xrow.push_back(Tile(Grid::getPosX(x-y), Grid::getPosY(y+x), TYPE_NORMAL));
                }
                else
                {
                    xrow.push_back(Tile(Grid::getPosX(x-y), Grid::getPosY(y+x), TYPE_EMPTY));
                }
            }
            _tiles.push_back(xrow);
        }
        
        std::printf("Done loading save...\n");
    }
    
    if(_machineSave.empty())
    {
        std::printf("Warning: No Machines!\n");
        return;
    }
    else
    {
        std::printf("Preparing machines...\n");
        
        for(int y = 0; y < _machineSave.size(); y++)
        {
            for(int x = 0; x < _machineSave[y].length(); x++)
            {
                if(_machineSave[y][x] == '1')
                {
                    // motor
                    _machines.push_back(std::make_shared<Motor>(Motor(Grid::getPosX(x-y)+16, Grid::getPosY(y+x)-8)));
                }
                else if(_machineSave[y][x] == '2')
                {
                    // cylinder
                    _machines.push_back(std::make_shared<Cylinder>(Cylinder(Grid::getPosX(x-y)+16, Grid::getPosY(y+x)-8)));
                }
                else if(_machineSave[y][x] == '3')
                {
                    // storage
                    _machines.push_back(std::make_shared<Storage>(Storage(Grid::getPosX(x-y)+16, Grid::getPosY(y+x)-8)));
                }
				else if(_machineSave[y][x] == '4')
				{
					_machines.push_back(std::make_shared<EnergyCell>(EnergyCell(Grid::getPosX(x-y)+16, Grid::getPosY(y+x)-8)));
				}
            }
        }
        std::printf("Done loading machines...\n");
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
			int x = rand()%tileSizeX;
			int y = rand()%tileSizeY;

            if(j%3 == 0 && i%3 == 0)
            {
                std::printf("Creating enemy unit\n");
				x*2;
				y*2;
                //_entities.push_back(std::make_shared<EnemyUnit>(EnemyUnit(Grid::getPosX(x-y)+16, Grid::getPosY(y+x)-8)));
            }
            else
            {
                _entities.push_back(std::make_shared<Unit>(Unit(Grid::getPosX(x-y)+16, Grid::getPosY(y+x)-8)));
            }
        }
    }
}

void Spaceship::createDefault()
{
    // -- Create level 50x50
    for(int y = 0; y < 50; y++)
    {
        std::vector<Tile> xrow;
        for(int x = 0; x < 50; x++)
        {
            if(x > 10 && y > 0 && x < 30 && y < 20)
                xrow.push_back(Tile(Grid::getPosX(x-y), Grid::getPosY(y+x), TYPE_NORMAL));
            else
                xrow.push_back(Tile(Grid::getPosX(x-y), Grid::getPosY(y+x), TYPE_EMPTY));
        }
        _tiles.push_back(xrow);
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j%3 == 0)
            {
                std::printf("Creating enemy unit\n");
                _entities.push_back(std::make_shared<EnemyUnit>(EnemyUnit(Grid::getPosX(i-j)+16, Grid::getPosY(j+i)-8)));
            }
            else
            {
                _entities.push_back(std::make_shared<Unit>(Unit(Grid::getPosX(i-j)+16, Grid::getPosY(j+i)-8)));
            }
        }
    }
}

// -- Main game logic stuff
void Spaceship::openTile(int x, int y, int layer)
{
    _tiles[y][x].setType(TYPE_NORMAL);
}

void Spaceship::handleInput(SDL_Event &e, Camera &cam)
{
    for each(auto& u in _entities)
    {
        u->handleInput(e, cam);
    }
    
	if(e.type == SDL_MOUSEBUTTONDOWN)
	{
		if(e.button.button == SDL_BUTTON_MIDDLE)
		{
			int x,y;
			SDL_GetMouseState(&x, &y);
			x = (x + cam.getX()) / tileSizeX;
			y = (y + cam.getY()) / tileSizeY;
			_entities.push_back(std::make_shared<EnemyUnit>(EnemyUnit(Grid::getPosX(x-y)+16, Grid::getPosY(y+x)-8)));
		}
	}

    _gui.handleInput(e);
}

void Spaceship::update()
{
    for each(auto& mach in _machines)
    {
        mach->update();
    }
    
    for each(auto& u in _entities)
    {
        u->update(_entities);
    }
    
    _gui.update(_machines);
}

void Spaceship::render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera)
{
    for(int y = 0; y < _tiles.size(); y++)
    {
        for(int x = 0; x < _tiles[y].size(); x++)
        {
            _tiles[y][x].render(manager, renderer, camera);
        }
    }
    
    for each(auto& mach in _machines)
    {
        mach->render(renderer, manager, camera);
    }
    
    for each(auto& u in _entities)
    {
        u->render(renderer, manager, camera);
    }
    
    _gui.render(renderer, manager, camera);
}