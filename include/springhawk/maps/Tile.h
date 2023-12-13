#ifndef CPROG_PROJECT_TILE_H
#define CPROG_PROJECT_TILE_H

#include "SDL2/SDL.h"
#include "components/Gamecomponents/GameObject.h"

class Tile : public GameObject{
public:
    Tile();
    explicit Tile(SDL_Texture &texture);


    void setTexture(SDL_Texture &texture);

    char getId() const;
    void setId(char id);

private:
    char id;
};


#endif //CPROG_PROJECT_TILE_H
