#include <fstream>
#include <iostream>
#include <utility>
#include <map>
#include "algorithm"
#include "random"

#include <SDL2/SDL_image.h>

#include "springhawk/maps/Tilemap.h"
#include "Constants.h"
#include "springhawk/TextureTag.h"
#include "nlohmann/json.hpp"

//----------------------------------------------------------------------------------------------------------------------

springhawk::Tilemap::Tilemap(nlohmann::json &mapdata) {
    std::vector<std::string> map = mapdata["data"];
    this->map = map;
    this->height = map.size();
    this->width = map[0].length();

    generateTiles();

    nlohmann::json textureKey = mapdata["textureKey"];
    for (const auto& entry : textureKey.items()) {
        this->texturePaths.insert({entry.key().at(0),entry.value()});
    }
}

//----------------------------------------------------------------------------------------------------------------------

bool springhawk::Tilemap::isOutOfBounds(Vector2 &position) {

    if(position.getX() < 0 || position.getX() > width){
        return true;
    }

    if(position.getY() < 0 || position.getY() > height){
        return true;
    }

    return this->operator[](position) != 0;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 springhawk::Tilemap::getValidPos() {
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            Vector2 pos = {x,y};
            if(!isOutOfBounds(pos)){
                return pos;
            }
        }
    }
    return {0,0};
}

//----------------------------------------------------------------------------------------------------------------------

int springhawk::Tilemap::operator[](Vector2 position) {
    //TODO: Implement!
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------

int springhawk::Tilemap::getWidth() {
    return width;
}

//----------------------------------------------------------------------------------------------------------------------

int springhawk::Tilemap::getHeight() {
    return height;
}

//----------------------------------------------------------------------------------------------------------------------

SDL_Texture* springhawk::Tilemap::getTextureAt(Vector2 position){
    return tiles->at(position.getY()).at(position.getX())->getTexture();
}

//----------------------------------------------------------------------------------------------------------------------

void springhawk::Tilemap::loadTextures(SDL_Renderer& renderer) {
    //TODO: Create Textures with renderer and texturePaths

    std::map<char,SDL_Texture* > textures;
    std::string path = constants::gResPath + "/images/";
    for(const auto& [key,imageName] : texturePaths){
        SDL_Surface *surface = IMG_Load((path + imageName).c_str());
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(&renderer, surface);
        SDL_FreeSurface(surface);
        textures.insert({key, pTexture});
    }


    for(std::vector<Tile*> row : *tiles){
        for(Tile* tile : row){
            SDL_Texture* c = textures[tile->getId()];
            tile->setTexture(*c);
        }
    }

}

void springhawk::Tilemap::generateTiles() {
    tiles = new std::vector<std::vector<Tile*>>;

    for(int y = 0; y < height; y++){
        std::vector<Tile*> vec;
        for(int x = 0; x < width; x++){
            Tile* tile = new Tile();
            tile->setId(map[y][x]);
            vec.push_back(tile);
        }
        tiles->push_back(vec);
    }
}
