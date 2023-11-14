//
// Created by felix on 2023-11-11.
//

#include <cmath>
#include "scripts/Player.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"
#include "iostream"



Player::Player() {
    color = {0,0xcf,0x50,0xff};
    position = {100,-100}; //Quick fix. Game object should not need to tell the engine to spawn in negative space
}

void Player::update(){

    input();
}

void Player::input() {
    if(Input::bufferContains(A)){
        //position -= Vector2{static_cast<float>(velocity*sin(angle)),static_cast<float>(velocity* cos(angle))} * Time::getDeltaTime();
        position +=Vector2{static_cast<float>(velocity* cos(angle + M_PI/2)),static_cast<float>(velocity*sin(angle + M_PI/2))} * Time::getDeltaTime();
        //std::cout << "A" << std::endl;
    }

    if(Input::bufferContains(D)){
        position -= Vector2{static_cast<float>(velocity* cos(angle + M_PI/2)),static_cast<float>(velocity*sin(angle + M_PI/2))} * Time::getDeltaTime();
        //position += Vector2{static_cast<float>(velocity*sin(angle)),static_cast<float>(velocity* cos(angle))} * Time::getDeltaTime();
        //std::cout << "D" << std::endl;
    }

    if(Input::bufferContains(S)){
        position -=Vector2{static_cast<float>(velocity* cos(angle)),static_cast<float>(velocity*sin(angle))} * Time::getDeltaTime();
        //std::cout << "S" << std::endl;
    }

    if(Input::bufferContains(W)){
        position += Vector2{static_cast<float>(velocity* cos(angle)),static_cast<float>(velocity*sin(angle))} * Time::getDeltaTime();
        //std::cout << "W" << std::endl;
    }

    if(Input::bufferContains(E)){
        angle -= 1 * Time::getDeltaTime();
    }

    if(Input::bufferContains(Q)){
        angle += 1 * Time::getDeltaTime();
    }

    if(Input::bufferContains(NUM_PLUS)){
        lineCount++;
    }

    if(Input::bufferContains(NUM_MINUS)){
        if(--lineCount < 5){
            lineCount = 5;
        }
    }
}

Color Player::getColor() {
    return color;
}

int Player::getLineCount() {
    return lineCount;
}

