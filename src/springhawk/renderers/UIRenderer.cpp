#include <iostream>
#include "springhawk/renderers/UIRenderer.h"
#include "Constants.h"
#include "springhawk/Time.h"

void UIRenderer::render(SDL_Renderer &renderer, std::vector<UIComponent *> &uiComponents, int width, int height) {
    drawDebugText(renderer);

//    std::string text = "Hello World!";
//    drawText(text,
//             {0, 0},
//             "ComicSans/comic.ttf",
//             20,
//             {255, 255, 0, 255},
//             &renderer
//    );

}

//----------------------------------------------------------------------------------------------------------------------

void UIRenderer::drawText(const std::string& text, const Vector2& position, TTF_Font* font, Color color, SDL_Renderer *renderer) {
    //Modified from https://stackoverflow.com/a/22889483

    SDL_Color sdl_color = {255,255,0,255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), sdl_color);

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect = {0,0,500,100}; //create a rect
    SDL_RenderCopy(renderer, Message, nullptr, &Message_rect);

    // Don't forget to free your surface and texture
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

//----------------------------------------------------------------------------------------------------------------------

void UIRenderer::drawText(const std::string& text, const Vector2& position, const std::string& fontName, int fontSize, Color color, SDL_Renderer *renderer) {
    std::string pathToFont = constants::fontPath + fontName;

    TTF_Font *font = TTF_OpenFont(pathToFont.c_str(), fontSize);
    if(font == nullptr){
        std::cout << "Failed to load font: " << fontName << std::endl;
        std::cout << "Error: " << TTF_GetError() << std::endl;
        return;
    }
    drawText(text, position, font, color, renderer);
    TTF_CloseFont(font);
}

void UIRenderer::drawDebugText(SDL_Renderer &renderer) {
    std::string text = "FPS: " + std::to_string((int) (1 / Time::getDeltaTime()));
    drawText(text,
             {0, 0},
             "ComicSans/comic.ttf",
             20,
             {255, 255, 0, 255},
             &renderer
    );
}
