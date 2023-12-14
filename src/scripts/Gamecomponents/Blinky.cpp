//
// Created by felix on 2023-12-14.
//

#include "components/gamecomponents/Blinky.h"

Blinky::Blinky() {
    this->color = {0,0xcf,0x50,0xff};
    this->position = {280,280};
    this->oldPosition = this->position;
    this->map = nullptr;
    this->tag = "Blinky";
    this->texturePath = "blinky.png";
}

Blinky::Blinky(Map *map) : Blinky(){
    this->map = map;
}
