//
// Created by dot_blue on 3/25/19.
//

#pragma once

#include <ostream>
#include "Geom.h"


struct Ang {

    double rad();
    double deg();
    double tan();
    double slope();

    void setDeg(double deg);
    void setRad(double rad);

    Ang operator+(Ang _secAng) const;
    Ang operator+(double deg) const;
    Ang operator-(Ang _secAng) const;
    Ang operator-(double deg) const;
    double operator^(double deg);

    friend std::ostream &operator<< ( std::ostream & oo , const Ang & _deg ) {
        oo << "Ang: " << _deg._deg << std::endl;
        return oo;
    }

    Ang() = default;
private:
    double _deg = 0.0;

    double normalizeDeg(double deg);
    double normalizeRad(double rad);
};

Ang angDeg(double deg);
Ang angRad(double rad);
