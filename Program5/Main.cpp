#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>
#include "SceneComponent/SceneComponent.h"
#include "Image/Screen.h"


int main() {
    std::string outputFileName;
    std:: cout << "Enter output file name:";
    std::cin >> outputFileName;
    outputFileName += ".ppm";

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    Pixel pixel(65, 66, 67);
    std::cout << pixel << std::endl << std::endl;

    Screen screen(8, 8);
    screen.setPixel(0, 1, pixel);

    // Output
    outputFile << "P3" << std::endl;  // ASCII file
    outputFile << screen.getWidth() << " " << screen.getHeight() << std::endl;  // Number of columns and rows
    outputFile << "255" << std::endl;  // Maximum color value
    outputFile << screen << std::endl;  // Pixel values

    return 0;
}