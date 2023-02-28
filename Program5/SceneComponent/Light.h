//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_LIGHT_H
#define PROGRAM5_LIGHT_H


#include "SceneComponent.h"

class Light: public SceneComponent {
private:
    const Vector3 Ip;

protected:
    Light() : Ip(0.5, 0.5, 0.5), SceneComponent() {}

    Light(const Vector3& Ip, const Vector3& location) : Ip(Ip), SceneComponent(location) {}

    Light(const Vector3& Ip, const Vector3& location, const Vector3& rotation) : Ip(Ip), SceneComponent(location, rotation) {}

public:
    const Vector3 &getIp() const {
        return Ip;
    }
};


#endif //PROGRAM5_LIGHT_H
