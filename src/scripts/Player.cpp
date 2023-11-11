//
// Created by felix on 2023-11-11.
//

#include "scripts/Player.h"
#include "engine/Input.h"
#include "iostream"


void Player::update(){
    std::cout << "Player: "<< Input::getKeyCode() << std::endl;
}
