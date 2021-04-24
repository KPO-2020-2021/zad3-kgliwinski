#pragma once

#include "vector.hh"
#include "size.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
class Rectangle{

Vector top[4]; //wierzcholki prostokata

public:
Rectangle();

Rectangle(Vector const (&tab)[4]);

~Rectangle();

Rectangle translation(Vector const &tran) const;

Rectangle rotate(const double &theta) const;

void get_rect( Vector ((&tab)[4])) const;

bool check_len_opp(Vector const (&vecs)[4]) const;

bool check_angle_rec(Vector const (&vecs)[4]) const;

bool check_angle_straight(double ang) const;

bool check_rec() const;

void RectangleToStdout(std::ostream &StrmWy);

Rectangle rotation_n_times();

bool RectangleToFile(const char *sNazwaPliku);
};

std::ostream &operator<<(std::ostream &out,  Rectangle const &Rec);