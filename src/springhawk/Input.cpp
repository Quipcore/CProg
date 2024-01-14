#include "springhawk/Input.h"

//----------------------------------------------------------------------------------------------------------------------

//const Uint8* Input::currentKeyState = SDL_GetKeyboardState(nullptr);

//----------------------------------------------------------------------------------------------------------------------

//Mostly likely a better way to do this mapping.
//std::map<Keycode, SDL_Scancode> Input::keyMap = {
//        {A, SDL_SCANCODE_A},
//        {B, SDL_SCANCODE_B},
//        {C, SDL_SCANCODE_C},
//        {D, SDL_SCANCODE_D},
//        {E, SDL_SCANCODE_E},
//        {F, SDL_SCANCODE_F},
//        {G, SDL_SCANCODE_G},
//        {H, SDL_SCANCODE_H},
//        {I, SDL_SCANCODE_I},
//        {J, SDL_SCANCODE_J},
//        {K, SDL_SCANCODE_K},
//        {L, SDL_SCANCODE_L},
//        {M, SDL_SCANCODE_M},
//        {N, SDL_SCANCODE_N},
//        {O, SDL_SCANCODE_O},
//        {P, SDL_SCANCODE_P},
//        {Q, SDL_SCANCODE_Q},
//        {R, SDL_SCANCODE_R},
//        {S, SDL_SCANCODE_S},
//        {T, SDL_SCANCODE_T},
//        {U, SDL_SCANCODE_U},
//        {V, SDL_SCANCODE_V},
//        {W, SDL_SCANCODE_W},
//        {X, SDL_SCANCODE_X},
//        {Y, SDL_SCANCODE_Y},
//        {Z, SDL_SCANCODE_Z},
//        {SPACE, SDL_SCANCODE_SPACE},
//        {ENTER, SDL_SCANCODE_RETURN},
//        {ESCAPE, SDL_SCANCODE_ESCAPE},
//        {TAB, SDL_SCANCODE_TAB},
//        {NUM_PLUS, SDL_SCANCODE_KP_PLUS},
//        {NUM_MINUS, SDL_SCANCODE_KP_MINUS}
//};

//----------------------------------------------------------------------------------------------------------------------

//bool Input::bufferContains(Keycode keycode) {
//    std::map<Keycode, SDL_Scancode> keyMap = {
//            {A, SDL_SCANCODE_A},
//            {B, SDL_SCANCODE_B},
//            {C, SDL_SCANCODE_C},
//            {D, SDL_SCANCODE_D},
//            {E, SDL_SCANCODE_E},
//            {F, SDL_SCANCODE_F},
//            {G, SDL_SCANCODE_G},
//            {H, SDL_SCANCODE_H},
//            {I, SDL_SCANCODE_I},
//            {J, SDL_SCANCODE_J},
//            {K, SDL_SCANCODE_K},
//            {L, SDL_SCANCODE_L},
//            {M, SDL_SCANCODE_M},
//            {N, SDL_SCANCODE_N},
//            {O, SDL_SCANCODE_O},
//            {P, SDL_SCANCODE_P},
//            {Q, SDL_SCANCODE_Q},
//            {R, SDL_SCANCODE_R},
//            {S, SDL_SCANCODE_S},
//            {T, SDL_SCANCODE_T},
//            {U, SDL_SCANCODE_U},
//            {V, SDL_SCANCODE_V},
//            {W, SDL_SCANCODE_W},
//            {X, SDL_SCANCODE_X},
//            {Y, SDL_SCANCODE_Y},
//            {Z, SDL_SCANCODE_Z},
//            {SPACE, SDL_SCANCODE_SPACE},
//            {ENTER, SDL_SCANCODE_RETURN},
//            {ESCAPE, SDL_SCANCODE_ESCAPE},
//            {TAB, SDL_SCANCODE_TAB},
//            {NUM_PLUS, SDL_SCANCODE_KP_PLUS},
//            {NUM_MINUS, SDL_SCANCODE_KP_MINUS}
//    };
//
//    return SDL_GetKeyboardState(nullptr)[keyMap[keycode]];
//}