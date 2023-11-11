//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_GAMEOBJECT_H
#define CPROG_PROJECT_GAMEOBJECT_H
struct position{
    int x = 0;
    int y = 0;
};

class GameObject {
public:
    GameObject() = default;
    ~GameObject() = default;

    virtual void update();

protected:
    position position;
};


#endif //CPROG_PROJECT_GAMEOBJECT_H
