//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_RAYTRACER_H
#define PROGRAM5_RAYTRACER_H


#include <cmath>
#include <iostream>
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
        Vector3 rayVector = (scene.getCamera().getTarget() - scene.getCamera().getOrigin());

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

                // Check for intersections with spheres
                for (const Sphere& sphere : scene.getSpheres()) {
                    double t = ray.hitSphere(sphere);
                    if (t > 0) {
                        const Vector3 intersect = ray.at(t);
                        const Vector3 normal = (intersect - sphere.getCenter()) / sphere.getRadius();
//                        screen.setPixelColor(x, y, 0.5 * (normal.getX() + 1), 0.5 * (normal.getY() + 1), 0.5 * (normal.getZ() + 1));

                        // Only accounts for one light
                        Vector3 surfaceColor = ray.computeSurfaceColor(intersect, normal, scene.getAmbientLight(),
                                                                       sphere.getSphereMaterial(),
                                                                       scene.getLights().at(0));
                        screen.setPixelColor(x, y, surfaceColor.getX(), surfaceColor.getY(), surfaceColor.getZ());
                    }
                }

                // Check for intersections with triangles
                for (const Triangle& triangle : scene.getTriangles()) {
                    if (ray.hitTriangle(triangle)) {
                        screen.setPixelColor(x, y, 1, 0, 0);
                    }
                }
            }
        }
    }
};


#endif //PROGRAM5_RAYTRACER_H
