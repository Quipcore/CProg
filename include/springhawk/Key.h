//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_KEY_H
#define CPROG_PROJECT_KEY_H

#include "vector"

class Key{
public:
    enum Keycodes{
        null, //This should probably be renamed
        A,
        D,
        S,
        W
    };

    bool operator==(Key key);
    bool operator==(int);
private:
    std::vector<Keycodes> buffer; //All key pressed down this frame
};
#endif //CPROG_PROJECT_KEY_H
