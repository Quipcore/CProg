#include "springhawk/raycaster/Raycaster.h"
#include "iostream"
#include "SDL2/SDL.h"



int Springhawk::Raycaster::run(int screenWidth, int screenHeight, std::array<std::array<int, MAP_WIDTH>, MAP_HEIGHT> map) {

    createWindowExit windowExit = createWindow(screenWidth,screenHeight);
    if(windowExit.window != nullptr){
        return windowExit.exitcode;
    }

    SDL_Window* window = windowExit.window;
    //Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Update the surface
    SDL_UpdateWindowSurface( window );
    stayUp();

    return 0;
}

void Springhawk::Raycaster::stayUp(){
    SDL_Event e;
    bool quit = false;
    while(!quit){
        while( SDL_PollEvent( &e ) ){
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
        }
    }
}

createWindowExit Springhawk::Raycaster::createWindow(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error SDL2 Initialization : " << SDL_GetError();
        return {EXIT_FAILURE, nullptr};
    }

    SDL_Window* window 		= SDL_CreateWindow("Window", 100, 100, 800, 600, 0);
    SDL_Renderer* renderer 	= SDL_CreateRenderer(window, -1, 0);

    return {0,window,renderer};
}

