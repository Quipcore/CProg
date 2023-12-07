#include <iostream>
#include <map>
#include "springhawk/renderers/PlaneRenderer.h"
#include "SDL2/SDL.h"

void PlaneRenderer::render(SDL_Renderer &renderer, std::vector<GameObject *> &gameObjects, Player &player, Map &map, int screenWidth, int screenHeight) {

    int rectW = 20;
    int rectH = 20;

    for(int y = 0; y < map.getHeight(); y++){
        for(int x = 0; x < map.getWidth(); x++){
            SDL_Rect rect = {(screenWidth-map.getWidth()*rectW)/2+x * rectW, y * 20, rectW, rectH};
            SDL_Texture* tileTexture = map.getTextureAt(Vector2{x,y});
            SDL_RenderCopy(&renderer,tileTexture, nullptr, &rect);
        }
    }
}
