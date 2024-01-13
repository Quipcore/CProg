#ifndef CPROG_PROJECT_PACMANCONTROLLER_H
#define CPROG_PROJECT_PACMANCONTROLLER_H


#include "GameObject.h"
#include "springhawk/maps/Map.h"
#include "components/uiComponents/UIComponent.h"
#include "components/uiComponents/ScoreField.h"
#include "Blinky.h"


class PacmanController : public GameObject{
public:
    PacmanController();
    ~PacmanController() override= default;
    PacmanController(const PacmanController&) = default;

    explicit PacmanController(Map* map);

    void update() override;
    void onCollision(GameObject& other) override;
private:
    ScoreField* scoreField;
    double velocity = 100;
    Map* map;
};


#endif //CPROG_PROJECT_PACMANCONTROLLER_H
