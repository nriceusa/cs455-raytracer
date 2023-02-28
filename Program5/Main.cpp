#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>
#include "Image/Screen.h"
#include "SceneComponent/Camera.h"
#include "Scene.h"
#include "RayTracer.h"
#include "Vector3.h"
#include "SceneComponent/LightDirectional.h"

void renderScene1(Screen& screen, Scene& scene);
void renderScene2(Screen& screen, Scene& scene);

int main() {
    std::string outputFileName;
    std:: cout << "Enter output file name:";
    std::cin >> outputFileName;
    outputFileName += ".ppm";

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    const size_t image_width = 512;
    const size_t image_height = 512;

    Camera camera(60, Vector3(0, 0, 1), Vector3(0, 0, 0));

    // Scene 1
//    Scene scene(51, 51, 51, camera, Vector3(0, 0, 0));
//    Screen screen(image_width, image_height, scene.getSkyColorR(), scene.getSkyColorG(), scene.getSkyColorG());
//    renderScene1(screen, scene);

    // Scene 2
    Scene scene(51, 51, 51, camera, Vector3(0.2, 0.2, 0.2));
    Screen screen(image_width, image_height, scene.getSkyColorR(), scene.getSkyColorG(), scene.getSkyColorG());
    renderScene2(screen, scene);

    // Output
    outputFile << "P3" << std::endl;  // ASCII file
    outputFile << screen.getWidth() << " " << screen.getHeight() << std::endl;  // Number of columns and rows
    outputFile << "255" << std::endl;  // Maximum color value
    outputFile << screen << std::endl;  // Pixel values

    return 0;
}

void renderScene1(Screen& screen, Scene& scene) {
    const LightDirectional light(Vector3(1, 1, 1), Vector3(0, 5, 0), Vector3(0, -1, 0));
    scene.addLight(light);

    Material sphereMaterial(0.7, 0.2, 0.1, 1, 0, 1, 1, 1, 1, 16);
    Sphere sphere(sphereMaterial, 0.4, Vector3(0, 0, 0));
    scene.addSphere(sphere);

    RayTracer rayTracer(screen, scene);
    rayTracer.render();
}

void renderScene2(Screen& screen, Scene& scene) {
    LightDirectional light(Vector3(1, 1, 1), Vector3(5, 5, 5), Vector3(0, -1, 0));
    scene.addLight(light);

    Material whiteMaterial(0.8, 0.1, 0.3, 1, 1, 1, 1, 1, 1, 4);
    Material redMaterial(0.6, 0.3, 0.1, 1, 0, 0, 1, 1, 1, 32);
    Material greenMaterial(0.7, 0.2, 0.1, 0, 1, 0, 0.5, 1, 0.5, 64);
    Material blueMaterial(0.9, 0, 0.1, 0, 0, 1, 1, 1, 1, 16);

    Sphere sphereWhite(whiteMaterial, 0.15, Vector3(0.45, 0, -0.15));
    Sphere redSphere(redMaterial, 0.2, Vector3(0, 0, -0.1));
    Sphere greenSphere(greenMaterial, 0.3, Vector3(-0.6, 0, 0));
    Sphere blueSphere(blueMaterial, 10000, Vector3(0, -10000.5, 0));

    scene.addSphere(blueSphere);
    scene.addSphere(sphereWhite);
    scene.addSphere(redSphere);
    scene.addSphere(greenSphere);

    RayTracer rayTracer(screen, scene);
    rayTracer.render();
}