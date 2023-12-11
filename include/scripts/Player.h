#ifndef CPROG_PROJECT_PLAYER_H
#define CPROG_PROJECT_PLAYER_H

#include "scripts/GameObject.h"
#include "springhawk/Color.h"
#include "springhawk/maps/Map.h"
#include "springhawk/maps/Tilemap.h"

class Player : public GameObject{
public:
    Player();
    Player(const Player&);

    explicit Player(Map *map);

    void update() override;
    Color getColor() override;

    int getLineCount();

private:
    void input();
    double velocity = 100;
    int lineCount = 250;
    Map* map;
};

#endif //CPROG_PROJECT_PLAYER_H