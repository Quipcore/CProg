#include "springhawk/Engine.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"
#include "springhawk/Renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include "Constants.h" //gResPath-contains the path to your resources.
#include "chrono"
#include "thread"


//Screen dimension constants
const int Springhawk::Engine::SCREEN_WIDTH = 1500;
const int Springhawk::Engine::SCREEN_HEIGHT = 680;


int Springhawk::Engine::run(std::vector<Scene *> scenes) {

    if(init()){
        throw std::runtime_error("Failed to initialize!");
    }

    SDL_Window* window = SDL_CreateWindow("Window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    playScene(scenes[0],renderer);
    quit(window, renderer);


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


void Springhawk::Engine::playScene(Scene *scene, SDL_Renderer *renderer) {
    std::vector<GameObject*> gameObjects = scene->getGameObjects();
    Player* player = scene->getPlayer();
    std::vector<std::vector<int>> map = scene->getMap();
    keepOpen(renderer, gameObjects, player, map);
}

void Springhawk::Engine::keepOpen(SDL_Renderer *pRenderer, std::vector<GameObject *> gameObjects, Player *pPlayer,
                                  std::vector<std::vector<int>> map) {
    Uint64 startTime = SDL_GetTicks();

    Vector2 lastValidPlayerPosition = pPlayer->getPosition(); //Assuming the player spawns i valid space
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
            if(isOutOfBounds(gameObject->getPosition(), map)){

            }
        }
        pPlayer->update();
        if(isOutOfBounds(pPlayer->getPosition(), map)){
            pPlayer->setPosition(lastValidPlayerPosition);
        }
        lastValidPlayerPosition = pPlayer->getPosition();

        draw(pRenderer, gameObjects, pPlayer, map);

        float deltaTime = (SDL_GetTicks64() - startTime) / 1000.0f;

        //Needs to be looked at, dont know if this is the best way to do it. Should probably not use inheritance.
        //Works for now.
        Time::setDeltaTime(deltaTime);

        startTime = SDL_GetTicks();
    }

}

void Springhawk::Engine::handleEvent(SDL_Event *event){
    switch (event->type) {
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            break;
    }
}

void Springhawk::Engine::sleep(int duration_ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}

void Springhawk::Engine::quit(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}

void Springhawk::Engine::draw(SDL_Renderer *pRenderer, std::vector<GameObject *> gameObjects, Player *pPlayer,
                              std::vector<std::vector<int>> map) {
    Color backgroundColor = {120,104,103,255};
    SDL_SetRenderDrawColor( pRenderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a );
    SDL_RenderClear( pRenderer );
    Springhawk::Renderer::render(pRenderer, gameObjects,pPlayer, map, SCREEN_WIDTH,SCREEN_HEIGHT);
    SDL_RenderPresent(pRenderer);
}

bool Springhawk::Engine::isOutOfBounds(Vector2 objectPosition, std::vector<std::vector<int>> map) {

    if(objectPosition.getX() < 0 || objectPosition.getX() > SCREEN_WIDTH){
        return true;
    }
    if(objectPosition.getY() > 0 || objectPosition.getY() < -SCREEN_HEIGHT){
        return true;
    }

    int mapWidth = map.size();
    int mapHeight = map[0].size();
    int currentXCell = static_cast<int>(objectPosition.getX() * mapWidth / SCREEN_WIDTH);
    int currentYCell = static_cast<int>(objectPosition.getY() * mapHeight / SCREEN_HEIGHT);
    return map[-currentYCell][currentXCell] != 0;
}


