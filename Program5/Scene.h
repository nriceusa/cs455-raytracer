//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_SCENE_H
#define PROGRAM5_SCENE_H


#include <vector>
#include "SceneComponent/Camera.h"
#include "SceneComponent/Geometry/Sphere.h"

class Scene {
private:
    const std::vector<unsigned char> skyColor;

    const Camera camera;
    std::vector<Sphere> spheres;

public:
    Scene() : skyColor{127, 127, 127}, camera() {}

    Scene(const unsigned char skyColorR, const unsigned char skyColorG, const unsigned char skyColorB,
          Camera& camera) :
          skyColor{skyColorR, skyColorG, skyColorB}, camera(camera) {}

    const Camera &getCamera() const {
        return camera;
    }

    void addSphere(const Sphere& sphere) {
        spheres.push_back(sphere);
    }
};


#endif //PROGRAM5_SCENE_H
