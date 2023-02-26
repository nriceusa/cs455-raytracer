//
// Created by Nathan Rice on 2/14/2023.
//

#ifndef PROGRAM5_RAY_H
#define PROGRAM5_RAY_H


#include <ostream>
#include "../Vector3.h"

class Ray {
private:
    const Vector3 origin;
    const Vector3 direction;

public:
    Ray() : origin(0, 0, 0), direction(0, 1, 0) {}

    Ray(const Vector3& origin, const Vector3& direction) :
        origin(origin), direction(direction) {}

    Ray(const double xOrigin, const double yOrigin, const double zOrigin) :
        origin(xOrigin, yOrigin, zOrigin), direction(0, 1, 0) {}

    Ray(const double xOrigin, const double yOrigin, const double zOrigin,
        const double xDirection, const double yDirection, const double zDirection) :
        origin(xOrigin, yOrigin, zOrigin), direction(xOrigin, yOrigin, zOrigin) {}

    const Vector3& getOrigin() const {
        return origin;
    }

    const Vector3& getDirection() const {
        return direction;
    }

    bool hitSphere(const Sphere& sphere) const {
        Vector3 oc = origin - sphere.getCenter();
        double a = Vector3::dot(direction, direction);
        double b = 2 * Vector3::dot(oc, direction);
        double c = Vector3::dot(oc, oc) - (sphere.getRadius() * sphere.getRadius());

        double discriminant = (b * b) - (4 * a * c);
        return (discriminant > 0);
    }

    friend std::ostream &operator<<(std::ostream &os, const Ray &ray) {
        os << "origin: " << ray.origin << " direction: " << ray.direction;
        return os;
    }
};


#endif //PROGRAM5_RAY_H
