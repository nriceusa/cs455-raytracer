//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_RAYTRACER_H
#define PROGRAM5_RAYTRACER_H

#define NUM_RECURSIONS 4
#define MIN_CLIPPING_DISTANCE 0

#include <cmath>
#include <iostream>
#include <limits>
#include "../Image/Screen.h"
#include "../Scene.h"
#include "Ray.h"

class RayTracer {
private:
    Screen& screen;
    const Scene& scene;

public:
    RayTracer(Screen& screen, const Scene& scene) : screen(screen), scene(scene) {}

    void render() {
        Vector3 rayVector = Vector3::normalize(scene.getCamera().getTarget() - scene.getCamera().getOrigin());

        const double xOffset = rayVector.getZ() * tan(scene.getCamera().getFov() / 2);
        const double yOffset = -xOffset * (static_cast<double>(screen.getHeight()) / static_cast<double>(screen.getWidth()));
        const double rayWidth = (2 * -xOffset) / static_cast<double>(screen.getWidth());
        const double initial_x = rayVector.getX() + xOffset;
        const double initial_y = rayVector.getY() + yOffset;

        rayVector.setX(initial_x);
        for (size_t x = 0; x < screen.getWidth(); ++x) {
            rayVector.setX(rayVector.getX() + rayWidth);

            rayVector.setY(initial_y);
            for (size_t y = 0; y < screen.getHeight(); ++y) {
                rayVector.setY(rayVector.getY() - rayWidth);

                Ray ray(scene, scene.getCamera().getOrigin(), rayVector);
                double lowestT = std::numeric_limits<double>::max();

                // Check for intersections with spheres
                for (const Sphere& sphere : scene.getSpheres()) {
                    const double t = ray.hitSphere(sphere);
                    if (t < lowestT && t > MIN_CLIPPING_DISTANCE) {
                        lowestT = t;
                        const Vector3 intersect = ray.at(t);
                        const Vector3 normal = sphere.getNormalAt(intersect);

                        // Only accounts for one light
                        Vector3 surfaceColor = ray.computeSurfaceColor(NUM_RECURSIONS, intersect, normal,
                                                               scene.getAmbientLight(), sphere.getSphereMaterial());
                        screen.setPixelColor(x, y, surfaceColor.getX(), surfaceColor.getY(), surfaceColor.getZ());
                    }
                }

                // Check for intersections with triangles
                for (const Triangle& triangle : scene.getTriangles()) {
                    const double t = ray.hitTriangle(triangle);
                    if (t < lowestT && t > MIN_CLIPPING_DISTANCE) {
                        lowestT = t;
                        const Vector3 intersect = ray.at(t);

                        // Only accounts for one light
                        Vector3 surfaceColor = ray.computeSurfaceColor(NUM_RECURSIONS, intersect, triangle.getNormal(),
                                                               scene.getAmbientLight(), triangle.getTriangleMaterial());
                        screen.setPixelColor(x, y, surfaceColor.getX(), surfaceColor.getY(), surfaceColor.getZ());
                    }
                }

            }
        }
    }
};


#endif //PROGRAM5_RAYTRACER_H
