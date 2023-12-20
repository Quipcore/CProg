//
// Created by felix on 2023-12-14.
//

#ifndef CPROG_PROJECT_BLINKY_H
#define CPROG_PROJECT_BLINKY_H


#include "components/gamecomponents/GameObject.h"
#include "springhawk/maps/Map.h"

class Blinky : public GameObject{
public:
    explicit Blinky(Map *map);

    void powerPelletActivated();

private:
    Blinky();

    Map* map;

};


#endif //CPROG_PROJECT_BLINKY_H
