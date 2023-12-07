//
// Created by felix on 2023-12-07.
//

#ifndef CPROG_PROJECT_PLANERENDERER_H
#define CPROG_PROJECT_PLANERENDERER_H

#include <vector>
#include "SDL2/SDL.h"
#include "scripts/GameObject.h"
#include "scripts/Player.h"
#include "springhawk/maps/Map.h"

class PlaneRenderer {
public:
    static void render(SDL_Renderer&, std::vector<GameObject*>&, Player&, Map&, int,int);
private:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
};


#endif //CPROG_PROJECT_PLANERENDERER_H
