#pragma once

#include "vector.hh"
#include "size.hh"
#include "lacze_do_gnuplota.hh"
#include <fstream>
#include <iostream>
#include <iomanip>


/*!
 * \file  rectangle.hh
 *  
 *  Plik zawiera definicję klasy reprezentujacej prostokat
 *  w przestrzeni dwuwymiarowej
 */



/*! \class Rectangle
 *  \brief Opisuje prostokat w przestrzeni dwuwymiarowej
 */
class Rectangle{

Vector top[4]; //wierzcholki prostokata

public:
//konstruktor bezparametryczny
Rectangle(); 
//konstruktor parametryczny
Rectangle(Vector const (&tab)[4]); 
//destruktor bezparametrryczny
~Rectangle();   
//metoda translacji (z zadanym wektorem)
Rectangle translation(Vector const &tran) const; 
//metoda translacji (pyta o wektor)
Rectangle translation() const; 
//metoda obrotu (z zadanym katem)
Rectangle rotate(const double &theta) const; 
//metoda obrotu (pyta o kat)
Rectangle rotate() const;   
//zwraca prostokat
void get_rect( Vector ((&tab)[4])) const;   
//sprawdza dlugosci przeciwnych bokow
bool check_len_opp(Vector const (&vecs)[4]) const;  
 //sprawdza katy wewnetrzne
bool check_angle_rec(Vector const (&vecs)[4]) const;   
//sprawdza czy katy proste
bool check_angle_straight(double ang) const;    
//sprawdza katy i boki
bool check_rec() const; 
//zapisuje wierzcholki do wyjscia
void RectangleToStdout(std::ostream &StrmWy);   
//obraca n razy
Rectangle rotation_n_times();   
//zapisuje wierzcholki do pliku
bool RectangleToFile(const char *sNazwaPliku);  
//wyswietla w gnuplocie
void PrintRectangle();  
};

std::ostream &operator<<(std::ostream &out,  Rectangle const &Rec); //przeciazenie wyjscia