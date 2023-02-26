//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_LIGHT_H
#define PROGRAM5_LIGHT_H


#include "SceneComponent.h"

class Light: public SceneComponent {
protected:
    Light() : SceneComponent() {}

    explicit Light(const Vector3& location) : SceneComponent(location) {}

    Light(const Vector3& location, const Vector3& rotation) : SceneComponent(location, rotation) {}

    Light(const Vector3& location, const Vector3& rotation, const Vector3& scale) :
          SceneComponent(location, rotation, scale) {}
};


#endif //PROGRAM5_LIGHT_H
