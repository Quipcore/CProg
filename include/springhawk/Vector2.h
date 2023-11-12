//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_VECTOR2_H
#define CPROG_PROJECT_VECTOR2_H

#include <ostream>

class Vector2{
public:
    Vector2(float x, float y);
    Vector2();
    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator*(const float& rhs) const;
    Vector2 operator+=(const Vector2& rhs);
    Vector2 operator-=(const Vector2& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Vector2& dt);

    float getX() const {return x;}
    float getY() const {return y;}
private:
    float y;
    float x;
};

#endif //CPROG_PROJECT_VECTOR2_H
