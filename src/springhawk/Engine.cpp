#include "springhawk/Engine.h"
#include "springhawk/Time.h"
#include "springhawk/renderers/Raycaster.h"
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
//void (*Engine::render)(SDL_Renderer&, std::vector<GameObject*>&, Player&, std::vector<std::vector<int>>&, int, int) = nullptr;
void (*Engine::render)(SDL_Renderer&, std::vector<GameObject*>&, Player&, Map&, int, int) = nullptr;


int Engine::run(std::vector<Scene *> &scenes) {

    if(init()){
        throw std::runtime_error("Failed to initialize!");
    }

    SDL_Window* window = SDL_CreateWindow("Window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Scene* startScene = scenes.at(0);

    playScene(*startScene, *renderer);
    quit(window, renderer);
    return EXIT_SUCCESS;
}

bool Engine::init() {
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

void Engine::quit(SDL_Window &window, SDL_Renderer &renderer,std::vector<SDL_Texture*> &textures) {
    for(SDL_Texture* texture : textures){
        SDL_DestroyTexture(texture);
    }

    quit(&window,&renderer);
}

void Engine::quit(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}



std::vector<SDL_Texture*> Engine::loadTextures(SDL_Renderer& pRenderer) {
    auto textures = new std::vector<SDL_Texture*>;

    SDL_Surface* bg_sur = IMG_Load( (constants::gResPath + "images/bg.jpg").c_str() );
    SDL_Texture* bg_tex = SDL_CreateTextureFromSurface(&pRenderer, bg_sur);
    SDL_FreeSurface(bg_sur);

    textures->push_back(bg_tex);
    return *textures;
}


void Engine::playScene(Scene &scene, SDL_Renderer &sdlRenderer) {
    std::vector<GameObject*> gameObjects = scene.getGameObjects();
    Player player = scene.getPlayer();
    Map* map = scene.getMap();

    if(map->isOutOfBounds(player.getPosition())){
        Vector2 validPos = map->getValidPos();
        player.setPosition(validPos);
    }

    RenderTag renderTag = scene.getRenderTag();
    switch (renderTag) {
        case Plane:
            std::cout << "No plane render available yet" << std::endl;
            break;
        case Raycaster:
            Engine::render = Raycaster::render;
            break;
        case Doom:
            std::cout << "No doom style render available yet" << std::endl;
            break;
        default:
            std::cout << "No render tag found" << std::endl;
            std::exit(-1);
            break;
    }


    keepOpen(sdlRenderer, gameObjects, player, *map);
}

//TODO Player should be renamed to Camera!
void Engine::keepOpen(SDL_Renderer &renderer, std::vector<GameObject*> &gameObjects, Player &camera, Map& map) {
    Uint64 startTime = SDL_GetTicks();

    Vector2 lastValidCameraPosition = camera.getPosition(); //Assuming the player spawns i valid space
    while (true) {

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return;
            }
            handleEvent(e);
        }

        for (const auto &gameObject: gameObjects) {
            gameObject->update();
            if (map.isOutOfBounds(gameObject->getPosition())) {

            }
        }

        camera.update();
        if (map.isOutOfBounds(camera.getPosition())) {
            camera.setPosition(lastValidCameraPosition);
        }
        lastValidCameraPosition = camera.getPosition();

        draw(renderer, gameObjects, camera, map);

        float deltaTime = (SDL_GetTicks64() - startTime) / 1000.0f;
        //Needs to be looked at, dont know if this is the best way to do it. Should probably not use inheritance.
        //Works for now.
        Time::setDeltaTime(deltaTime);
        startTime = SDL_GetTicks();
    }
}

void Engine::handleEvent(SDL_Event &event){
    switch (event.type) {
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            break;
    }
}

void Engine::sleep(int duration_ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}

void Engine::draw(SDL_Renderer &renderer, std::vector<GameObject*> &gameObjects, Player &camera, Map &map){
    Color backgroundColor = {120,104,103,255};
    SDL_SetRenderDrawColor( &renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a );
    SDL_RenderClear( &renderer );
    Engine::render(renderer, gameObjects, camera, map, SCREEN_WIDTH, SCREEN_HEIGHT);

    std::string text = "FPS: " + std::to_string((int)(1/Time::getDeltaTime()));
    UIRenderer::drawText(text, {0,0}, "ComicSans/comic.ttf", 20, {255,255,0,255},&renderer);
    SDL_RenderPresent(&renderer);
}

//bool Engine::isOutOfBounds(Vector2 &objectPosition, std::vector<std::vector<int>> &map) {
//
//    if(objectPosition.getX() < 0 || objectPosition.getX() > SCREEN_WIDTH){
//        return true;
//    }
//    if(objectPosition.getY() > 0 || objectPosition.getY() < -SCREEN_HEIGHT){
//        return true;
//    }
//
//    int mapWidth = map.size();
//    int mapHeight = map[0].size();
//    int currentXCell = static_cast<int>(objectPosition.getX() * mapWidth / SCREEN_WIDTH);
//    int currentYCell = static_cast<int>(objectPosition.getY() * mapHeight / SCREEN_HEIGHT);
//    return map[-currentYCell][currentXCell] != 0;
//}
//
//Vector2 Engine::getValidPos(std::vector<std::vector<int>> map) {
//    //Todo: Change scalar to be based on tileMap size not screenSize. ScreenSize works in 2D game not in 3D
//    int mapWidth = SCREEN_WIDTH;
//    int mapHeight = SCREEN_HEIGHT;
//
//    for (int x = 0; x < mapWidth; x++) {
//        for (int y = 0; y < mapHeight; y++) {
//            Vector2 pos = Vector2(x, -y);
//            if (!isOutOfBounds(pos, map)) {
//                return pos;
//            }
//        }
//    }
//
//    return {0, 0};
//}


