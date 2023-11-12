//
// Created by felix on 2023-11-11.
//

#include "scripts/Player.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"
#include "iostream"



Player::Player() {
    color = {0,0xcf,0x50,0xff};
}

void Player::update(){

    input();
}

void Player::input() {
    if(Input::bufferContains(A)){
        position -= Vector2{velocity,0} * Time::getDeltaTime();
        std::cout << "A" << std::endl;
    }

    if(Input::bufferContains(D)){
        position += Vector2{velocity,0} * Time::getDeltaTime();
        std::cout << "D" << std::endl;
    }

    if(Input::bufferContains(S)){
        position -= Vector2{0,velocity} * Time::getDeltaTime();
        std::cout << "S" << std::endl;
    }

    if(Input::bufferContains(W)){
        position += Vector2{0,velocity} * Time::getDeltaTime();
        std::cout << "W" << std::endl;
    }
}

Color Player::getColor() {
    return color;
}

Tag Player::getTag() {
    return tag;
}

