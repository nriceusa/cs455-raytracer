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
    const Vector3 destination;

public:
    Ray() : origin(0, 0, 0), destination(0, 1, 0) {}

    Ray(const Vector3& origin, const Vector3& direction) :
            origin(origin), destination(direction) {}

    Ray(const double xOrigin, const double yOrigin, const double zOrigin) :
            origin(xOrigin, yOrigin, zOrigin), destination(0, 1, 0) {}

    Ray(const double xOrigin, const double yOrigin, const double zOrigin,
        const double xDirection, const double yDirection, const double zDirection) :
            origin(xOrigin, yOrigin, zOrigin), destination(xOrigin, yOrigin, zOrigin) {}

    const Vector3& getOrigin() const {
        return origin;
    }

    const Vector3& getDestination() const {
        return destination;
    }

    Vector3 at(double position) const {
        return origin + (position * destination);
    }

    double hitSphere(const Sphere& sphere) const {
//        Vector3 rayDirection = Vector3::normalize(destination);
        Vector3 originToCenter = origin - sphere.getCenter();

        double a = Vector3::dot(destination, destination);
        double halfB = Vector3::dot(originToCenter, destination);
        double c = originToCenter.getLength() * originToCenter.getLength() - (sphere.getRadius() * sphere.getRadius());

        double discriminant = halfB * halfB - a * c;
        if (discriminant < 0) {
            return -1;
        } else {
            return (-halfB - sqrt(discriminant)) / a;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Ray &ray) {
        os << "origin: " << ray.origin << " destination: " << ray.destination;
        return os;
    }
};


#endif //PROGRAM5_RAY_H
