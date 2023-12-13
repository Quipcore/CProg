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
#include "scripts/GameObject.h"
#include "nlohmann/json.hpp"

namespace springhawk {
    class Tilemap : public Map {
    public:
        explicit Tilemap(nlohmann::json_abi_v3_11_2::basic_json<> &mapdata);

        //TODO: Implement freeing of textures
        Tilemap() = delete;
        ~Tilemap() override = default;

        bool isOutOfBounds(Vector2 &position) override;
        Vector2 getValidPos() override;

        int operator[](Vector2 vector2) override;
        int getWidth() override;
        int getHeight() override;

        SDL_Texture *getTextureAt(Vector2 position) override;
        void loadTextures(SDL_Renderer&) override;
        void setValueAt(Vector2, char) override;
        char getValueAt(Vector2 pos) override;
        bool isEmptyAt(Vector2 &postion) override;
        GameObject* getObjectAt(Vector2 &vector2) override;

    private:

        int width;
        int height;
        int tileWidth;
        int tileHeight;

        std::vector<std::vector<Tile*>> tiles;
        std::map<char, std::pair<std::string,SDL_Texture*>> texturesMap;
        std::vector<std::string> map;

        void generateTiles();


        void setTagAt(Vector2 pos, char id);

        Tile *getTileAt(Vector2 &vector2);
    };
}

#endif //CPROG_PROJECT_TILEMAP_H
