#ifndef CPROG_PROJECT_GAME_H
#define CPROG_PROJECT_GAME_H

//----------------------------------------------------------------------------------------------------------------------

#include <vector>
#include "springhawk/Scene.h"

//----------------------------------------------------------------------------------------------------------------------

class Game {
public:
    Game() = default;
    ~Game() = default;
    virtual void run() = 0;
};

#endif //CPROG_PROJECT_GAME_H