#pragma once

#include "size.hh"

#include <iostream>
#include <cmath>
#include <iomanip>
class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    ~Vector();

    Vector operator + (const Vector &v) const;

    Vector operator - (const Vector &v) const;

    Vector operator * (const double &tmp) const;

    Vector operator / (const double &tmp) const;

    Vector rotate(const double &theta) const;

    double modulus2() const;

    double get_len() const;

    double get_slope_angle() const;

    const double &operator [] (int index) const;

    double &operator [] (int index);

};


std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);