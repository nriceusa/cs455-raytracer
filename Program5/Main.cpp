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

int main() {
    std::string outputFileName;
    std:: cout << "Enter output file name:";
    std::cin >> outputFileName;
    outputFileName += ".ppm";

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    const size_t image_width = 512;
    const size_t image_height = 512;

    // Scene 1
    Camera camera(60, Vector3(0, 0, 1), Vector3(0, 0, 0));
    Scene scene(51, 51, 51, camera);
    Screen screen(image_width, image_height, scene.getSkyColorR(), scene.getSkyColorG(), scene.getSkyColorG());
    renderScene1(screen, scene);

    // Output
    outputFile << "P3" << std::endl;  // ASCII file
    outputFile << screen.getWidth() << " " << screen.getHeight() << std::endl;  // Number of columns and rows
    outputFile << "255" << std::endl;  // Maximum color value
    outputFile << screen << std::endl;  // Pixel values

    return 0;
}

void renderScene1(Screen& screen, Scene& scene) {
    LightDirectional light(Vector3(1, 1, 1), Vector3(0, 5, 0), Vector3(0, -1, 0));
    scene.addLight(light);

    Material sphereMaterial(0.7, 0.2, 0.1, 1, 0, 1, 1, 1, 1, 16);
    Sphere sphere(sphereMaterial, 0.4, Vector3(0, 0, 0));
    scene.addSphere(sphere);

    RayTracer rayTracer(screen, scene);

    rayTracer.render();
}

void renderScene2(Screen& screen, Scene& scene) {

}