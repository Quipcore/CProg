#define SDL_MAIN_HANDLED

//#include "games/Game.h"
//#include "games/Tetris.h"
//#include "games/Wolfenstein.h"

#include <vector>
#include <iostream>
#include "games/Wolfenstein.h"
#include "games/PacMan.h"
#include "games/Tetris.h"

int main( int argc, char* args[] )
{
    //START
    std::vector<Game*> games = {
//            new PacMan(),
            new Wolfenstein(),
//            new Tetris()
    };

    for(Game* game : games){
        game->run();
    }



    return 0;
}
