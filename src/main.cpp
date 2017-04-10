#include <string>
#include <time.h>
#include "Game.h"

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    
	Game g("Space Game", 1280, 720);
	g.run();

	return 0;
}