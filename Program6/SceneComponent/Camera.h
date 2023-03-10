//
// Created by Nathan Rice on 2/21/2023.
//
#ifndef PROGRAM5_CAMERA_H
#define PROGRAM5_CAMERA_H

#include <cmath>
#include "SceneComponent.h"

class Camera: SceneComponent {
private:
    const double fov;

    static double degreesToRadians(const double valInDegrees) {
        return valInDegrees * (M_PI / 180);
    }

public:
    Camera() : fov(90) {}

    Camera(const double fovInDegrees, const Vector3 origin, const Vector3 target) :
           fov(degreesToRadians(fovInDegrees)), SceneComponent(origin, target) {}

    const Vector3& getOrigin() const {
        return SceneComponent::getLocation();
    }

    const Vector3& getTarget() const {
        return SceneComponent::getRotation();
    }

    double getFov() const {
        return fov;
    }
};


#endif //PROGRAM5_CAMERA_H
