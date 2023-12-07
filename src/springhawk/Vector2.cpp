//
// Created by felix on 2023-11-12.
//
#include <cmath>
#include "springhawk/Vector2.h"

//Unit vector is up and right, that is (0,1) and (1,0). This is to make it easier for the user to work with the engine.
//The origin is in the lower left corner of the screen.
Vector2 const Vector2::zero = Vector2(0,0);
Vector2 const Vector2::one = Vector2(1,1);
Vector2 const Vector2::up = Vector2(0,1);
Vector2 const Vector2::down = Vector2(0,-1);
Vector2 const Vector2::left = Vector2(-1,0);
Vector2 const Vector2::right = Vector2(1,0);

//----------------------------------------------------------------------------------------------------------------------

Vector2::Vector2(int x, int y) {
    this->x = x;
    this->y = y;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2::Vector2(double x, double y) {
    this->x = x;
    this->y = y;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2::Vector2() {
    x = 0;
    y = 0;
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::getX() const {
    return x;
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::getY() const {
    return y;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::operator+(const Vector2 &rhs) const {
    return {x+rhs.x,y+rhs.y};
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::operator-(const Vector2 &rhs) const {
    return {x-rhs.x,y-rhs.y};
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::operator*(const double &rhs) const {
    return {x*rhs,y*rhs};
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::operator+=(const Vector2& rhs){
    x += rhs.getX();
    y += rhs.getY();
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::operator-=(const Vector2& rhs){
    x -= rhs.getX();
    y -= rhs.getY();
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2& Vector2::operator=(const Vector2& rhs){
    x = rhs.getX();
    y = rhs.getY();
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::operator*=(const double &rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Vector2 &dt) {
    os << "{x: " << dt.x << ", y: " << dt.y << "}";
    return os;
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::magnitude() const {
    return std::sqrt((x*x) + (y*y));
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::dot(const Vector2 &v1, const Vector2 &v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::distance(const Vector2 &v1, const Vector2 &v2) {
    return (v1 - v2).magnitude();
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::angle(const Vector2 &v1, const Vector2 &v2) {
    double magProduct = v1.magnitude() * v2.magnitude();
    if(magProduct != 0){
        double dotProduct = Vector2::dot(v1,v2);
        return std::acos(dotProduct/magProduct);
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::normalized(const Vector2 &vector) {
    return vector * (1 / vector.magnitude());
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::rotated(const Vector2 &vector, double angle) {
    double newX = vector.x * std::cos(angle) - vector.y * std::sin(angle);
    double newY = vector.x * std::sin(angle) + vector.y * std::cos(angle);
    return {newX, newY};
}

//----------------------------------------------------------------------------------------------------------------------

bool Vector2::operator==(const Vector2 &rhs) const {
    return x == rhs.x && y == rhs.y;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2::Vector2(const Vector2 &rhs) {
    x = rhs.x;
    y = rhs.y;
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::dot(const Vector2 &rhs) const {
    return (this->x*rhs.x) + (this->y*rhs.y);
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::angleBetween(const Vector2 &rhs) const {
    double dot = this->dot(rhs);
    double mag = this->magnitude() * rhs.magnitude();
    return std::acos(dot/mag);
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::normalize() {
    *this *= 1/this->magnitude();
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::rotate(double angle){
    double newX = x * std::cos(angle) - y * std::sin(angle);
    double newY = x * std::sin(angle) + y * std::cos(angle);
    *this = Vector2(newX, newY);
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

double Vector2::distance(const Vector2 &rhs) const {
    return (*this - rhs).magnitude();
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Vector2::parse(std::string point) {
    for(int i = 0; i < point.length(); i++){
        if(point[i] == ','){
            std::string x = point.substr(1,i-1);
            std::string y = point.substr(i+1,point.length()-i-2);
            return {std::stod(x),std::stod(y)};
        }
    }
    return Vector2::zero;
}
