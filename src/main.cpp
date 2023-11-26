#define SDL_MAIN_HANDLED

#include "games/Tetris.h"
#include "games/Wolfenstein.h"
#include <vector>

int main( int argc, char* args[] )
{
    //START
    std::vector<Game*> games = {
            new Wolfenstein(),
            //new Tetris()
    };

    for(Game* game : games){
        game->run();
    }
    //STOP


//    std::vector<GameObject*> gameObjects = {
//            new class Player()
//    };
//    return springhawk::Engine::run(SCREEN_WIDTH, SCREEN_HEIGHT, gameObjects);
}
