//
// Created by dot_blue on 3/25/19.
//

#include "Angle.h"


double Ang::rad() {
    return Deg2Rad(_deg);
}

double Ang::deg() {
    return this->_deg;
}

double Ang::tan() {
    return tanDeg(_deg);
}

double Ang::slope() {
    return tan();
}

//Ang::operator AngRad() {
//    return _rad;
//}
//
//Ang::operator AngDeg() {
//    return deg();
//}

void Ang::setDeg(double deg) {
    deg = normalizeDeg(deg);
    this->_deg = deg;
}

void Ang::setRad(double rad) {
    rad = normalizeRad(rad);
    this->_deg = Rad2Deg(rad);
}

double Ang::normalizeDeg(double deg) {
    while(deg > 180)
        deg -= 360;
    while(deg < -180)
        deg += 360;

    return deg;
}

double Ang::normalizeRad(double rad) {
    while(rad > M_PI)
        rad -= 2*M_PI;
    while(rad < -M_PI)
        rad += 2*M_PI;

    return rad;
}

Ang Ang::operator+(Ang _secAng) const{
    return angDeg(this->_deg + _secAng._deg);
}

Ang Ang::operator+(double deg) const{
    return angDeg(this->_deg + deg);
}

Ang Ang::operator-(Ang _secAng) const {
    return angDeg(this->_deg - _secAng._deg);
}

Ang Ang::operator-(double deg) const {
    return angDeg(this->_deg - deg);
}

//This operator gives the difference in a positive number
double Ang::operator^(double deg) {
    deg = normalizeDeg(this->_deg - deg);
    return abs(deg);
}

Ang angDeg(double deg) {
    Ang _ang;
    _ang.setDeg(deg);
    return _ang;
}

Ang angRad(double rad) {
    Ang _ang;
    _ang.setRad(rad);
    return _ang;
}
