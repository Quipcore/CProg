#ifndef CPROG_PROJECT_PLAYER_H
#define CPROG_PROJECT_PLAYER_H

#include "GameObject.h"
#include "springhawk/Color.h"
#include "springhawk/maps/Map.h"
#include "springhawk/maps/Tilemap.h"

class Player : public GameObject{
public:
    Player();
    Player(const Player&);
    explicit Player(Map *map);

    void update() override;
    int getLineCount() const;

private:
    double velocity = 100;
    int lineCount = 250;
    Map* map;

    void input();
};

#endif //CPROG_PROJECT_PLAYER_H