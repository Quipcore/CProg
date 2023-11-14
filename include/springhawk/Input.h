//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_INPUT_H
#define CPROG_PROJECT_INPUT_H

#include <map>
#include <vector>

#include "SDL2/SDL.h"


enum Keycode{
    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
    SPACE,ENTER,ESCAPE,
    NUM_PLUS,NUM_MINUS
};

class Input{
public:
    static bool bufferContains(Keycode);

private:
    static std::map<Keycode, SDL_Scancode> keyMap;
    static const Uint8* currentKeyState;
};

#endif //CPROG_PROJECT_INPUT_H
