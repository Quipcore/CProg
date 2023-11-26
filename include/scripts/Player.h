//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_PLAYER_H
#define CPROG_PROJECT_PLAYER_H
#include "scripts/GameObject.h"
#include "springhawk/Color.h"

class Player : public GameObject{
public:
    Player();
    void update() override;
    Color getColor() override;

    int getLineCount();

private:
    void input();
    const double velocity = 100;
    int lineCount = 250;
};


#endif //CPROG_PROJECT_PLAYER_H
