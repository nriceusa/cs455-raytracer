#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "SceneComponent/SceneComponent.h"
#include "Screen.h"


int main() {
    Pixel pixel(65, 66, 67);
    std::cout << pixel << std::endl << std::endl;

    Screen screen(4, 4);
    screen.setPixel(0, 1, pixel);

    // Output
    std::cout << "P3" << std::endl;  // ASCII file
    std::cout << screen.getWidth() << " " << screen.getHeight() << std::endl;  // Number of columns and rows
    std::cout << "255" << std::endl;  // Maximum color value
    std::cout << screen << std::endl;  // Pixel values

    return 0;
}