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

    static void clearLastFrame(SDL_Renderer &renderer);

    static void drawDebugText(SDL_Renderer &renderer);

    static void drawMap(Map &map, int drawingOffset, SDL_Renderer &renderer, int &rectW, int &rectH);

    static void drawPlayer(SDL_Renderer &renderer, Player &player, int rectW, int rectH, int drawingOffset);
};


#endif //CPROG_PROJECT_PLANERENDERER_H
