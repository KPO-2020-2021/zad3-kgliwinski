#pragma once

#include "vector.hh"
#include "size.hh"
#include <iostream>
class Rectangle{

Vector a,b,c,d; //wierzcholki prostokata

public:
Rectangle();

Rectangle(Vector const &aX, Vector const &bX, Vector const &cX, Vector const &dX);

Rectangle translation(Vector const &tran) ;

Rectangle rotate(const double &theta) ;

void get_rect( Vector &aX, Vector &bX, Vector &cX, Vector &dX) const;

bool check_len() const;

bool check_angle() const;
};

std::ostream &operator<<(std::ostream &out,  Rectangle const &Rec);