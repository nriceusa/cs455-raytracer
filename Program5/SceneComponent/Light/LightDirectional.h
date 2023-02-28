//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_LIGHT_DIRECTIONAL_H
#define PROGRAM5_LIGHT_DIRECTIONAL_H


#include "Light.h"

class LightDirectional: public Light {
public:
    LightDirectional(const Vector3& Ip, const Vector3& location, const Vector3& rotation) : Light(Ip, location, rotation) {}
};


#endif //PROGRAM5_LIGHT_DIRECTIONAL_H
