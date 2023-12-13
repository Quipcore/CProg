#include <iostream>
#include "scripts/PacmanController.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"
#include "springhawk/Collider.h"

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

    Vector2 temp = Vector2{this->position.getX()+15, this->position.getY()+15};
    if(map->getValueAt(temp) == '.'){
        map->setValueAt(temp, '_');
    }


}

void OnCollisionEnter(GameObject& other) {
    std::cout << "Collision" << std::endl;
}




