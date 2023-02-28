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

    Geometry(Material& material, const Vector3& location) :
             material(material), SceneComponent(location) {}

    Geometry(Material& material, const Vector3& location, const Vector3& rotation) :
            material(material), SceneComponent(location, rotation) {}

    Geometry(Material& material, const Vector3& location, const Vector3& rotation, const Vector3& scale) :
            material(material), SceneComponent(location, rotation, scale) {}

public:
    const Material& getMaterial() const {
        return material;
    }
};


#endif //PROGRAM5_GEOMETRY_H
