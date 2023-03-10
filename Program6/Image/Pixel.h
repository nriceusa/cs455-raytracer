//
// Created by Nathan Rice on 2/21/2023.
//

#ifndef PROGRAM5_PIXEL_H
#define PROGRAM5_PIXEL_H


#include <ostream>
#include <string>
#include <vector>

class Pixel {
private:
    unsigned char R;
    unsigned char G;
    unsigned char B;

public:
    Pixel() : R(0), G(0), B(0) {}

    Pixel(const unsigned char r, const unsigned char g, const unsigned char b) : R(r), G(g), B(b) {}

    float getR() const {
        return R;
    }

    void setR(unsigned char r) {
        R = r;
    }

    float getG() const {
        return G;
    }

    void setG(unsigned char g) {
        G = g;
    }

    float getB() const {
        return B;
    }

    void setB(unsigned char b) {
        B = b;
    }

    void setRGB(unsigned char r, unsigned char g, unsigned char b) {
        R = r;
        G = g;
        B = b;
    }

    friend std::ostream &operator<<(std::ostream &os, const Pixel &pixel) {
        os << std::to_string(pixel.R) << ' ' << std::to_string(pixel.G) << ' ' << std::to_string(pixel.B);
        return os;
    }
};


#endif //PROGRAM5_PIXEL_H
