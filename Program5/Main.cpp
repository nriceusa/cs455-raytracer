#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>
#include "Image/Screen.h"
#include "SceneComponent/Camera.h"
#include "Scene.h"
#include "RayTracer.h"
#include "Vector3.h"


int main() {
    std::string outputFileName;
    std:: cout << "Enter output file name:";
    std::cin >> outputFileName;
    outputFileName += ".ppm";

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    const size_t image_width = 256;
    const size_t image_height = 256;

    Camera camera(90, Vector3(0, 0, 1), Vector3(0, 0, 0));
    Scene scene(51, 51, 51, camera);

    Material sphereMaterial(0.7, 0.2, 0.1, 1, 0, 1, 1, 1, 1, 16);
    Sphere sphere(sphereMaterial, 0.4, Vector3(0, 0, 0));
    scene.addSphere(sphere);

    Screen screen(image_width, image_height);
    RayTracer rayTracer(screen, scene);

    rayTracer.render();

//    Vector3 vector(0, 1, 2);
//    std::cout << "Vector tests: " << vector << std::endl;
//    std::cout << vector * vector << std::endl;  // TODO: Just testing Vector3

    // Output
    outputFile << "P3" << std::endl;  // ASCII file
    outputFile << screen.getWidth() << " " << screen.getHeight() << std::endl;  // Number of columns and rows
    outputFile << "255" << std::endl;  // Maximum color value
    outputFile << screen << std::endl;  // Pixel values

    return 0;
}