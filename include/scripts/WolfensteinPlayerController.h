//
// Created by felix on 2023-12-11.
//

#ifndef CPROG_PROJECT_WOLFENSTEINPLAYERCONTROLLER_H
#define CPROG_PROJECT_WOLFENSTEINPLAYERCONTROLLER_H

#include "scripts/Player.h"

class WolfensteinPlayerController : public Player{

    WolfensteinPlayerController() = default;
    WolfensteinPlayerController(const WolfensteinPlayerController&) = default;
    ~WolfensteinPlayerController() = default;


    void update() override;
};


#endif //CPROG_PROJECT_WOLFENSTEINPLAYERCONTROLLER_H
