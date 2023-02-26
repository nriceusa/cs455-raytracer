//
// Created by Nathan Rice on 2/14/2023.
//

#ifndef PROGRAM5_RAY_H
#define PROGRAM5_RAY_H


#include <vector>

class Ray {
private:
    const std::vector<double> origin;
    const std::vector<double> direction;

public:
    Ray() : origin{0, 0, 0}, direction{0, 1, 0} {}

    Ray(const std::vector<double>& origin, const std::vector<double>& direction) :
        origin(origin), direction(direction) {}

    Ray(const double xOrigin, const double yOrigin, const double zOrigin) :
        origin{xOrigin, yOrigin, zOrigin}, direction{0, 1, 0} {}

    Ray(const double xOrigin, const double yOrigin, const double zOrigin,
        const double xDirection, const double yDirection, const double zDirection) :
        origin{xOrigin, yOrigin, zOrigin}, direction{xOrigin, yOrigin, zOrigin} {}

    const std::vector<double> &getOrigin() const {
        return origin;
    }

    const std::vector<double> &getDirection() const {
        return direction;
    }
};


#endif //PROGRAM5_RAY_H
