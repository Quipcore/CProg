//
// Created by felix on 2023-11-26.
//

#ifndef CPROG_PROJECT_TEXTFIELD_H
#define CPROG_PROJECT_TEXTFIELD_H

#include <string>
#include "springhawk/Vector2.h"


class TextField {
    TextField(std::string text, Vector2 &position);
    ~TextField() = default;
    std::string getText() const;
    void setText(std::string text);


private:
    std::string text;
    Vector2 position;

};

#endif //CPROG_PROJECT_TEXTFIELD_H

