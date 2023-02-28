//
// Created by Nathan Rice on 2/14/2023.
//

#ifndef PROGRAM5_RAY_H
#define PROGRAM5_RAY_H


#include <ostream>
#include "../Vector3.h"
#include "Light.h"

class Ray {
private:
    const Scene& scene;
    const Vector3 origin;
    const Vector3 destination;

public:
    explicit Ray(const Scene& scene) : scene(scene), origin(0, 0, 0), destination(0, 1, 0) {}

    Ray(const Scene& scene, const Vector3& origin, const Vector3& direction) :
        scene(scene), origin(origin), destination(direction) {}

    Ray(const Scene& scene, const double xOrigin, const double yOrigin, const double zOrigin) :
        scene(scene), origin(xOrigin, yOrigin, zOrigin), destination(0, 1, 0) {}

    Ray(const Scene& scene, const double xOrigin, const double yOrigin, const double zOrigin,
        const double xDirection, const double yDirection, const double zDirection) :
        scene(scene), origin(xOrigin, yOrigin, zOrigin), destination(xOrigin, yOrigin, zOrigin) {}

    const Vector3& getOrigin() const {
        return origin;
    }

    const Vector3& getDestination() const {
        return destination;
    }

    Vector3 at(double position) const {
        return origin + (position * destination);
    }

    double hitSphere(const Sphere& sphere) const {
//        Vector3 rayDirection = Vector3::normalize(destination);
        Vector3 oc = origin - sphere.getCenter();

        double a = Vector3::dot(destination, destination);
        double halfB = Vector3::dot(oc, destination);
        double c = oc.getLength() * oc.getLength() - (sphere.getRadius() * sphere.getRadius());

        double discriminant = halfB * halfB - a * c;
        if (discriminant < 0) {
            return -1;
        } else {
            return (-halfB - sqrt(discriminant)) / a;
        }
    }

    Vector3 computerSurfaceColor(const Vector3& intersect, const Vector3& normal, const Vector3& ambientColor,
                                 const Material& material, const Light& light) const {
        // Compute diffuse
        const Vector3 l = Vector3::normalize(light.getLocation() - intersect);
        const Vector3 n = Vector3::normalize(normal);

        double angleToLight = Vector3::dot(n, l);
        if (angleToLight < 0) {
            angleToLight = 0;
        }

        const Vector3 id = material.getKd() * light.getIp() * material.getOd() * angleToLight;

        // Compute ambience
        const Vector3 ia = material.getKa() * ambientColor * material.getOd();

        // Compute specular highlight
        const Vector3 r = 2 * n * Vector3::dot(n, l) - l;
        double angleToReflection = Vector3::dot(origin, r);
        if (angleToReflection < 0) {
            angleToReflection = 0;
        }

        const Vector3 is = material.getKs() * light.getIp() * material.getOs() * pow(angleToReflection, material.getKgls());

        return id + ia + is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Ray &ray) {
        os << "origin: " << ray.origin << " destination: " << ray.destination;
        return os;
    }
};


#endif //PROGRAM5_RAY_H
