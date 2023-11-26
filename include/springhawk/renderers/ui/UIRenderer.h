//
// Created by felix on 2023-11-26.
//

#ifndef CPROG_PROJECT_UIRENDERER_H
#define CPROG_PROJECT_UIRENDERER_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include "springhawk/Color.h"
#include "springhawk/Vector2.h"
#include "SDL2/SDL.h"

class UIRenderer {
public:
    static void drawText(const std::string& text, const Vector2& position, TTF_Font* font, Color color, SDL_Renderer *renderer);
    static void drawText(const std::string& text, const Vector2& position, const std::string& fontName, int fontSize, Color color, SDL_Renderer *renderer);
};

#endif //CPROG_PROJECT_UIRENDERER_H
