//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_SCENE_COMPONENT_H
#define PROGRAM5_SCENE_COMPONENT_H


#include <vector>
#include <string>
#include <ostream>

class SceneComponent {
private:
    std::vector<float> location;
    std::vector<float> rotation;
    std::vector<float> scale;

public:
    SceneComponent() : location(3, 0), rotation(3, 0), scale(3, 0) {}

    SceneComponent(float xLoc, float yLoc, float zLoc) : location(3), rotation(3, 0), scale(3, 0) {
        setLocation(xLoc, yLoc, zLoc);
    }

    SceneComponent(float xLoc, float yLoc, float zLoc,
                   float xRot, float yRot, float zRot) : location(3), rotation(3), scale(3, 0) {
        setLocation(xLoc, yLoc, zLoc);
        setRotation(xRot, yRot, zRot);
    }

    SceneComponent(float xLoc, float yLoc, float zLoc,
                   float xRot, float yRot, float zRot,
                   float xScale, float yScale, float zScale) : location(3), rotation(3), scale(3) {
        setLocation(xLoc, yLoc, zLoc);
        setRotation(xRot, yRot, zRot);
        setScale(xScale, yScale, zScale);
    }

    const std::vector<float> &getLocation() const {
        return location;
    }

    const std::vector<float> &getRotation() const {
        return rotation;
    }

    const std::vector<float> &getScale() const {
        return scale;
    }

    float getLocationX() {
        return location.at(0);
    }

    float getLocationY() {
        return location.at(1);
    }

    float getLocationZ() {
        return location.at(2);
    }

    float getRotationX() {
        return rotation.at(0);
    }

    float getRotationY() {
        return rotation.at(1);
    }

    float getRotationZ() {
        return rotation.at(2);
    }

    void setLocation(float x, float y, float z) {
        location.at(0) = x;
        location.at(1) = y;
        location.at(2) = z;
    }

    void setRotation(float x, float y, float z) {
        rotation.at(0) = x;
        rotation.at(1) = y;
        rotation.at(2) = z;
    }

    void setScale(float x, float y, float z) {
        scale.at(0) = x;
        scale.at(1) = y;
        scale.at(2) = z;
    }

    friend std::ostream &operator<<(std::ostream &os, const SceneComponent &object) {
        os << "location: " << object.location.at(0) << " " << object.location.at(1) << " " << object.location.at(2) << std::endl
           << " rotation: " << object.rotation.at(0) << " " << object.rotation.at(1) << " " << object.rotation.at(2) << std::endl
           << " scale: " << object.scale.at(0) << " " << object.scale.at(1) << " " << object.scale.at(2) << std::endl;
        return os;
    }
};


#endif //PROGRAM5_SCENE_COMPONENT_H