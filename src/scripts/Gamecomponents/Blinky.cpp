#include <iostream>
#include "components/gamecomponents/Blinky.h"
#include "springhawk/Engine.h"

Blinky::Blinky() {
    this->color = {0,0xcf,0x50,0xff};
    this->position = {280,280};
    this->oldPosition = this->position;
    this->map = nullptr;
    this->tag = "Blinky";
    this->texturePath = "blinky.png";
    this->objectIsTrigger = true;
}


Blinky::Blinky(Map *map) : Blinky(){
    this->map = map;
}

void Blinky::update() {
    position += Vector2::left * 50 * Time::getDeltaTime();
}

void Blinky::powerPelletActivated() {
    springhawk::Engine::swapTexture(this, "ghost_active.png");
}
