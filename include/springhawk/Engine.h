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

        static void keepOpen(SDL_Renderer*, std::vector<SDL_Texture *>&, std::vector<GameObject *>&);
        static void handleEvent(SDL_Event*);
        static void render(SDL_Renderer *renderer, std::vector<SDL_Texture *> &textures);
        static void draw(SDL_Renderer *pRenderer, std::vector<GameObject*>& gameObjects);
        static void sleep(int);
        static void quit(SDL_Window *window, SDL_Renderer *renderer, std::vector<SDL_Texture*> &textures);

        static int SCREEN_WIDTH;
        static int SCREEN_HEIGHT;
    };
}


#endif //CPROG_PROJECT_ENGINE_H
