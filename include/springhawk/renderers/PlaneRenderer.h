//
// Created by felix on 2023-12-07.
//

#ifndef CPROG_PROJECT_PLANERENDERER_H
#define CPROG_PROJECT_PLANERENDERER_H

#include <vector>
#include "SDL2/SDL.h"
#include "components/Gamecomponents/GameObject.h"
#include "components/Gamecomponents/Player.h"
#include "springhawk/maps/Map.h"

class PlaneRenderer {
public:
    static void render(SDL_Renderer&, std::vector<GameObject*>&, Map&, int,int);

private:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;

    static void drawMap(Map &map, int drawingOffset, SDL_Renderer &renderer, int &rectW, int &rectH);
    static void drawGameObjects(SDL_Renderer &renderer, std::vector<GameObject *> &vector, int w, int h, int offset);
};


#endif //CPROG_PROJECT_PLANERENDERER_H
