//
// Created by felix on 2023-11-26.
//

#ifndef CPROG_PROJECT_UIRENDERER_H
#define CPROG_PROJECT_UIRENDERER_H

#include <string>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include "springhawk/Color.h"
#include "springhawk/Vector2.h"
#include "SDL2/SDL.h"
#include "components/uiComponents/UIComponent.h"

class UIRenderer {
public:
    static void render(SDL_Renderer& renderer, std::vector<UIComponent *> &uiComponents, int width, int height);

private:
    static void drawText(const std::string& text, const Vector2& position, TTF_Font* font, Color color, SDL_Renderer *renderer);
    static void drawDebugText(SDL_Renderer &renderer);
};

#endif //CPROG_PROJECT_UIRENDERER_H
