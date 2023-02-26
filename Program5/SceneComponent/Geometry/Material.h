//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_MATERIAL_H
#define PROGRAM5_MATERIAL_H


#include <vector>

class Material {
private:
    const double Kd;
    const double Ks;
    const double Ka;
    const std::vector<double> Od;
    const std::vector<double> Os;
    const double Kgls;

public:
    Material(const double Kd, const double Ks, const double Ka, const double OdR, const double OdG, const double OdB,
             const double OsR, const double OsG, const double OsB, const double Kgls) :
             Kd(Kd), Ks(Ks), Ka(Ka), Od{OdR, OdG, OdB}, Os{OsR, OsG, OsB}, Kgls(Kgls) {}

    double getKd() const {
        return Kd;
    }

    double getKs() const {
        return Ks;
    }

    double getKa() const {
        return Ka;
    }

    double getOdR() const {
        return Od.at(0);
    }

    double getOdG() const {
        return Od.at(1);
    }

    double getOdB() const {
        return Od.at(1);
    }

    double getOsR() const {
        return Os.at(0);
    }

    double getOsG() const {
        return Os.at(1);
    }

    double getOsB() const {
        return Os.at(1);
    }

    double getKgls() const {
        return Kgls;
    }
};


#endif //PROGRAM5_MATERIAL_H
