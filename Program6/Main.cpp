#include <iostream>
#include <fstream>
#include <cmath>
#include "Image/Screen.h"
#include "SceneComponent/Camera.h"
#include "Scene.h"
#include "RayTracer/RayTracer.h"
#include "Vector3.h"
#include "SceneComponent/Light/LightDirectional.h"
#include "SceneComponent/Geometry/Triangle.h"

void renderScene1(Screen& screen, Scene& scene);

int main() {
    std::string outputFileName;
    std:: cout << "Enter output file name:";
    std::cin >> outputFileName;
    outputFileName += ".ppm";

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    // Scene 1
    const size_t image_width = 512;
    const size_t image_height = 512;

    Camera camera(60, Vector3(0, 0, 1), Vector3(0, 0, 0));
    Scene scene(51, 51, 51, camera, Vector3(0, 0, 0));
    Screen screen(image_width, image_height, scene.getSkyColorR(), scene.getSkyColorG(), scene.getSkyColorB());
    renderScene1(screen, scene);

    // Output
    outputFile << "P3" << std::endl;  // ASCII file
    outputFile << screen.getWidth() << " " << screen.getHeight() << std::endl;  // Number of columns and rows
    outputFile << "255" << std::endl;  // Maximum color value
    outputFile << screen << std::endl;  // Pixel values

    return 0;
}

void renderScene1(Screen& screen, Scene& scene) {
    const LightDirectional light(Vector3(1, 1, 1), Vector3(0, 1000, 0), Vector3(0, -1, 0));
    scene.addLight(light);

    Material sphereMaterial(0, 0.1, 0.1, 0.75, 0.75, 0.75, 1, 1, 1, 10, 0.9);
    Sphere sphere(sphereMaterial, 0.25, Vector3(0, 0.3, -1));
    scene.addSphere(sphere);

    Material blueTriangleMaterial(0.9, 1, 0.1, 0, 0, 1, 1, 1, 1, 4, 0);
    Triangle blueTriangle(blueTriangleMaterial, Vector3(0, -0.7, -0.5), Vector3(1, 0.4, -1),
                          Vector3(0, -0.7, -1.5));
    scene.addTriangle(blueTriangle);

    Material yellowTriangleMaterial(0.9, 1, 0.1, 1, 1, 0, 1, 1, 1, 4, 0);
    Triangle yellowTriangle(yellowTriangleMaterial, Vector3(0, -0.7, -0.5), Vector3(0, -0.7, -1.5),
                            Vector3(-1, 0.4, -1));
    scene.addTriangle(yellowTriangle);

    RayTracer rayTracer(screen, scene);
    rayTracer.render();
}
