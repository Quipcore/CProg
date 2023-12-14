#include <iostream>
#include "springhawk/renderers/UIRenderer.h"
#include "Constants.h"
#include "springhawk/Time.h"

void UIRenderer::render(SDL_Renderer &renderer, std::vector<UIComponent *> &uiComponents, int screenWidth, int screenheight) {
    drawDebugText(renderer);

    for(auto &uiComponent : uiComponents){
        drawText(uiComponent->getText(),
                 uiComponent->getPosition(),
                 uiComponent->getFont(),
                 uiComponent->getColor(),
                 &renderer);
    }
}

//----------------------------------------------------------------------------------------------------------------------

void UIRenderer::drawText(const std::string& text, const Vector2& position, TTF_Font* font, Color color, SDL_Renderer *renderer) {
    //Modified from https://stackoverflow.com/a/22889483


    SDL_Color sdl_color = color.toSDLColor();

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), sdl_color);

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect = {static_cast<int>(position.getX()),static_cast<int>(position.getY()),500,100};
    SDL_RenderCopy(renderer, Message, nullptr, &Message_rect);

    // Don't forget to free your surface and texture
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

//----------------------------------------------------------------------------------------------------------------------

void UIRenderer::drawDebugText(SDL_Renderer &renderer) {
    std::string text = "FPS: " + std::to_string((int) (1 / Time::getDeltaTime()));

    std::string pathToFont = constants::fontPath + "ComicSans/comicbd.ttf";

    TTF_Font *font = TTF_OpenFont(pathToFont.c_str(), 20);
    if(font == nullptr){
        std::cout << "Failed to load font: " << "ComicSans/comic.ttf" << std::endl;
        std::cout << "Error: " << TTF_GetError() << std::endl;
        return;
    }
    drawText(text, {0, 0}, font, {255, 255, 0, 255}, &renderer);
    TTF_CloseFont(font);
}
