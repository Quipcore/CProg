//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_VECTOR2_H
#define CPROG_PROJECT_VECTOR2_H

#include <ostream>

class Vector2{
public:
    Vector2(double x, double y);
    Vector2(int x, int y);
    Vector2(const Vector2& rhs);
    Vector2();

    /**
     * Shorhand for Vector2(0,0)
     */
    static const Vector2 zero;

    /**
     * Shorthand for Vector2(1,1)
     */
    static const Vector2 one;

    /**
     * Shorthand for Vector2(0,1)
     */
    static const Vector2 up;

    /**
     * Shorthand for Vector2(0,-1)
     */
    static const Vector2 down;

    /**
     * Shorthand for Vector2(-1,0)
     */
    static const Vector2 left;

    /**
     * Shorthand for Vector2(1,0)
     */
    static const Vector2 right;

    /**
     * Returns the value of the x component of this vector
     * @return The x value of this vector
     */
    double getX() const;

    /**
     * Returns the value of the y component of this vector
     * @return The y value of this vector
     */
    double getY() const;

    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator-(const Vector2& rhs) const;
    Vector2 operator*(const double& rhs) const;
    Vector2 operator+=(const Vector2& rhs);
    Vector2 operator-=(const Vector2& rhs);
    Vector2 operator*=(const double& rhs);
    Vector2& operator=(const Vector2& rhs);
    bool operator==(const Vector2& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector2& dt);

    /**
     * Returns the magnitude (length) of this vector
     * @return The magnitude (length) of this vector
     */
    double magnitude() const;

    /**
     * Returns the dot product of this vector and the given vector
     * @param rhs The vector to compare this vector to
     * @return Dot product of this vector and the given vector
     */
    double dot(const Vector2& rhs) const;

    /**
     * Returns the distance between this vector and the given vector
     * @param rhs The vector to compare this vector to
     * @return The distance between this vector and the given vector
     */
    double distance(const Vector2& rhs) const;

    /**
     * Returns the angle between this vector and the given vector. Given in radians
     * @param rhs The vector to compare this vector to
     * @return The angle between this vector and the given vector in radians
     */
    double angleBetween(const Vector2& rhs) const;

    /**
     * Returns a normalized version of this vector
     * @return A normalized version of this vector
     */
    Vector2 normalize();

    /**
     * Rotates this vector by the given angle
     * @param angle The angle to rotate this vector by
     * @return The rotated vector
     */
    Vector2 rotate(double angle);

    /**
     * Returns the dot product of the two given vectors. Order does not matter.
     * @param v1 First vector
     * @param v2 Second vector
     * @return Dot product of the two given vectors
     */
    static double dot(const Vector2& v1, const Vector2& v2);

    /**
     * Returns the distance between the two given vectors
     * @param v1 First vector
     * @param v2 Second vector
     * @return Distance between the two given vectors
     */
    static double distance(const Vector2& v1, const Vector2& v2);

    /**
     * Returns the angle between the two given vectors. Given in radians
     * @param v1 First vector
     * @param v2 Second vector
     * @return Angle between the two given vectors in radians
     */
    static double angle(const Vector2& v1, const Vector2& v2);

    /**
     * Returns a normalized version of the given vector
     * @param vector
     * @return Normal vector. That is, a vector with the same direction but with magnitude (length) 1
     */
    static Vector2 normalized(const Vector2& vector);

    /**
     * Returns a rotated version of the given vector
     * @param vector Vector to rotate
     * @param angle Angle to rotate the vector by
     * @return Rotated vector
     */
    static Vector2 rotated(const Vector2& vector, double angle);


    static Vector2 parse(std::string point);

private:
    double y;
    double x;
};

#endif //CPROG_PROJECT_VECTOR2_H
