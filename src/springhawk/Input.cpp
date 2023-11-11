//
// Created by felix on 2023-11-11.
//

#include "springhawk/Input.h"

Key::Keycodes Input::key = Key::null;
std::map<SDL_KeyCode, Key::Keycodes> Input::keyMap = {
        {SDLK_a, Key::A},
        {SDLK_d, Key::D},
        {SDLK_s, Key::S},
        {SDLK_w, Key::W}
};

void Input::setKeyCode(int keyCode){
    key = keyMap[SDL_KeyCode(keyCode)];
}

Key::Keycodes Input::getKeyCode(){
    return key;
}