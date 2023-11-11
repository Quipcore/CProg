#ifndef CPROG_PROJECT_RAYCASTER_H
#define CPROG_PROJECT_RAYCASTER_H

#include <array>
#include "SDL2/SDL.h"

const int MAP_HEIGHT = 5;
const int MAP_WIDTH = 5;

struct createWindowExit{
    int exitcode;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

namespace Springhawk{
    class Raycaster {
    public:
        static int run(int screenWidth , int screenHeight, std::array<std::array<int,5>,5> map);
    private:
        static createWindowExit createWindow(int width, int height);

        static void stayUp();
    };
}

#endif //CPROG_PROJECT_RAYCASTER_H
