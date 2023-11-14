//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_GAME_H
#define CPROG_PROJECT_GAME_H

#include <vector>
#include "springhawk/Scene.h"

class Game {
public:
    Game();
    ~Game();
    virtual void run();
private:
    std::vector<Scene*> scenes;
};


#endif //CPROG_PROJECT_GAME_H
