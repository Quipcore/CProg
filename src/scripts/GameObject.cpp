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

Vector2 GameObject::getPosition() const{
    return position;
}

float GameObject::getAngle() const{
    return angle;
}

Tag GameObject::getTag() {
    return tag;
}

