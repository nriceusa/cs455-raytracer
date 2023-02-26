#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>
#include "Image/Screen.h"
#include "SceneComponent/Camera.h"
#include "Scene.h"
#include "RayTracer.h"


int main() {
    std::string outputFileName;
    std:: cout << "Enter output file name:";
    std::cin >> outputFileName;
    outputFileName += ".ppm";

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    const size_t image_width = 256;
    const size_t image_height = 128;

    Camera camera(90, 0, 0, 1, 0, 0, 0);
    Scene scene(51, 51, 51, camera);

    Material sphereMaterial(0.7, 0.2, 0.1, 1, 0, 1, 1, 1, 1, 16);
    Sphere sphere(sphereMaterial, 0.4, 0, 0, 0);
    scene.addSphere(sphere);

    Screen screen(image_width, image_height);
    RayTracer rayTracer(screen, scene);

    rayTracer.render();

    // Output
    outputFile << "P3" << std::endl;  // ASCII file
    outputFile << screen.getWidth() << " " << screen.getHeight() << std::endl;  // Number of columns and rows
    outputFile << "255" << std::endl;  // Maximum color value
    outputFile << screen << std::endl;  // Pixel values

    return 0;
}