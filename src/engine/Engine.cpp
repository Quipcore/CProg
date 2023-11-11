#include "engine/Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include "Constants.h" //gResPath-contains the path to your resources.


//#define FPS 60

int Springhawk::Engine::run(int screenWidth, int screenHeight, std::vector<GameObject *> &gameObjects) {

    if(init()){
        throw std::runtime_error("Failed to initialize!");
    }

    SDL_Window* window = SDL_CreateWindow("Window", 100, 100, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    std::vector<SDL_Texture*> textures = loadTextures(renderer);

    keepOpen(renderer, textures, gameObjects);

    quit(window, renderer, textures);

    return EXIT_SUCCESS;
}

// Städa innan programmet avslutas!
void Springhawk::Engine::quit(SDL_Window *window, SDL_Renderer *renderer,std::vector<SDL_Texture*> &textures) {
    for(SDL_Texture* texture : textures){
        SDL_DestroyTexture(texture);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}

void Springhawk::Engine::render(SDL_Renderer *renderer, std::vector<SDL_Texture*> &textures) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, textures[0], NULL, NULL);
    SDL_RenderPresent(renderer);
}

bool Springhawk::Engine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error SDL2 Initialization : " << SDL_GetError();
        return EXIT_FAILURE;
    }

    if (TTF_Init() < 0)
    {
        std::cout << "Error SDL_ttf Initialization : " << SDL_GetError();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

std::vector<SDL_Texture*> Springhawk::Engine::loadTextures(SDL_Renderer* pRenderer) {
    std::vector<SDL_Texture*> textures;

    SDL_Surface* bg_sur = IMG_Load( (constants::gResPath + "images/bg.jpg").c_str() );
    SDL_Texture* bg_tex = SDL_CreateTextureFromSurface(pRenderer, bg_sur);
    SDL_FreeSurface(bg_sur);

    textures.push_back(bg_tex);
    return textures;
}

// Loop till dess att programmet avslutas!
void Springhawk::Engine::keepOpen(SDL_Renderer *pRenderer, std::vector<SDL_Texture *> &textures,
                                  std::vector<GameObject *> gameObjects) {

    std::vector<GameObject*> gameObject = getGameObjects();

    bool running = true;
    while (running) {
        SDL_Event e;

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        for(GameObject* gameObject : gameObjects){
            gameObject->update();
        }

        render(pRenderer, textures);
    }
}

std::vector<GameObject*> Springhawk::Engine::getGameObjects() {
    std::vector<GameObject*> gameObjects;
    return gameObjects;
}
