#include "springhawk/TextureManager.h"

TextureManager::TextureManager(std::initializer_list<std::string> paths) {
    for (auto &path : paths) {
        if(textures.find(path) == textures.end()){
            this->textures[path] = nullptr;
        }
    }
}
