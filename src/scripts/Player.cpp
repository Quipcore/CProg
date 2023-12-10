#include <cmath>
#include "springhawk/maps/Map.h"
#include "scripts/Player.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"
#include "iostream"


//----------------------------------------------------------------------------------------------------------------------

Player::Player() {
    color = {0,0xcf,0x50,0xff};
    position = {500,500};
}

//TODO: REMOVE THIS!
Player::Player(Map& incomingMap) : Player() {
    this->map = &incomingMap;
}

//----------------------------------------------------------------------------------------------------------------------

Player::Player(const Player &player)  : GameObject(player) {
    this->lineCount = player.lineCount;
    this->angle = player.angle;
    this->position = player.position;
    this->color = player.color;
    this->velocity = player.velocity;
}

//----------------------------------------------------------------------------------------------------------------------

void Player::update(){
    input();
}

//----------------------------------------------------------------------------------------------------------------------

void Player::input() {
    if(Input::bufferContains(A)){
        position +=Vector2{cos(angle + M_PI/2),sin(angle + M_PI/2)} * velocity  * Time::getDeltaTime();
        std::cout << "A" << std::endl;
    }

    if(Input::bufferContains(D)){
        position -= Vector2{cos(angle + M_PI/2),sin(angle + M_PI/2)} * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(S)){
        position -=Vector2{cos(angle),sin(angle)} * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(W)){
        position += Vector2{cos(angle),sin(angle)} * velocity * Time::getDeltaTime();
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

    if(Input::bufferContains(SPACE)){
        if(map == nullptr){
            std::cout << "MAP IS NULL!" << std::endl;
        }else{
            std::cout << "MAP EXISTS!" << std::endl;
            map->setValueAt({0,0},'=');
        }
    }

    if(Input::bufferContains(NUM_MINUS)){
        if(--lineCount < 5){
            lineCount = 5;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

Color Player::getColor() {
    return color;
}

//----------------------------------------------------------------------------------------------------------------------

int Player::getLineCount() {
    return lineCount;
}