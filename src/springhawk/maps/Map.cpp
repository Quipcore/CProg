//
// Created by felix on 2023-11-16.
//

#include "springhawk/maps/Map.h"

int Map::getWidth() {
    return width;
}

int Map::getHeight() {
    return height;
}

int Map::operator[](Vector2 vector2) {
    return 0;
}

Map::Map() {
    width = 8;
    height = 8;
}

Map::~Map() = default;
