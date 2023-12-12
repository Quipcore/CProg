#include <fstream>
#include <iostream>
#include <utility>
#include <map>
#include "algorithm"
#include "random"

#include <SDL2/SDL_image.h>

#include "springhawk/maps/Tilemap.h"
#include "Constants.h"
#include "nlohmann/json.hpp"

#define EPSILON 0.0001

//----------------------------------------------------------------------------------------------------------------------
springhawk::Tilemap::Tilemap(nlohmann::json &mapdata) {
    std::vector<std::string> jsonMapData = mapdata["data"];
    this->map = jsonMapData;

    nlohmann::json properties = mapdata["properties"];
    tileWidth = properties["tileWidth"];
    tileHeight = properties["tileHeight"];

    this->height = tileHeight * jsonMapData.size();
    this->width = tileWidth * jsonMapData[0].length();
    generateTiles();


    nlohmann::json textureKey = mapdata["textureKey"];
    for (const auto& entry : textureKey.items()) {
        this->texturesMap.insert({entry.key().at(0),{entry.value(), nullptr}});
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
    return tiles.at(position.getY()).at(position.getX())->getTexture();
}

//----------------------------------------------------------------------------------------------------------------------

void springhawk::Tilemap::loadTextures(SDL_Renderer& renderer) {
    //TODO: Create Textures with renderer and texturePaths
    std::string path = constants::imagePath;

    for(const auto& [key, pair] : texturesMap){
        SDL_Surface *surface = IMG_Load((path + pair.first).c_str());
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(&renderer, surface);
        SDL_FreeSurface(surface);
        std::pair<std::string,SDL_Texture*>& value = texturesMap[key];
        value.second = pTexture;
    }

    for(const std::vector<Tile*>& row : tiles){
        for(Tile* tile : row){
            SDL_Texture* c = texturesMap[tile->getId()].second;
            tile->setTexture(*c);
        }
    }
}

void springhawk::Tilemap::generateTiles() {
    tiles = *new std::vector<std::vector<Tile*>>;

    for(int y = 0; y < height/tileHeight; y++){
        std::vector<Tile*> vec;
        for(int x = 0; x < width/tileWidth; x++){
            Tile* tile = new Tile();
            tile->setId(map[y][x]);
            vec.push_back(tile);
        }
        tiles.push_back(vec);
    }
}

void springhawk::Tilemap::setValueAt(Vector2 pos, char value) {
    Tile* tile = tiles.at((int)pos.getY()).at((int)pos.getX());
    tile->setId(value);
    tile->setTexture(*texturesMap[value].second);
}

bool springhawk::Tilemap::isEmptyAt(Vector2 &postion) {

    if (isOutOfBounds(postion)) {
        return false;
    }

    std::vector<Vector2> positionsToCheck = {
        {postion.getX()/tileWidth + 1 - EPSILON, postion.getY()/tileHeight + EPSILON},
        {postion.getX()/tileWidth + 1 - EPSILON, postion.getY()/tileHeight + 1 - EPSILON},
        {postion.getX()/tileWidth + EPSILON, postion.getY()/tileHeight + 1 - EPSILON},
        {postion.getX()/tileWidth + EPSILON, postion.getY()/tileHeight + EPSILON}
    };


    std::string emptyId = "._-+"; //Temporarly taken from pacman.json
    for(auto& pos : positionsToCheck){
        if (isOutOfBounds(pos)) {
            return false;
        }
        char tileId = tiles.at((int) pos.getY()).at((int) pos.getX())->getId();
        if (emptyId.find(tileId) == std::string::npos) {
            return false;
        }
    }
    return true;
}