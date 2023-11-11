#ifndef CPROG_PROJECT_SQUARE_H
#define CPROG_PROJECT_SQUARE_H

#include "GameObject.h"

namespace Scripts {
    class Square : public GameObject {
    public:
        Square() : GameObject(){};
        void update() override;
    private:
        int size = 1;
    };
}

#endif //CPROG_PROJECT_SQUARE_H
