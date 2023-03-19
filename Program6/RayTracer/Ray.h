//
// Created by Nathan Rice on 2/14/2023.
//

#ifndef PROGRAM5_RAY_H
#define PROGRAM5_RAY_H


#include <ostream>
#include "../Vector3.h"
#include "../SceneComponent/Light/Light.h"

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

    bool hitTriangle(const Triangle& triangle) const {
        // Compute plane intersection
        const double vd = Vector3::dot(triangle.getNormal(), destination);
        if (vd >= 0) {  // Face is parallel or facing away from the triangle
            return false;
        }

        const double d = Vector3::dot(triangle.getPoint1(), triangle.getNormal()); // TODO: make sure
                                                                                                      // this is the coreect calculation of d
        const double t = -(vd + d) / vd;
        if (t <= 0) {  // Intersection is in the negative direction
            return false;
        }

        const Vector3 intersect = origin + (destination * t);

        const Vector3 C1 = intersect - triangle.getEdge1();
        const Vector3 C2 = intersect - triangle.getEdge2();
        const Vector3 C3 = intersect - triangle.getEdge3();

        return ((Vector3::dot(triangle.getNormal(), Vector3::cross(triangle.getEdge1(), C1)) > 0) &&
                (Vector3::dot(triangle.getNormal(), Vector3::cross(triangle.getEdge2(), C2)) > 0) &&
                (Vector3::dot(triangle.getNormal(), Vector3::cross(triangle.getEdge3(), C3)) > 0));
    }

    Vector3 computeSurfaceColor(const Vector3& intersect, const Vector3& normal, const Vector3& ambientColor,
                                const Material& material, const Light& light) const {
        const Vector3 l = Vector3::normalize(light.getLocation() - intersect);
        const Vector3 n = Vector3::normalize(normal);
        const Vector3 v = Vector3::normalize(origin - intersect);

        // Compute diffuse
        double angleToLight = Vector3::dot(n, l);
        if (angleToLight < 0) {
            angleToLight = 0;
        }
        const Vector3 id = material.getKd() * light.getIp() * material.getOd() * angleToLight;

        // Compute ambience
        const Vector3 ia = material.getKa() * ambientColor * material.getOd();

        // Compute specular highlight
        const Vector3 r = 2 * n * Vector3::dot(n, l) - l;
        double angleToReflection = Vector3::dot(v, r);
        if (angleToReflection < 0) {
            angleToReflection = 0;
        }
        const Vector3 is = material.getKs() * light.getIp() * material.getOs() * pow(angleToReflection, material.getKgls());

        // Sum lighting components
        Vector3 surfaceColor = id + ia + is;
        surfaceColor.setX(surfaceColor.getX() > 1 ? 1 : surfaceColor.getX());
        surfaceColor.setY(surfaceColor.getY() > 1 ? 1 : surfaceColor.getY());
        surfaceColor.setZ(surfaceColor.getZ() > 1 ? 1 : surfaceColor.getZ());
        return surfaceColor;
    }

    friend std::ostream &operator<<(std::ostream &os, const Ray &ray) {
        os << "origin: " << ray.origin << " destination: " << ray.destination;
        return os;
    }
};


#endif //PROGRAM5_RAY_H
