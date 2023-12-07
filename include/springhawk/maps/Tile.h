//
// Created by felix on 2023-12-07.
//

#ifndef CPROG_PROJECT_TILE_H
#define CPROG_PROJECT_TILE_H

#include "SDL2/SDL.h"

class Tile {

    Tile(SDL_Texture &texture);

public:
    Tile();

    SDL_Texture* getTexture();

    void setTexture(SDL_Texture &texture);

private:
    SDL_Texture* texture{};


};


#endif //CPROG_PROJECT_TILE_H
