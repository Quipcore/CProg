//
// Created by felix on 2023-11-11.
//

#include "engine/Input.h"

Key Input::key = null;
std::map<SDL_KeyCode, Key> Input::keyMap = {
        {SDLK_w, Key::W}
};

void Input::setKeyCode(int keyCode){
    key = keyMap[SDL_KeyCode(keyCode)];
}

Key Input::getKeyCode(){
    return key;
}