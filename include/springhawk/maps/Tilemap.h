//
// Created by felix on 2023-11-16.
//

#ifndef CPROG_PROJECT_TILEMAP_H
#define CPROG_PROJECT_TILEMAP_H

#include <vector>
#include <map>
#include "Map.h"
#include "scripts/Wall.h"
#include "Tile.h"
#include "springhawk/TextureTag.h"

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
        SDL_Texture *getTextureAt(Vector2 position) override;
//        void loadTextures(std::vector<SDL_Texture*>&) override;
        void loadTextures(std::map<TextureTag, SDL_Texture *> &) override;
    private:
        Wall createWall(std::string &fileLine);

        void loadMap(std::string &mapName);


        //For now avoid walls!
        std::vector<Wall *> *walls;

        std::vector<std::vector<int>> *mapVector;

        int width;
        int height;


        std::vector<std::vector<Tile*>> *tiles;
        std::vector<SDL_Texture*> *textures;


    };
}

#endif //CPROG_PROJECT_TILEMAP_H
