//
// Created by felix on 2023-11-26.
//


#include <iostream>
#include "springhawk/renderers/ui/UIRenderer.h"
#include "Constants.h"


void UIRenderer::drawText(const std::string& text, const Vector2& position, TTF_Font* font, Color color, SDL_Renderer *renderer) {
    //Modified from https://stackoverflow.com/a/22889483

    // this is the color in rgb format,
    // maxing out all would give you the color white,
    // and it will be your text's color
    SDL_Color sdl_color = { static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b),255 };

    sdl_color = {255,255,0,255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), sdl_color);

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect = {0,0,500,100}; //create a rect
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    // Don't forget to free your surface and texture
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void UIRenderer::drawText(const std::string& text, const Vector2& position, const std::string& fontName, int fontSize, Color color, SDL_Renderer *renderer) {
    std::string pathToFont = constants::gFontPath + fontName;

    TTF_Font *font = TTF_OpenFont(pathToFont.c_str(), fontSize);
    if(font == nullptr){
        std::cout << "Failed to load font: " << fontName << std::endl;
        std::cout << "Error: " << TTF_GetError() << std::endl;
        return;
    }
    drawText(text, position, font, color, renderer);
    TTF_CloseFont(font);
}
