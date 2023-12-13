#include <cmath>
#include "springhawk/maps/Map.h"
#include "scripts/Player.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"
#include "iostream"


//----------------------------------------------------------------------------------------------------------------------

Player::Player() {
    color = {0,0xcf,0x50,0xff};
    this->position = {280,280};
    this->oldPosition = this->position;
    this->map = nullptr;

}

Player::Player(Map* incomingMap) : Player() {
    this->map = incomingMap;
}

//----------------------------------------------------------------------------------------------------------------------

Player::Player(const Player &player)  : GameObject(player) {
    this->lineCount = player.lineCount;
    this->angle = player.angle;
    this->position = player.position;
    this->oldPosition = player.oldPosition;
    this->color = player.color;
    this->velocity = player.velocity;
    this->map = player.map;
}

//----------------------------------------------------------------------------------------------------------------------

void Player::update(){
    input();
}

//----------------------------------------------------------------------------------------------------------------------

void Player::input() {
    if(Input::bufferContains(A)){
//        position +=Vector2{cos(angle + M_PI/2),sin(angle + M_PI/2)} * velocity  * Time::getDeltaTime();
        position += Vector2::left * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(D)){
        position += Vector2::right * velocity * Time::getDeltaTime();
//        position -= Vector2{cos(angle + M_PI/2),sin(angle + M_PI/2)} * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(S)){
        position -= Vector2::down * velocity * Time::getDeltaTime();
//        position -=Vector2{cos(angle),sin(angle)} * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(W)){
        position -= Vector2::up * velocity * Time::getDeltaTime();
//        position += Vector2{cos(angle),sin(angle)} * velocity * Time::getDeltaTime();
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
        if(map != nullptr){
            map->setValueAt({0,0},'=');
        }
    }

    if(Input::bufferContains(ENTER)){
        std::cout << position << std::endl;
    }

    if(Input::bufferContains(NUM_MINUS)){
        if(--lineCount < 5){
            lineCount = 5;
        }
    }
}

int Player::getLineCount() const {
    return lineCount;
}