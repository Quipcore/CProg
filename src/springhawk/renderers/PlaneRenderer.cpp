#include <iostream>
#include "springhawk/renderers/PlaneRenderer.h"
#include "SDL2/SDL.h"
#include "springhawk/Time.h"
#include "springhawk/renderers/ui/UIRenderer.h"

void PlaneRenderer::render(SDL_Renderer &renderer, std::vector<GameObject *> &gameObjects, Map &map, int screenWidth, int screenHeight) {
    clearLastFrame(renderer);

    //TODO: Change to be dynamic with maps tile size
    int rectW = 20;
    int rectH = 20;
    int drawingOffset = (screenWidth-map.getWidth())/2;

    drawMap(map, drawingOffset, renderer, rectW, rectH);
    drawGameObjects(renderer,gameObjects,rectW,rectH,drawingOffset);
    drawDebugText(renderer);

    SDL_RenderPresent(&renderer);
}

void PlaneRenderer::drawMap(Map &map, int drawingOffset, SDL_Renderer &renderer, int &rectW, int &rectH) {
    for(int y = 0; y < map.getHeight()/rectH; y++){
        for(int x = 0; x < map.getWidth()/rectW; x++){
            SDL_Rect rect = {drawingOffset+x * rectW, y * 20, rectW, rectH};
            SDL_Texture* tileTexture = map.getTextureAt(Vector2{x,y});
            SDL_RenderCopy(&renderer,tileTexture, nullptr, &rect);
        }
    }
}

void PlaneRenderer::drawDebugText(SDL_Renderer &renderer) {
    std::string text = "FPS: " + std::to_string((int) (1 / Time::getDeltaTime()));
    UIRenderer::drawText(text,
                         {0, 0},
                         "ComicSans/comic.ttf",
                         20,
                         {255, 255, 0, 255},
                         &renderer
                         );
}

void PlaneRenderer::clearLastFrame(SDL_Renderer &renderer) {
    Color backgroundColor = {0, 0, 0, 255};
    SDL_SetRenderDrawColor(&renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(&renderer);
}

void PlaneRenderer::drawGameObjects(SDL_Renderer &renderer, std::vector<GameObject *> &vector, int w, int h, int offset) {
    for(GameObject* gameObject : vector){
        SDL_Texture* playerTexture = gameObject->getTexture();
        Vector2 playerPosition = gameObject->getPosition();
        SDL_Rect playerRect = {(int)playerPosition.getX() + offset, (int)playerPosition.getY(), w, h};
        SDL_RenderCopy(&renderer, playerTexture, nullptr, &playerRect);
    }
}
