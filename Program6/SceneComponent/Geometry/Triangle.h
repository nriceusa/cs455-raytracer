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

    const Vector3 edge1;
    const Vector3 edge2;
    const Vector3 edge3;

    const Vector3 normal;

public:
    Triangle(Material &material, const Vector3 &location,
             const Vector3 &point1, const Vector3 &point2, const Vector3 &point3) :
             Geometry(material, location), point1(point1), point2(point2), point3(point3),
             edge1(point2 - point1), edge2(point3 - point2), edge3(point1 - point3),
             normal(Vector3::normalize(Vector3::cross(point2 - point1, point3 - point2))) {}
              // TODO: make sure you're crossing these right

    const Vector3 &getPoint1() const {
        return point1;
    }

    const Vector3 &getPoint2() const {
        return point2;
    }

    const Vector3 &getPoint3() const {
        return point3;
    }

    const Vector3 &getEdge1() const {
        return edge1;
    }

    const Vector3 &getEdge2() const {
        return edge2;
    }

    const Vector3 &getEdge3() const {
        return edge3;
    }

    const Vector3 &getNormal() const {
        return normal;
    }
};


#endif //PROGRAM5_TRIANGLE_H
