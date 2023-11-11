//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_INPUT_H
#define CPROG_PROJECT_INPUT_H

#include "SDL2/SDL.h"
#include "map"
#include "Key.h"

class Input{
public:
    static void setKeyCode(int keyCode);
    static Key::Keycodes getKeyCode();
private:
    static Key::Keycodes key;
    static std::map<SDL_KeyCode , Key::Keycodes> keyMap;
};

#endif //CPROG_PROJECT_INPUT_H
