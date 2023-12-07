#ifndef CPROG_PROJECT_PLAYER_H
#define CPROG_PROJECT_PLAYER_H

#include "scripts/GameObject.h"
#include "springhawk/Color.h"

class Player : public GameObject{
public:
    Player();
    Player(const Player&);
    void update() override;
    Color getColor() override;

    int getLineCount();

private:
    void input();
    double velocity = 100;
    int lineCount = 250;
};

#endif //CPROG_PROJECT_PLAYER_H