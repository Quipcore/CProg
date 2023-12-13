#include "components/uiComponents/TextField.h"

//----------------------------------------------------------------------------------------------------------------------

TextField::TextField(std::string text, Vector2 &position) {
    setText(text);
    setPosition(position);
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 TextField::getPosition() const{
    return position;
}

//----------------------------------------------------------------------------------------------------------------------

void TextField::setPosition(Vector2 position) {
    this->position = position;
}

//----------------------------------------------------------------------------------------------------------------------

std::string TextField::getText() const{
    return text;
}

//----------------------------------------------------------------------------------------------------------------------

void TextField::setText(std::string text) {
    delete &this->text;
    this->text = text;
}


