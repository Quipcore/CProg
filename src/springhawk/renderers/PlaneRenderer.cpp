#include <iostream>
#include <map>
#include "springhawk/renderers/PlaneRenderer.h"
#include "SDL2/SDL.h"
#include "springhawk/Time.h"
#include "springhawk/renderers/ui/UIRenderer.h"

void PlaneRenderer::render(SDL_Renderer &renderer, std::vector<GameObject *> &gameObjects, Player &player, Map &map, int screenWidth, int screenHeight) {

    clearLastFrame(renderer);

    int rectW = 20;
    int rectH = 20;
    int drawingOffset = (screenWidth-map.getWidth()*rectW)/2;

    drawMap(map, drawingOffset, renderer, rectW, rectH);
    drawPlayer(renderer, player, rectW, rectH, drawingOffset);
    drawDebugText(renderer);

    SDL_RenderPresent(&renderer);
}

void PlaneRenderer::drawPlayer(SDL_Renderer &renderer, Player &player, int rectW, int rectH, int drawingOffset) {
    SDL_Texture* playerTexture = player.getTexture();
    Vector2 playerPosition = player.getPosition();
    SDL_Rect playerRect = {(int)playerPosition.getX() + drawingOffset, (int)playerPosition.getY(), rectW, rectH};
    SDL_RenderCopy(&renderer, playerTexture, nullptr, &playerRect);
}

void PlaneRenderer::drawMap(Map &map, int drawingOffset, SDL_Renderer &renderer, int &rectW, int &rectH) {
    for(int y = 0; y < map.getHeight(); y++){
        for(int x = 0; x < map.getWidth(); x++){
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
