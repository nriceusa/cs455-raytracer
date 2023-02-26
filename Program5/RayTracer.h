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
    const Screen screen;
    const Scene scene;

public:
    RayTracer(Screen& screen, Scene& scene) : screen(screen), scene(scene) {}

    void render() {
        double cameraFov = scene.getCamera().getFov();

        double xDestination;
        double yDestination;
        double zDestination = (static_cast<double>(screen.getWidth()) / 2) / tan(scene.getCamera().getFov() / 2);
        for (size_t x = 0; x < screen.getWidth(); ++x) {
            xDestination = static_cast<double>(x) - (static_cast<double>(screen.getWidth()) / 2);

            for (size_t y = 0; y < screen.getHeight(); ++y) {
                yDestination = -(static_cast<double>(y) - static_cast<double>(screen.getHeight()) / 2);

                std::vector<double> rayDirection{xDestination, yDestination, zDestination};
                Ray ray(scene.getCamera().getLocation(), rayDirection);


            }
        }
    }
};


#endif //PROGRAM5_RAYTRACER_H
