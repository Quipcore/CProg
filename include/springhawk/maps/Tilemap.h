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
#include "nlohmann/json.hpp"

namespace springhawk {
    class Tilemap : public Map {
    public:
        explicit Tilemap(nlohmann::json_abi_v3_11_2::basic_json<> &mapdata);

        //TODO: Implement freeing of textures
        Tilemap() = default;
        ~Tilemap() override = default;

        bool isOutOfBounds(Vector2 &position) override;
        Vector2 getValidPos() override;

        int operator[](Vector2 vector2) override;
        int getWidth() override;
        int getHeight() override;

        SDL_Texture *getTextureAt(Vector2 position) override;
        void loadTextures(SDL_Renderer&) override;
        void setValueAt(Vector2, char) override;

    private:

        int width;
        int height;

        std::vector<std::vector<Tile*>> tiles;
        std::map<char, std::pair<std::string,SDL_Texture*>> texturesMap;
        std::vector<std::string> map;

        void generateTiles();
    };
}

#endif //CPROG_PROJECT_TILEMAP_H
