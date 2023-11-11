#ifndef CPROG_PROJECT_ENGINE_H
#define CPROG_PROJECT_ENGINE_H

#include <vector>
#include "SDL2/SDL.h"
#include "scripts/GameObject.h"

namespace Springhawk {
    class Engine {
    public:
        static int run(int screenWidth, int screenHeight, std::vector<GameObject *> &gameObjects);
    private:

        static bool init();


        static std::vector<SDL_Texture*> loadTextures(SDL_Renderer *pRenderer);

        static void
        keepOpen(SDL_Renderer *pRenderer, std::vector<SDL_Texture *> &textures, std::vector<GameObject *> vector);
        static void render(SDL_Renderer *renderer, std::vector<SDL_Texture *> &textures);

        static void quit(SDL_Window *window, SDL_Renderer *renderer, std::vector<SDL_Texture*> &textures);
    };
}


#endif //CPROG_PROJECT_ENGINE_H
