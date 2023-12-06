//
// Created by felix on 2023-11-16.
//

#ifndef CPROG_PROJECT_TILEMAP_H
#define CPROG_PROJECT_TILEMAP_H

#include <vector>
#include "Map.h"
#include "scripts/Wall.h"

namespace springhawk {
    class Tilemap : public Map {
    public:
        explicit Tilemap(std::string mapName);
        explicit Tilemap(std::vector<std::vector<int>> vector1);

        ~Tilemap() override = default;

        bool isOutOfBounds(Vector2 &position) override;
        Vector2 getValidPos() override;
        int operator[](Vector2 vector2) override;
        int getWidth() override;
        int getHeight() override;


    private:
        Wall createWall(std::string &fileLine);

        void loadMap(std::string &mapName);


        //For now avoid walls!
        std::vector<Wall *> *walls;

        std::vector<std::vector<int>> *mapVector;
    };
}

#endif //CPROG_PROJECT_TILEMAP_H
