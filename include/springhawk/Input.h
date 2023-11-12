//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_INPUT_H
#define CPROG_PROJECT_INPUT_H

#include <map>
#include <vector>

#include "SDL2/SDL.h"


enum Keycode{
    A,
    D,
    S,
    W
};

class Input{
public:
    static bool bufferContains(Keycode);

private:
    static std::map<SDL_KeyCode , Keycode> keyMap;
    static std::vector<Keycode> buffer; //All key pressed down this frame
    static std::map<Keycode, SDL_Scancode> keyMap2;
};

#endif //CPROG_PROJECT_INPUT_H
