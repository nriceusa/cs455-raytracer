//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_SCENE_H
#define PROGRAM5_SCENE_H


#include <vector>
#include "SceneComponent/Camera.h"
#include "SceneComponent/Geometry/Sphere.h"
#include "SceneComponent/Light/Light.h"

class Scene {
private:
    unsigned char skyColorR;
    unsigned char skyColorG;
    unsigned char skyColorB;

    const Camera camera;
    std::vector<Sphere> spheres;
    std::vector<Light> lights;
    Vector3 ambientLight;

public:
    Scene() : skyColorR(127), skyColorG(127), skyColorB(127), camera(), ambientLight(0, 0, 0) {}

    Scene(const unsigned char skyColorR, const unsigned char skyColorG, const unsigned char skyColorB,
          Camera& camera, const Vector3& ambientLight) :
          skyColorR(skyColorR), skyColorG(skyColorG), skyColorB(skyColorB), camera(camera), ambientLight(ambientLight) {}

    unsigned char getSkyColorR() const {
        return skyColorR;
    }

    unsigned char getSkyColorG() const {
        return skyColorG;
    }

    unsigned char getSkyColorB() const {
        return skyColorB;
    }

    Vector3 getAmbientLight() const {
        return Vector3{static_cast<double>(skyColorR) / 255,
                       static_cast<double>(skyColorG) / 255,
                       static_cast<double>(skyColorB) / 255};
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

    const std::vector<Light>& getLights() const {
        return lights;
    }

    void addLight(const Light& light) {
        lights.push_back(light);
    }
};


#endif //PROGRAM5_SCENE_H
