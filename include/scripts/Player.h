//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_PLAYER_H
#define CPROG_PROJECT_PLAYER_H
#include "GameObject.h"
#include "springhawk/Key.h"
#include "springhawk/Color.h"

class Player : public GameObject{
public:
    Player();
    void update() override;
    Color getColor() override;
private:
    void input();
    const int velocity = 10;
};


#endif //CPROG_PROJECT_PLAYER_H
