//
// Created by felix on 2023-11-26.
//

#include "springhawk/ui/TextField.h"

TextField::TextField(std::string text, Vector2 &position) {
    this->text = text;
    this->position = position;
}

std::string TextField::getText() const{
    return text;
}

void TextField::setText(std::string text) {
    this->text = text;
}
