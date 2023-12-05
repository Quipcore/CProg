//
// Created by felix on 2023-11-16.
//

#ifndef CPROG_PROJECT_TILEMAP_H
#define CPROG_PROJECT_TILEMAP_H

#include <vector>
#include "Map.h"
#include "scripts/Wall.h"

class Tilemap : public Map{
public:
    explicit Tilemap(std::string mapName);

    Tilemap(std::vector<std::vector<int>> vector1);

private:
    Wall createWall(std::string& fileLine);
    void loadMap(std::string& mapName);

    std::vector<Wall*>* walls;
};


#endif //CPROG_PROJECT_TILEMAP_H
