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
#include "Constants.h"

using namespace springhawk;


//----------------------------------------------------------------------------------------------------------------------

std::vector<GameObject *> Engine::gameObjects = {};
std::vector<UIComponent *> Engine::uiComponents = {};
const std::vector<Scene *> *Engine::scenes = {};
SDL_Window *Engine::window = nullptr;
SDL_Renderer *Engine::renderer = nullptr;
Map* Engine::map = nullptr;
bool Engine::beenInitialized = false;

void (*Engine::render)(SDL_Renderer &, std::vector<GameObject *> &, Map &, int, int) = nullptr;

//----------------------------------------------------------------------------------------------------------------------

int Engine::initilize() {
    if (beenInitialized) {
        return EXIT_SUCCESS;
    }

    if (init()) {
        throw std::runtime_error("Failed to initialize!");
    }

    window = SDL_CreateWindow("Springhawk", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    return EXIT_SUCCESS;
}


int Engine::run(std::vector<Scene *>& incomingScenes) {
    initilize();

    scenes = &incomingScenes;

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

    for(GameObject* gameObject : scene->getGameObjects()){
        gameObjects.push_back(gameObject);
    }

    for(UIComponent* uiComponent : scene->getUIComponents()){
        uiComponents.push_back(uiComponent);
    }

    map = &scene->getMap();

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
    beenInitialized = true;
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

        updateObjects();

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
    gameObjects.push_back(gameObject);
}

void Engine::instantiate(UIComponent *uiComponent) {

    if(uiComponent->getFont() == nullptr){
        std::string pathToFont = constants::fontPath + "ComicSans/comic.ttf";
        TTF_Font *font = TTF_OpenFont(pathToFont.c_str(), 20);
        if(font == nullptr){
            std::cout << "Failed to load font: " << uiComponent->getFontName() << std::endl;
            std::cout << "Error: " << TTF_GetError() << std::endl;
            return;
        }
        uiComponent->setFont(font);
    }
    uiComponents.push_back(uiComponent);
}

void Engine::swapTexture(GameObject *gameObject, std::string path) {
    gameObject->setTexture(*renderer, path);
}

void Engine::updateObjects() {
    for (GameObject *gameObject : gameObjects) {
        gameObject->updateObject();

        GameObject* collisionObject = map->getObjectAt(gameObject->getPosition());
        if(collisionObject != nullptr && gameObject->getTag() != "Wall"){
            gameObject->onCollision(*collisionObject);
        }

        if(map->collidesWithWall(gameObject)){
            gameObject->resetPosition();
        }

        for(const auto &other : gameObjects){
            if(gameObject != other && gameObject->intersects(*other)){
                if(!other->isTrigger() && !gameObject->isTrigger()){
                    gameObject->resetPosition();
                }
                gameObject->onCollision(*other);
            }
        }
    }




}
