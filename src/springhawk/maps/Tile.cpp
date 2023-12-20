#include "springhawk/maps/Tile.h"


Tile::Tile() = default;

Tile::Tile(SDL_Texture &texture) {
    GameObject::setTexture(&texture);
}

char Tile::getId() const {
    return id;
}

void Tile::setId(char id){
    this->id = id;
    switch (id) {
        case 'P':
            setTag("PowerPellet");
            break;
        case '.':
            setTag("Pellet");
            break;
        case '#':
            setTag("Wall");
            break;

        case '_':
        case '-':
        default:
            setTag("Empty");
            break;
    }
}

