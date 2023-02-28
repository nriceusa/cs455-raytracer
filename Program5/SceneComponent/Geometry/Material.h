//
// Created by Nathan Rice on 2/25/2023.
//

#ifndef PROGRAM5_MATERIAL_H
#define PROGRAM5_MATERIAL_H


class Material {
private:
    const double Kd;
    const double Ks;
    const double Ka;
    const Vector3 Od;
    const Vector3 Os;
    const double Kgls;

public:
    Material(const double Kd, const double Ks, const double Ka, const double OdR, const double OdG, const double OdB,
             const double OsR, const double OsG, const double OsB, const double Kgls) :
             Kd(Kd), Ks(Ks), Ka(Ka), Od(OdR, OdG, OdB), Os(OsR, OsG, OsB), Kgls(Kgls) {}

    double getKd() const {
        return Kd;
    }

    double getKs() const {
        return Ks;
    }

    double getKa() const {
        return Ka;
    }

    const Vector3 &getOd() const {
        return Od;
    }

    const Vector3 &getOs() const {
        return Os;
    }

    double getKgls() const {
        return Kgls;
    }
};


#endif //PROGRAM5_MATERIAL_H
