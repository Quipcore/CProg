#include <iostream>
#include "components/gamecomponents/PacmanController.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"

PacmanController::PacmanController() {
    color = {0,0xcf,0x50,0xff};
    this->position = {280,280};
    this->oldPosition = this->position;
    this->map = nullptr;
}

PacmanController::PacmanController(Map* map) : PacmanController(){
    this->map = map;
}

void PacmanController::update() {
    if(Input::bufferContains(A)){
        position += Vector2::left * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(D)){
        position += Vector2::right * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(S)){
        position -= Vector2::down * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(W)){
        position -= Vector2::up * velocity * Time::getDeltaTime();
    }
}

void PacmanController::onCollision(GameObject &other) {
    if(other.getTag() == "Pellet"){
        map->setValueAt(other.getPosition(), '_');
    }
}




