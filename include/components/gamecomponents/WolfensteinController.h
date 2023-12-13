//
// Created by felix on 2023-12-11.
//

#ifndef CPROG_PROJECT_WOLFENSTEINCONTROLLER_H
#define CPROG_PROJECT_WOLFENSTEINCONTROLLER_H

#include "Player.h"

class WolfensteinController : public GameObject{

    WolfensteinController() = default;
    WolfensteinController(const WolfensteinController&) = default;
    ~WolfensteinController() = default;

    void update() override;
};


#endif //CPROG_PROJECT_WOLFENSTEINCONTROLLER_H
