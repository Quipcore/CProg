#ifndef CPROG_PROJECT_ENGINE_H
#define CPROG_PROJECT_ENGINE_H

#include <vector>
#include "SDL2/SDL.h"
#include "scripts/GameObject.h"
#include "springhawk/Time.h"
#include "springhawk/Scene.h"
#include "springhawk/renderers/Renderer.h"
#include "Input.h"
#include "maps/Map.h"

namespace springhawk {
    class Engine: Time{
    public:
        static int run(std::vector<Scene*>& scenes);
    private:
        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;

        //Might causes prefomance issues
        static void (*render)(SDL_Renderer &, std::vector<GameObject *> &, Map &, int, int);

        static bool init();
        static bool isOutOfBounds(Vector2 &objectPosition, Map &map);

        static void sleep(int);
        static void quit(SDL_Window* window, SDL_Renderer* renderer);
        static void playScene(Scene &scene, SDL_Renderer &sdlRenderer);
        static void handleEvent(SDL_Event &event);
        static void startGameLoop(SDL_Renderer &renderer, std::vector<GameObject *> &gameObjects, Map &map);
        static void checkForMapCollision(Vector2 &vector2, Map &map);
    };
}


#endif //CPROG_PROJECT_ENGINE_H
