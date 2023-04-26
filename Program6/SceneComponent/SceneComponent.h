//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_SCENE_COMPONENT_H
#define PROGRAM5_SCENE_COMPONENT_H


#include <string>
#include <ostream>
#include "../Vector3.h"

class SceneComponent {
private:
    const Vector3 location;
    const Vector3 rotation;
    const Vector3 scale;

protected:
    SceneComponent() : location(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1) {}

    explicit SceneComponent(const Vector3& location) :
                            location(location), rotation(0, 0, 0), scale(1, 1, 1) {}

    SceneComponent(const Vector3& location, const Vector3& rotation) :
                   location(location), rotation(rotation), scale(1, 1, 1) {}

    SceneComponent(const Vector3& location, const Vector3& rotation, const Vector3& scale) :
                   location(location), rotation(rotation), scale(scale) {}

public:
    const Vector3 &getLocation() const {
        return location;
    }

    const Vector3 &getRotation() const {
        return rotation;
    }

    const Vector3 &getScale() const {
        return scale;
    }

    double getLocationX() {
        return location.getX();
    }

    double getLocationY() {
        return location.getY();
    }

    double getLocationZ() {
        return location.getZ();
    }

    double getRotationX() {
        return rotation.getX();
    }

    double getRotationY() {
        return rotation.getY();
    }

    double getRotationZ() {
        return rotation.getZ();
    }

    friend std::ostream &operator<<(std::ostream &os, const SceneComponent &object) {
        os << "location: " << object.location << std::endl
           << "rotation: " << object.rotation << std::endl
           << "scale: " << object.scale << std::endl;
        return os;
    }
};


#endif //PROGRAM5_SCENE_COMPONENT_H
