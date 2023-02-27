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
    unsigned char skyColorR;
    unsigned char skyColorG;
    unsigned char skyColorB;

    const Camera camera;
    std::vector<Sphere> spheres;

public:
    Scene() : skyColorR(127), skyColorG(127), skyColorB(127), camera() {}

    Scene(const unsigned char skyColorR, const unsigned char skyColorG, const unsigned char skyColorB, Camera& camera) :
          skyColorR(skyColorR), skyColorG(skyColorG), skyColorB(skyColorB), camera(camera) {}

    unsigned char getSkyColorR() const {
        return skyColorR;
    }

    unsigned char getSkyColorG() const {
        return skyColorG;
    }

    unsigned char getSkyColorB() const {
        return skyColorB;
    }

    const Camera &getCamera() const {
        return camera;
    }

    const std::vector<Sphere>& getSpheres() const {
        return spheres;
    }

    void addSphere(const Sphere& sphere) {
        spheres.push_back(sphere);
    }
};


#endif //PROGRAM5_SCENE_H
