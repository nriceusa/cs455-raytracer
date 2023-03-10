//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_SPHERE_H
#define PROGRAM5_SPHERE_H


#include "Geometry.h"

class Sphere: Geometry {
private:
    float radius;

public:
    explicit Sphere(const float radius) : radius(radius), Geometry() {}

    Sphere(Material& material, const float radius, const Vector3& location) :
           radius(radius), Geometry(material, location) {}

    const Vector3& getCenter() const {
        return Geometry::getLocation();
    }

    float getRadius() const {
        return radius;
    }

    void setRadius(float newRadius) {
        Sphere::radius = newRadius;
    }

    const Material& getSphereMaterial() const {
        return Geometry::getMaterial();
    }
};


#endif //PROGRAM5_SPHERE_H
