//
// Created by Nathan Rice on 3/9/2023.
//

#ifndef PROGRAM5_TRIANGLE_H
#define PROGRAM5_TRIANGLE_H


#include "Geometry.h"

class Triangle: Geometry {
private:
    const Vector3 point1;
    const Vector3 point2;
    const Vector3 point3;

public:
    Triangle(Material &material, const Vector3 &location, const Vector3 &point1, const Vector3 &point2,
             const Vector3 &point3) : Geometry(material, location), point1(point1), point2(point2), point3(point3) {}
};


#endif //PROGRAM5_TRIANGLE_H
