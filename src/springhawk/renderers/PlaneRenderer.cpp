#include "springhawk/renderers/PlaneRenderer.h"
#include "SDL2/SDL.h"
#include "springhawk/renderers/UIRenderer.h"

void PlaneRenderer::render(SDL_Renderer &renderer, std::vector<GameObject *> &gameObjects, Map &map, int screenWidth, int screenHeight) {

    int rectW = 20;
    int rectH = 20;
    int drawingOffset = (screenWidth-map.getWidth())/2;

    drawMap(map, drawingOffset, renderer, rectW, rectH);
    drawGameObjects(renderer,gameObjects,rectW,rectH,drawingOffset);
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

void PlaneRenderer::drawGameObjects(SDL_Renderer &renderer, std::vector<GameObject *> &vector, int w, int h, int offset) {
    for(GameObject* gameObject : vector){
        SDL_Texture* playerTexture = gameObject->getTexture();
        Vector2 playerPosition = gameObject->getPosition();
        SDL_Rect playerRect = {(int)playerPosition.getX() + offset, (int)playerPosition.getY(), w, h};
        SDL_RenderCopy(&renderer, playerTexture, nullptr, &playerRect);
    }
}
