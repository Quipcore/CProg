//
// Created by felix on 2023-11-12.
//
#include <cmath>
#include "springhawk/Vector2.h"

Vector2 Vector2::operator+(const Vector2 &rhs) const {
    return {x+rhs.x,y+rhs.y};
}

Vector2 Vector2::operator-(const Vector2 &rhs) const {
    return {x-rhs.x,y-rhs.y};
}

Vector2 Vector2::operator*(const double &rhs) const {
    return {x*rhs,y*rhs};
}

Vector2 Vector2::operator+=(const Vector2& rhs){
    x += rhs.getX();
    y += rhs.getY();
    return *this;
}
Vector2 Vector2::operator-=(const Vector2& rhs){
    x -= rhs.getX();
    y -= rhs.getY();
    return *this;
}

Vector2& Vector2::operator=(const Vector2& rhs){
    x = rhs.getX();
    y = rhs.getY();
    return *this;
}

Vector2::Vector2(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector2::Vector2(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector2::Vector2() {
    x = 0;
    y = 0;
}

std::ostream &operator<<(std::ostream &os, const Vector2 &dt) {
    os << "{x: " << dt.x << ", y: " << dt.y << "}";
    return os;
}

double Vector2::magnitude() const {
    return std::sqrt((x*x) + (y*y));
}
