//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_VECTOR3_H
#define PROGRAM5_VECTOR3_H


#include <cmath>
#include <iosfwd>

class Vector3 {
private:
    double x;
    double y;
    double z;

public:
    Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    Vector3 operator-() const {
        return Vector3{-x, -y, -z};
    }

    Vector3& operator+=(const Vector3& vector) {
        x += vector.getX();
        y += vector.getY();
        z += vector.getZ();
        return *this;
    }

    Vector3& operator*=(const Vector3& vector) {
        x *= vector.getX();
        y *= vector.getY();
        z *= vector.getZ();
        return *this;
    }

    Vector3& operator/=(const Vector3& vector) {
        return *this *= 1/vector;
    }

    double getLength() const {
        return sqrt(x * x + y * y + z * z);
    }

    bool operator==(const Vector3& vector) const {
        return x == vector.x &&
               y == vector.y &&
               z == vector.z;
    }

    bool operator!=(const Vector3 &vector) const {
        return !(vector == *this);
    }

    friend Vector3 operator+(const Vector3& vectorLeft, const Vector3& vectorRight) {
        return Vector3{vectorLeft.getX() + vectorRight.getX(),
                       vectorLeft.getY() + vectorRight.getY(),
                       vectorLeft.getZ() + vectorRight.getZ()};
    }

    friend Vector3 operator-(const Vector3& vectorLeft, const Vector3& vectorRight) {
        return Vector3{vectorLeft.getX() - vectorRight.getX(),
                       vectorLeft.getY() - vectorRight.getY(),
                       vectorLeft.getZ() - vectorRight.getZ()};
    }

    friend Vector3 operator*(const Vector3& vectorLeft, const Vector3& vectorRight) {
        return Vector3{vectorLeft.getX() * vectorRight.getX(),
                       vectorLeft.getY() * vectorRight.getY(),
                       vectorLeft.getZ() * vectorRight.getZ()};
    }

    friend Vector3 operator*(const double multiplier, const Vector3& vector) {
        return Vector3{multiplier * vector.getX(),
                       multiplier * vector.getY(),
                       multiplier * vector.getZ()};
    }

    friend Vector3 operator*(const Vector3& vector, const double multiplier) {
        return multiplier * vector;
    }

    friend Vector3 operator/(const Vector3& vector, const double dividend) {
        return 1/dividend * vector;
    }

    static double dot(const Vector3& vectorLeft, const Vector3& vectorRight) {
        return vectorLeft.getX() * vectorRight.getX() +
               vectorLeft.getY() * vectorRight.getY() +
               vectorLeft.getZ() * vectorRight.getZ();
    }

    static Vector3 cross(const Vector3& vectorLeft, const Vector3& vectorRight) {
        return Vector3{vectorLeft.getY() * vectorRight.getZ() - vectorLeft.getZ() * vectorRight.getY(),
                       vectorLeft.getZ() * vectorRight.getX() - vectorLeft.getX() * vectorRight.getZ(),
                       vectorLeft.getX() * vectorRight.getY() - vectorLeft.getY() * vectorRight.getX()};
    }

    static Vector3 normalize(const Vector3& vector) {
        return vector / vector.getLength();
    }
};


#endif //PROGRAM5_VECTOR3_H
