//
// Created by felix on 2023-11-11.
//

#include "springhawk/Input.h"
#include <algorithm>


std::vector<Keycode> Input::buffer;
std::map<SDL_KeyCode, Keycode> Input::keyMap = {
        {SDLK_a, A},
        {SDLK_d, D},
        {SDLK_s, S},
        {SDLK_w, W}
};
std::map<Keycode, SDL_Scancode > Input::keyMap2 = {
        {A, SDL_SCANCODE_A},
        {D, SDL_SCANCODE_D},
        {S, SDL_SCANCODE_S},
        {W, SDL_SCANCODE_W}
};


bool Input::bufferContains(Keycode keycode) {

//    return std::any_of(buffer.begin(), buffer.end(), [keycode](Keycode key) {
//        return key == keycode;
//    });
//    for(Keycode key : buffer){
//        if(key == keycode) {
//            return true;
//        }
//    }
//    return false;

    const Uint8* currentKeyState = SDL_GetKeyboardState(nullptr);
    return currentKeyState[keyMap2[keycode]];
}
