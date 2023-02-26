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
    Sphere() : radius(1) {}

    Sphere(Material& material, const float radius, const float xLoc, const float yLoc, const float zLoc) :
           radius(radius), Geometry(material, xLoc, yLoc, zLoc) {}

    float getRadius() const {
        return radius;
    }

    void setRadius(float newRadius) {
        Sphere::radius = newRadius;
    }
};


#endif //PROGRAM5_SPHERE_H
