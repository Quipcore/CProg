#include <iostream>
#include "components/gamecomponents/PacmanController.h"
#include "springhawk/Input.h"
#include "springhawk/Time.h"
#include "springhawk/Engine.h"
#include "components/gamecomponents/Blinky.h"
#include "components/gamecomponents/TeleportPad.h"

PacmanController::PacmanController() {
    this->color = {0,0xcf,0x50,0xff};
    this->position = {290,480};
    this->oldPosition = this->position;
    this->map = nullptr;
    this->tag = "Pacman";
    this->texturePath = "pac.png";

    this->scoreField = new ScoreField("Score");
    this->scoreField->setSize({100, 50});
    this->scoreField->setPosition({0, 400});
    this->scoreField->setColor({255,0,0,255});
    this->scoreField->setFontName("ComicSans/comic.ttf");
    this->scoreField->setFontSize(20);
    springhawk::Engine::instantiate(scoreField);

    int tileSize = 20;
    auto* leftPad = new TeleportPad(Vector2{28, 15}*tileSize);
    auto* rightPad = new TeleportPad(Vector2{1, 15}*tileSize);

    leftPad->setAnchor(rightPad, Vector2::right*2*tileSize);
    rightPad->setAnchor(leftPad, Vector2::left*2*tileSize);

    springhawk::Engine::instantiate(leftPad);
    springhawk::Engine::instantiate(rightPad);

}

PacmanController::PacmanController(Map* map) : PacmanController(){
    this->map = map;

}

void PacmanController::update() {
    if(Input::bufferContains(A)){
        position += Vector2::left * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(D)){
        position += Vector2::right * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(S)){
        position -= Vector2::down * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(W)){
        position -= Vector2::up * velocity * Time::getDeltaTime();
    }

    if(Input::bufferContains(SPACE)){
        std::cout << position << std::endl;
    }
}

void PacmanController::onCollision(GameObject& other) {
    if(other.getTag() == "Pellet"){
        map->setValueAt(other.getPosition(), '_');
        scoreField->incrementScore();
    }

    if(other.getTag() == "PowerPellet"){
        map->setValueAt(other.getPosition(), '_');
        std::vector<Blinky*> ghosts = springhawk::Engine::getObjects<Blinky>();
        for(Blinky* ghost : ghosts){
            ghost->powerPelletActivated();
        }
    }

    if(other.getTag() == "Blinky"){
        std::cout << "Pacman collided with ghost" << std::endl;
        scoreField->setScore(0);
    }
}






