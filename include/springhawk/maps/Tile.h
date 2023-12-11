//
// Created by felix on 2023-12-07.
//

#ifndef CPROG_PROJECT_TILE_H
#define CPROG_PROJECT_TILE_H

#include "SDL2/SDL.h"

class Tile {
public:
    Tile();
    explicit Tile(SDL_Texture &texture);

    SDL_Texture* getTexture();

    void setTexture(SDL_Texture &texture);

    char getId() const;
    void setId(char id);

private:
    SDL_Texture* texture{};
    char id;
};


#endif //CPROG_PROJECT_TILE_H
