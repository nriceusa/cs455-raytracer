//
// Created by Nathan Rice on 2/21/2023.
//
#ifndef PROGRAM5_CAMERA_H
#define PROGRAM5_CAMERA_H

#include <cmath>
#include "SceneComponent.h"

class Camera: public SceneComponent {
private:
    const double fov;

    static double degreesToRadians(const double valInDegrees) {
        return valInDegrees * (M_PI / 180);
    }

public:
    Camera() : fov(90) {}

    Camera(const double fovInDegrees,
           const double xOrigin, const double yOrigin, const double zOrigin,
           const double xLookAt, const double yLookAt, const double zLookAt) :
           fov(degreesToRadians(fovInDegrees)),
           SceneComponent(xOrigin, yOrigin, zOrigin, xLookAt, yLookAt, zLookAt) {}

    double getFov() const {
        return fov;
    }
};


#endif //PROGRAM5_CAMERA_H
