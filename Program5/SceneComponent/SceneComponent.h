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
    std::vector<double> location;
    std::vector<double> rotation;
    std::vector<double> scale;

protected:
    SceneComponent() : location(3, 0), rotation(3, 0), scale(3, 1) {}

    SceneComponent(const double xLoc, const double yLoc, const double zLoc) :
                   location{xLoc, yLoc, zLoc}, rotation(3, 0), scale(3, 1) {}

    SceneComponent(const double xLoc, const double yLoc, const double zLoc,
                   const double xRot, const double yRot, const double zRot) :
                   location{xLoc, yLoc, zLoc}, rotation{xRot, yRot, zRot}, scale(3, 1) {}

    SceneComponent(const double xLoc, const double yLoc, const double zLoc,
                   const double xRot, const double yRot, const double zRot,
                   const double xScale, const double yScale, const double zScale) :
                   location{xLoc, yLoc, zLoc}, rotation{xRot, yRot, zRot}, scale{xScale, yScale, zScale} {}

public:
    const std::vector<double> &getLocation() const {
        return location;
    }

    const std::vector<double> &getRotation() const {
        return rotation;
    }

    const std::vector<double> &getScale() const {
        return scale;
    }

    double getLocationX() {
        return location.at(0);
    }

    double getLocationY() {
        return location.at(1);
    }

    double getLocationZ() {
        return location.at(2);
    }

    double getRotationX() {
        return rotation.at(0);
    }

    double getRotationY() {
        return rotation.at(1);
    }

    double getRotationZ() {
        return rotation.at(2);
    }

    void setLocation(const double x, const double y, const double z) {
        location.at(0) = x;
        location.at(1) = y;
        location.at(2) = z;
    }

    void setRotation(const double x, const double y, const double z) {
        rotation.at(0) = x;
        rotation.at(1) = y;
        rotation.at(2) = z;
    }

    void setScale(const double x, const double y, const double z) {
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
