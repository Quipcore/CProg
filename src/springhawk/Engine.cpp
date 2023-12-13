#include "springhawk/Engine.h"
#include "springhawk/Time.h"
#include "springhawk/Input.h"
#include "springhawk/renderers/Raycaster.h"
#include "springhawk/renderers/PlaneRenderer.h"
#include "springhawk/renderers/UIRenderer.h"
#include "components/uiComponents/UIComponent.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include "chrono"
#include "thread"

using namespace springhawk;


//----------------------------------------------------------------------------------------------------------------------

std::vector<GameObject *> Engine::gameObjects = {};
std::vector<UIComponent *> Engine::uiComponents = {};
const std::vector<Scene *> *Engine::scenes = {};
void (*Engine::render)(SDL_Renderer &, std::vector<GameObject *> &, Map &, int, int) = nullptr;

//----------------------------------------------------------------------------------------------------------------------

int Engine::run(std::vector<Scene *>& giveScenes) {
    if (init()) {
        throw std::runtime_error("Failed to initialize!");
    }

    SDL_Window* window = SDL_CreateWindow("Springhawk", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    scenes = &giveScenes;

    startNextScene(*renderer);

    quit(renderer, window);
    return EXIT_SUCCESS;
}

void Engine::quit(SDL_Renderer *renderer, SDL_Window *window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}

//----------------------------------------------------------------------------------------------------------------------

void Engine::startNextScene(SDL_Renderer &renderer){
    Scene *scene = scenes->at(0);

    scene->loadTextures(renderer);

    gameObjects = scene->getGameObjects();
    uiComponents = scene->getUIComponents();
    Map* map = &scene->getMap();

    bool tagFound = true;
    switch (scene->getRenderTag()) {
        case Plane:
            Engine::render = PlaneRenderer::render;
            break;
        case Raycaster:
//            Engine::render = Raycaster::render;
            std::cout << "Raycaster currently out of commission" << std::endl;
            tagFound = false;
            break;
        case Doom:
            std::cout << "No doom style render available yet" << std::endl;
            tagFound = false;
            break;
        default:
            std::cout << "No render tag found" << std::endl;
            tagFound = false;
            break;
    }

    if (tagFound) {
        startGameLoop(renderer, *map);
    }

    scene->destroyTextures();
}

//----------------------------------------------------------------------------------------------------------------------

bool Engine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Error SDL2 Initialization : " << SDL_GetError();
        return EXIT_FAILURE;
    }

    if (TTF_Init() < 0) {
        std::cout << "Error SDL_ttf Initialization : " << SDL_GetError();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------------------------------------------------

void Engine::startGameLoop(SDL_Renderer &renderer, Map &map) {
    Uint64 startTime = SDL_GetTicks();

    bool running = true;
    while (running) {

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return;
            }
            if (Input::bufferContains(ESCAPE)) {
                running = false;
            }
            handleEvent(e);
        }

        for (const auto &gameObject: gameObjects) {
            gameObject->updateObject();

            GameObject* collisionObject = map.getObjectAt(gameObject->getPosition());
            gameObject->onCollision(*collisionObject);
            if(!map.isEmptyAt(gameObject->getPosition())){
                gameObject->resetPosition();
            }
        }

        renderScene(renderer, map);

        float deltaTime = (SDL_GetTicks64() - startTime) / 1000.0f;
        //Needs to be looked at, dont know if this is the best way to do it. Should probably not use inheritance.
        //Works for now.
        Time::setDeltaTime(deltaTime);
        startTime = SDL_GetTicks();
    }
}

void Engine::renderScene(SDL_Renderer &renderer, Map& map) {
    Color backgroundColor = {0, 0, 0, 255};
    SDL_SetRenderDrawColor(&renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(&renderer);

    Engine::render(renderer, gameObjects, map, SCREEN_WIDTH, SCREEN_HEIGHT);
    UIRenderer::render(renderer, uiComponents, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_RenderPresent(&renderer);
}

//----------------------------------------------------------------------------------------------------------------------

void Engine::handleEvent(SDL_Event &event) {
    switch (event.type) {
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            break;
    }
}

//----------------------------------------------------------------------------------------------------------------------

void Engine::sleep(int duration_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}
//----------------------------------------------------------------------------------------------------------------------

void Engine::instantiate(GameObject *gameObject) {

}

void Engine::instantiate(UIComponent *uiComponent) {

}











