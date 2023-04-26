//
// Created by Nathan Rice on 2/14/2023.
//

#ifndef PROGRAM5_RAY_H
#define PROGRAM5_RAY_H

#define MIN_REFLECTION_DISTANCE 0

#include <ostream>
#include <limits>
#include "../Vector3.h"
#include "../SceneComponent/Light/Light.h"

class Ray {
private:
    const Scene& scene;
    const Vector3 origin;
    const Vector3 direction;

public:
    explicit Ray(const Scene& scene) : scene(scene), origin(0, 0, 0), direction(0, 1, 0) {}

    Ray(const Scene& scene, const Vector3& origin, const Vector3& direction) :
            scene(scene), origin(origin), direction(direction) {}

    Ray(const Scene& scene, const double xOrigin, const double yOrigin, const double zOrigin) :
            scene(scene), origin(xOrigin, yOrigin, zOrigin), direction(0, 1, 0) {}

    Ray(const Scene& scene, const double xOrigin, const double yOrigin, const double zOrigin,
        const double xDirection, const double yDirection, const double zDirection) :
            scene(scene), origin(xOrigin, yOrigin, zOrigin), direction(xOrigin, yOrigin, zOrigin) {}

    const Vector3& getOrigin() const {
        return origin;
    }

    const Vector3& getDestination() const {
        return direction;
    }

    Vector3 at(double position) const {
        return origin + (position * direction);
    }

    double hitSphere(const Sphere& sphere) const {
        Vector3 oc = origin - sphere.getCenter();

        double a = Vector3::dot(direction, direction);
        double halfB = Vector3::dot(oc, direction);
        double c = oc.getLength() * oc.getLength() - (sphere.getRadius() * sphere.getRadius());

        double discriminant = halfB * halfB - a * c;
        if (discriminant < 0) {
            return -1;
        } else {
            return (-halfB - sqrt(discriminant)) / a;
        }
    }

    double hitTriangle(const Triangle& triangle) const {
        // Compute plane intersect
        const Vector3 originToPlane = triangle.getPoint1() - origin;

        const double rayScalar = Vector3::dot(originToPlane, triangle.getNormal()) /
                                 Vector3::dot(direction, triangle.getNormal());

        const Vector3 intersect = origin + (rayScalar * direction);

        if (rayScalar >= 0 && rayScalar <= 1) {
            return -1;
        }

        // Compute triangle intersect
        const Vector3 point1ToIntersect = intersect - triangle.getPoint1();
        const Vector3 point2ToIntersect = intersect - triangle.getPoint2();
        const Vector3 point3ToIntersect = intersect - triangle.getPoint3();

        if ((Vector3::dot(triangle.getNormal(), Vector3::cross(triangle.getEdge1(), point1ToIntersect)) > 0) &&
            (Vector3::dot(triangle.getNormal(), Vector3::cross(triangle.getEdge2(), point2ToIntersect)) > 0) &&
            (Vector3::dot(triangle.getNormal(), Vector3::cross(triangle.getEdge3(), point3ToIntersect)) > 0)) {
            return rayScalar;
        } else {
            return -1;
        }
    }

    Vector3 computeSurfaceColor(const size_t numRecursions, const Vector3& intersect, const Vector3& normal,
                                const Vector3& ambientColor, const Material& material) const {
        if (numRecursions <= 0) {
            return {0, 0, 0};
        }

        const Light& light = scene.getLights().at(0);
        const Vector3 l = Vector3::normalize(light.getLocation() - intersect);
        const Vector3 n = Vector3::normalize(normal);
        const Vector3 v = Vector3::normalize(origin - intersect);
        const Vector3 d = Vector3::normalize(direction);

        // Compute shadows
        bool inShadow = false;
        const Vector3 shadowVector = Vector3::normalize(light.getLocation() - intersect);
        const Ray shadowRay(scene, intersect + (shadowVector * 0.001), light.getLocation());
        for (const Triangle& triangle : scene.getTriangles()) {
            const double t = shadowRay.hitTriangle(triangle);
            if (t > 0) {
                inShadow = true;
            }
        }
        for (const Sphere& sphere : scene.getSpheres()) {
            const double t = shadowRay.hitSphere(sphere);
            if (t > 0) {
                inShadow = true;
            }
        }

        // Compute reflections
        const Vector3 reflectionDirection = d - (2 * n * (Vector3::dot(d, n)));
        const Ray reflectionRay(scene, intersect + (reflectionDirection * 0.001), reflectionDirection);

        double dl = d.getLength();
        double nl = n.getLength();
        double rl = reflectionDirection.getLength();

        Vector3 reflectedColor(0, 0, 0);
        double lowestT = std::numeric_limits<double>::max();
        for (const Sphere& sphere : scene.getSpheres()) {
            const double t = reflectionRay.hitSphere(sphere);
            if (t < lowestT && t > MIN_REFLECTION_DISTANCE) {
                lowestT = t;
                const Vector3 reflectionIntersect = reflectionRay.at(t);
                const Vector3 sphereNormal = (intersect - sphere.getCenter()) / sphere.getRadius();
                reflectedColor = reflectionRay.computeSurfaceColor(numRecursions - 1, reflectionIntersect, sphereNormal,
                                                                   scene.getAmbientLight(), sphere.getSphereMaterial());
            }
        }
        for (const Triangle& triangle : scene.getTriangles()) {
            const double t = reflectionRay.hitTriangle(triangle);
//            if (t < lowestT && t > MIN_REFLECTION_DISTANCE) {
            if (t < lowestT && t > -1) {
                lowestT = t;
                const Vector3 reflectionIntersect = reflectionRay.at(t);
                reflectedColor = reflectionRay.computeSurfaceColor(numRecursions - 1, reflectionIntersect, triangle.getNormal(),
                                                                   scene.getAmbientLight(), triangle.getTriangleMaterial());
            }
        }
        const Vector3 ir = material.getKs() * reflectedColor;
//        const Vector3 ir = reflectedColor;

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
        Vector3 surfaceColor = ia + ir;
        if (!inShadow) {
            surfaceColor += is + id;
        }
        surfaceColor.setX(surfaceColor.getX() > 1 ? 1 : surfaceColor.getX());
        surfaceColor.setY(surfaceColor.getY() > 1 ? 1 : surfaceColor.getY());
        surfaceColor.setZ(surfaceColor.getZ() > 1 ? 1 : surfaceColor.getZ());
        return surfaceColor;
    }

    friend std::ostream &operator<<(std::ostream &os, const Ray &ray) {
        os << "origin: " << ray.origin << " direction: " << ray.direction;
        return os;
    }
};


#endif //PROGRAM5_RAY_H
