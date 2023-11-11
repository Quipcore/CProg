//
// Created by felix on 2023-11-11.
//

#include "scripts/Player.h"
#include "springhawk/Input.h"
#include "iostream"



Player::Player() {
    color = {0,0xcf,0x50,0xff};
}

void Player::update(){
    input();
}

void Player::input() {
    Key::Keycodes input = Input::getKeyCode();
    if(input == Key::A){
        position.x -= velocity;
        std::cout << "A" << std::endl;
    }
    else if(input == Key::D){
        position.x += velocity;
        std::cout << "D" << std::endl;
    }
    else if(input == Key::S){
        position.y -= velocity;
        std::cout << "S" << std::endl;
    }
    else if(input == Key::W){
        position.y += velocity;
        std::cout << "W" << std::endl;
    }
}

Color Player::getColor() {
    return color;
}

