#define SDL_MAIN_HANDLED

#include <vector>
#include "games/Wolfenstein.h"
#include "games/PacMan.h"

int main( int argc, char* args[] )
{
    std::vector<Game*> games = {
            new PacMan(),
            new Wolfenstein(),
    };

    for(Game* game : games){
        game->run();
    }

    return 0;
}
