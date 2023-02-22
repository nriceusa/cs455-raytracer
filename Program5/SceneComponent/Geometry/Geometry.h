//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_GEOMETRY_H
#define PROGRAM5_GEOMETRY_H


#include "../SceneComponent.h"

class Geometry: SceneComponent {
protected:
    Geometry() : SceneComponent() {}

    Geometry(const float xLoc, const float yLoc, const float zLoc) : SceneComponent(xLoc, yLoc, zLoc) {}
};


#endif //PROGRAM5_GEOMETRY_H
