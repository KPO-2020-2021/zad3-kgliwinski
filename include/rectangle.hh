#pragma once

#include "vector.hh"
#include "size.hh"
#include <iostream>
class Rectangle{

Vector a,b,c,d; //wierzcholki prostokata

public:
Rectangle();

Rectangle(Vector const &aX, Vector const &bX, Vector const &cX, Vector const &dX);

Rectangle translation(Vector const &tran) const;

Rectangle rotate(const double &theta) const;

void get_rect( Vector &aX, Vector &bX, Vector &cX, Vector &dX) const;

bool check_len_opp() const;

bool check_angle_opp() const;
};

std::ostream &operator<<(std::ostream &out,  Rectangle const &Rec);