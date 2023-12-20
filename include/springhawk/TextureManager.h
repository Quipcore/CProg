//
// Created by felix on 2023-12-20.
//

#ifndef CPROG_PROJECT_TEXTUREMANAGER_H
#define CPROG_PROJECT_TEXTUREMANAGER_H


#include <map>
#include <string>
#include <SDL2/SDL.h>

class TextureManager {
public:
    TextureManager() = default;
    TextureManager(const TextureManager&) = default;
    TextureManager(std::initializer_list<std::string>);
    ~TextureManager() = default;


    void loadTextures(SDL_Renderer &renderer);
private:
    std::map<std::string, SDL_Texture*> textures;
};


#endif //CPROG_PROJECT_TEXTUREMANAGER_H
