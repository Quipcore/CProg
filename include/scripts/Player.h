//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_PLAYER_H
#define CPROG_PROJECT_PLAYER_H
#include "GameObject.h"
#include "springhawk/Color.h"

class Player : public GameObject{
public:
    Player();
    void update() override;
    Color getColor() override;
    Tag getTag() override;

    int getLineCount();

private:
    void input();
    const float velocity = 100;
    const Tag tag = Tag::Player;
    int lineCount = 1;
};


#endif //CPROG_PROJECT_PLAYER_H
