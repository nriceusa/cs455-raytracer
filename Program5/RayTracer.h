//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_RAYTRACER_H
#define PROGRAM5_RAYTRACER_H


#include <cmath>
#include <iostream>
#include "Image/Screen.h"
#include "Scene.h"
#include "SceneComponent/Ray.h"

class RayTracer {
private:
    Screen& screen;
    const Scene& scene;

public:
    RayTracer(Screen& screen, const Scene& scene) : screen(screen), scene(scene) {}

    void render() {
        double cameraFov = scene.getCamera().getFov();

        Vector3 rayDestination(0, 0, 0);
        rayDestination.setZ((static_cast<double>(screen.getWidth()) / 2) /
                            tan(scene.getCamera().getFov() / 2));

        for (size_t x = 0; x < screen.getWidth(); ++x) {
            rayDestination.setX(static_cast<double>(x) - (static_cast<double>(screen.getWidth()) / 2));

            for (size_t y = 0; y < screen.getHeight(); ++y) {
                rayDestination.setY(-(static_cast<double>(y) - static_cast<double>(screen.getHeight()) / 2));

                Ray ray(scene.getCamera().getLocation(), rayDestination);
                for (const Sphere& sphere : scene.getSpheres()) {
                    double t = ray.hitSphere(sphere);
                    if (t > 0) {
                        Vector3 normal = Vector3::normalize(ray.at(t) - Vector3(0, 0, -1));  // TODO: implement at()
                        screen.setPixelColor(x, y, 0.5 * (normal.getX() + 1), 0.5 * (normal.getY() + 1), 0.5 * (normal.getZ() + 1));
                    } else {
                        screen.setPixelColor(x, y,
                                             scene.getSkyColorR(), scene.getSkyColorG(), scene.getSkyColorB());
                    }
                }
            }
        }
    }

};


#endif //PROGRAM5_RAYTRACER_H
