//
// Created by felix on 2023-11-12.
//

#ifndef CPROG_PROJECT_RAYCASTER_H
#define CPROG_PROJECT_RAYCASTER_H

#include <SDL2/SDL.h>
#include <vector>
#include "scripts/GameObject.h"
#include "scripts/Player.h"
#include "springhawk/renderers/Renderer.h"
#include "springhawk/maps/Map.h"
#include "springhawk/Scene.h"

namespace springhawk {

    class Raycaster : public springhawk::Renderer {
    public:
        static void render(SDL_Renderer &pRenderer, std::vector<GameObject *> &gameobjects, Player &pPlayer,
                           std::vector<std::vector<int>> &map, int screenWidth, int screenHeight);
    private:
        static const int mapWidth = 8;
        static const int mapHeight = 8;
        static int tileMap[mapWidth][mapHeight];

        static int SCREEN_WIDTH;
        static int SCREEN_HEIGHT;

        static void drawMap(SDL_Renderer *pRenderer);
        static void drawObjects(SDL_Renderer *pRenderer, std::vector<GameObject *> &vector);
        static void drawPlayer(SDL_Renderer *pRenderer, class Player *const &player);
        static Vector2 findEndPosition(Vector2 &position, Vector2 &direction, double maxDistance);
        static bool isPositionValid(Vector2 vector2);
        static void drawRays(SDL_Renderer *pRenderer, class Player *pPlayer);
        static void setRenderDrawColor(SDL_Renderer *pRenderer,int wallValue);
        static Vector2 getIntersectionPoint(Vector2 &position, double angle);

        static Vector2 findMapPoint(Vector2 vector2);
    };
}

#endif //CPROG_PROJECT_RAYCASTER_H
