#ifndef CPROG_PROJECT_ENGINE_H
#define CPROG_PROJECT_ENGINE_H

#include <vector>
#include "SDL2/SDL.h"
#include "scripts/GameObject.h"
#include "springhawk/Time.h"
#include "springhawk/Scene.h"
#include "springhawk/renderers/Renderer.h"

namespace springhawk {
    class Engine: Time{
    public:
        static int run(std::vector<Scene*> scenes);
    private:
        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;

        //Might causes prefomance issues
        static void (*render)(SDL_Renderer*, std::vector<GameObject*>, Player*, std::vector<std::vector<int>>, int, int);

        static bool init();
        static std::vector<SDL_Texture*> loadTextures(SDL_Renderer *pRenderer);
        static void handleEvent(SDL_Event*);
        static void sleep(int);

        static void playScene(Scene *scene, SDL_Renderer *sdlRenderer);
        static void keepOpen(SDL_Renderer *pRenderer, std::vector<GameObject *> vector1, Player *pPlayer,
                             std::vector<std::vector<int>> vector2);
        static void draw(SDL_Renderer *pRenderer, std::vector<GameObject *> vector1, Player *pPlayer,
                         std::vector<std::vector<int>> vector2);

        static void quit(SDL_Window *window, SDL_Renderer *renderer);
        static void quit(SDL_Window *window, SDL_Renderer *renderer, std::vector<SDL_Texture *> &textures);

        static bool isOutOfBounds(Vector2 vector2, std::vector<std::vector<int>> vector1);

        static Vector2 getValidPos(std::vector<std::vector<int>> map);
    };
}


#endif //CPROG_PROJECT_ENGINE_H
