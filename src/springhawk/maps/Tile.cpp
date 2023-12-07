#include "springhawk/maps/Tile.h"


Tile::Tile() = default;

Tile::Tile(SDL_Texture &texture) {
    this->texture = &texture;
}

SDL_Texture *Tile::getTexture() {
    return texture;
}

void Tile::setTexture(SDL_Texture &texture){
    this->texture = &texture;
}

