//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_GEOMETRY_H
#define PROGRAM5_GEOMETRY_H


#include "../SceneComponent.h"
#include "Material.h"

class Geometry: public SceneComponent {
private:
    const Material material;

protected:
    Geometry() :
        material(0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5),
        SceneComponent() {}

    Geometry(Material& material, const float xLoc, const float yLoc, const float zLoc) :
             material(material), SceneComponent(xLoc, yLoc, zLoc) {}
};


#endif //PROGRAM5_GEOMETRY_H
