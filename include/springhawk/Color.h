#ifndef CPROG_PROJECT_COLOR_H
#define CPROG_PROJECT_COLOR_H

#include <SDL2/SDL.h>

struct Color{
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0xff;
    [[nodiscard]] SDL_Color toSDLColor() const{
        return SDL_Color{static_cast<Uint8>(r),static_cast<Uint8>(g),static_cast<Uint8>(b),static_cast<Uint8>(a)};
    }
};

#endif //CPROG_PROJECT_COLOR_H
