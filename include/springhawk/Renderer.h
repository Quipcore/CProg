//
// Created by felix on 2023-11-12.
//

#ifndef CPROG_PROJECT_RENDERER_H
#define CPROG_PROJECT_RENDERER_H

#include <SDL2/SDL.h>
#include <vector>
#include "scripts/GameObject.h"
#include "scripts/Player.h"

class Renderer {
public:
    static void render(SDL_Renderer*, std::vector<GameObject*>&,int,int);

private:
    static void drawMap(SDL_Renderer *pRenderer);
    static const int mapWidth = 8;
    static const int mapHeight = 8;
    static int map[mapWidth][mapHeight];

    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;

    static void drawObjects(SDL_Renderer *pRenderer, std::vector<GameObject *> &vector);

    static void drawPlayer(SDL_Renderer *pRenderer,class Player *const &player);
    static Vector2 findEndPosition(Vector2 &position, Vector2 &direction, float maxDistance);
};


#endif //CPROG_PROJECT_RENDERER_H
