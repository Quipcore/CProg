//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_VECTOR2_H
#define CPROG_PROJECT_VECTOR2_H

#include <ostream>

class Vector2{
public:
    Vector2(double x, double y);
    Vector2();

    Vector2(int x, int y);

    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator-(const Vector2& rhs) const;
    Vector2 operator*(const double& rhs) const;
    Vector2 operator+=(const Vector2& rhs);
    Vector2 operator-=(const Vector2& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Vector2& dt);
    Vector2& operator=(const Vector2& rhs);

    double getX() const {return x;}
    double getY() const {return y;}

    double magnitude() const;

private:
    double y;
    double x;
};

#endif //CPROG_PROJECT_VECTOR2_H
