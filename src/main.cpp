#define SDL_MAIN_HANDLED

#include "springhawk/Engine.h"
#include "scripts/GameObject.h"
#include "scripts/Square.h"
#include "scripts/Player.h"
#include <array>

//Screen dimension constants
const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 400;



std::array<std::array<int,5>,5> map = {
        {
            {1,1,1,1,1},
            {1,0,0,0,1},
            {1,0,2,0,1},
            {1,0,0,0,1},
            {1,1,1,1,1}
        }
};

int main( int argc, char* args[] )
{
    std::vector<GameObject*> gameObjects = {
            new class Player()
    };
    return Springhawk::Engine::run(SCREEN_WIDTH, SCREEN_HEIGHT, gameObjects);
}
