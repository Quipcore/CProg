#include "springhawk/Engine.h"
#include "springhawk/Time.h"
#include "springhawk/Input.h"
#include "springhawk/renderers/Raycaster.h"
#include "springhawk/renderers/PlaneRenderer.h"
#include "springhawk/renderers/ui/UIRenderer.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include "Constants.h" //gResPath-contains the path to your resources.
#include "chrono"
#include "thread"

using namespace springhawk;


//Screen dimension constants
const int Engine::SCREEN_WIDTH = 1500;
const int Engine::SCREEN_HEIGHT = 680;

//----------------------------------------------------------------------------------------------------------------------

void (*Engine::render)(SDL_Renderer &, std::vector<GameObject *> &, Player &, Map &, int, int) = nullptr;

//----------------------------------------------------------------------------------------------------------------------

int Engine::run(std::vector<Scene *> &scenes) {

    if (init()) {
        throw std::runtime_error("Failed to initialize!");
    }

    SDL_Window *window = SDL_CreateWindow("Springhawk", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    Scene *startScene = scenes.at(0);
    startScene->loadTextures(*renderer);
    playScene(*startScene, *renderer);
    quit(window, renderer);
    return EXIT_SUCCESS;
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

void Engine::quit(SDL_Window &window, SDL_Renderer &renderer, std::vector<SDL_Texture *> &textures) {
    for (SDL_Texture *texture: textures) {
        SDL_DestroyTexture(texture);
    }

    quit(&window, &renderer);
}

//----------------------------------------------------------------------------------------------------------------------

void Engine::quit(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}

//----------------------------------------------------------------------------------------------------------------------

void Engine::playScene(Scene &scene, SDL_Renderer &sdlRenderer) {
    std::vector<GameObject *> gameObjects = scene.getGameObjects();
    Player player = scene.getPlayer();
    Map& map = scene.getMap();

    RenderTag renderTag = scene.getRenderTag();
    bool tagFound = true;
    switch (renderTag) {
        case Plane:
            Engine::render = PlaneRenderer::render;
            break;
        case Raycaster:
            Engine::render = Raycaster::render;
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
        keepOpen(sdlRenderer, gameObjects, player,map);
    }

}

//----------------------------------------------------------------------------------------------------------------------

//TODO Player should be renamed to Camera!
void Engine::keepOpen(SDL_Renderer &renderer, std::vector<GameObject *> &gameObjects, Player &camera, Map &map) {
    Uint64 startTime = SDL_GetTicks();

    if (isOutOfBounds(camera.getPosition(), map)) {
        Vector2 spaceMid = Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        camera.setPosition(spaceMid);
    }
    Vector2 lastValidCameraPosition = camera.getPosition(); //Assuming the player spawns i valid space

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
            gameObject->update();
            if (isOutOfBounds(gameObject->getPosition(), map)) {

            }
        }

        camera.update();
        if (isOutOfBounds(camera.getPosition(), map)) {
            camera.setPosition(lastValidCameraPosition);
        }
        lastValidCameraPosition = camera.getPosition();

        Engine::render(renderer, gameObjects, camera, map, SCREEN_WIDTH, SCREEN_HEIGHT);

        float deltaTime = (SDL_GetTicks64() - startTime) / 1000.0f;
        //Needs to be looked at, dont know if this is the best way to do it. Should probably not use inheritance.
        //Works for now.
        Time::setDeltaTime(deltaTime);
        startTime = SDL_GetTicks();
    }
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

void Engine::draw(SDL_Renderer &renderer, std::vector<GameObject *> &gameObjects, Player &camera, Map &map) {


    //Draw scene

}

//----------------------------------------------------------------------------------------------------------------------

bool Engine::isOutOfBounds(Vector2 &objectPosition, Map &map) {
    if (objectPosition.getX() < 0 || objectPosition.getX() > SCREEN_WIDTH) {
        return true;
    }
    if (objectPosition.getY() < 0 || objectPosition.getY() > SCREEN_HEIGHT) {
        return true;
    }

    int mapWidth = map.getWidth();
    int mapHeight = map.getHeight();
    int currentXCell = static_cast<int>(objectPosition.getX() * mapWidth / SCREEN_WIDTH);
    int currentYCell = static_cast<int>(objectPosition.getY() * mapHeight / SCREEN_HEIGHT);
    Vector2 objectMapPos = {currentXCell, currentYCell};
    return map.isOutOfBounds(objectMapPos);
}


