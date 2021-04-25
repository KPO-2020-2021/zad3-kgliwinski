#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
/*!
 * \file  matrix.hh
 *  
 *  Plik zawiera definicję klasy reprezentujacej macierz
 *  o wymiarach SIZExSIZE
 */



/*! \class Matrix
 *  \brief Opisuje macierz nxn
 */
class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    ~Matrix();                              // Destruktor klasy

    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    Matrix operator - (Matrix tmp);

    bool operator == (Matrix const &tmp) const;

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;

    Matrix gauss() const;

    double determinant() const;
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);



