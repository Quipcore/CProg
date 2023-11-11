#include "springhawk/Engine.h"
#include "springhawk/Input.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include "Constants.h" //gResPath-contains the path to your resources.
#include "chrono"
#include "thread"

int Springhawk::Engine::SCREEN_WIDTH = 640;
int Springhawk::Engine::SCREEN_HEIGHT = 400;

int Springhawk::Engine::run(int screenWidth, int screenHeight, std::vector<GameObject *> &gameObjects) {

    SCREEN_WIDTH = screenWidth;
    SCREEN_HEIGHT = screenHeight;

    if(init()){
        throw std::runtime_error("Failed to initialize!");
    }

    SDL_Window* window = SDL_CreateWindow("Window", 100, 100, screenWidth, screenHeight, 0);
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
    SDL_RenderCopy(renderer, textures[0], nullptr, nullptr);
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
void Springhawk::Engine::keepOpen(SDL_Renderer *pRenderer, std::vector<SDL_Texture*> &textures,std::vector<GameObject*> &gameObjects) {
    while (true) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return;
            }

            handleEvent(&e);
        }

        for(const auto& gameObject : gameObjects){
            gameObject->update();
        }


        Input::setKeyCode(0);
        draw(pRenderer, gameObjects);
    }
}

void Springhawk::Engine::draw(SDL_Renderer* pRenderer, std::vector<GameObject*>& gameObjects){
    //Clear screen
    SDL_SetRenderDrawColor( pRenderer, 0, 0, 0, 0 );
    SDL_RenderClear( pRenderer );

    for(const auto& gameObject : gameObjects){
        Color color = gameObject->getColor();
        Vector2 position = gameObject->getPosition();
        SDL_Rect rect = {position.x, -position.y, 10,10};

        SDL_SetRenderDrawColor(pRenderer, color.r,color.g,color.b,color.a);
        SDL_RenderDrawRect(pRenderer,&rect);

//        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH /10, SCREEN_HEIGHT / 10 };
//        SDL_SetRenderDrawColor( pRenderer, 0xFF, 0x00, 0x00, 0xFF );
//        SDL_RenderFillRect( pRenderer, &fillRect );
    }
    SDL_RenderPresent(pRenderer);
}

void Springhawk::Engine::handleEvent(SDL_Event *event){
    if(event->type == SDL_KEYDOWN){
        Input::setKeyCode(event->key.keysym.sym);
    }
}

void Springhawk::Engine::sleep(int duration_ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}
