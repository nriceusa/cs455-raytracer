//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_SCREEN_H
#define PROGRAM5_SCREEN_H

#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 75

#include <vector>
#include <ostream>
#include "Pixel.h"

class Screen {
private:
    std::vector<std::vector<Pixel>> pixels;

public:
    Screen() :
        pixels(std::vector<std::vector<Pixel>>(DEFAULT_WIDTH, std::vector<Pixel>(DEFAULT_HEIGHT))) {}

    Screen(const size_t width, const size_t height) :
        pixels(std::vector<std::vector<Pixel>>(width, std::vector<Pixel>(height))) {}

    size_t getWidth() const {
        return pixels.capacity();
    }

    size_t getHeight() const {
        return pixels.at(0).capacity();
    }

    const Pixel &getPixel(const size_t &x, const size_t &y) {
        return pixels.at(x).at(y);
    }

    void setPixelColor(const size_t x, const size_t y, const double r, const double g, const double b) {
        pixels.at(x).at(y).setRGB(convertToChar(r), convertToChar(g), convertToChar(b));
    }

    static unsigned char convertToChar(const double value) {
        return static_cast<unsigned char>(value * 255);
    }

    friend std::ostream &operator<<(std::ostream &os, Screen& screen) {
        for (size_t y = 0; y < screen.getHeight(); ++y) {
            for (size_t x = 0; x < screen.getWidth(); ++x) {
                os << screen.getPixel(x, y) << "  ";
            }
            os << std::endl;
        }

        return os;
    }
};


#endif //PROGRAM5_SCREEN_H
