//
// Created by felix on 2023-11-11.
//

#include "scripts/GameObject.h"
#include "iostream"

void GameObject::update() {

}

Color GameObject::getColor() {
    return color;
}

Vector2& GameObject::getPosition(){
    return position;
}

double GameObject::getAngle() const{
    return angle;
}

void GameObject::setPosition(Vector2 &position) {
    this->position = position;
}

