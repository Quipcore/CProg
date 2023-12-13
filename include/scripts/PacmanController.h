#ifndef CPROG_PROJECT_PACMANCONTROLLER_H
#define CPROG_PROJECT_PACMANCONTROLLER_H


#include "scripts/GameObject.h"
#include "springhawk/maps/Map.h"


class PacmanController : public GameObject{
public:
    PacmanController();
    explicit PacmanController(Map* map);
    ~PacmanController() = default;
    PacmanController(const PacmanController&) = default;

    void update() override;
private:
    double velocity = 100;
    Map* map;
};


#endif //CPROG_PROJECT_PACMANCONTROLLER_H
