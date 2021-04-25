// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "../include/vector.hh"
#include "../include/matrix.hh"
#include "../include/vector.hh"
#include "../include/menu.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150


int main()
{
       std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
                 << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
                 << "."
                 << PROJECT_VERSION_MINOR /* istotne zmiany */
                 << "."
                 << PROJECT_VERSION_PATCH /* naprawianie bugów */
                 << "."
                 << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
                 << std::endl <<std::endl;
       // std::system("cat ../LICENSE");
       // do zadania Rotacja 2D
       /* std::cout << "Vector:" << std::endl;
       Vector tmpV1 = Vector();
       
       std::cout << "Vector - konstruktor bezparametryczny:\n"
                 << tmpV1 << std::endl;
       double argumentsV[] = {0.000000001, 0.000000002};
       Vector tmpV2 = Vector(argumentsV);
       
       std::cout << "Vector - konstruktor parametryczny:\n"
                 << tmpV2 << std::endl;

       
       std::cout << "Matrix:" << std::endl;
       Matrix tmpM1 = Matrix();

       std::cout << "Matrix - konstruktor bezparametryczny:\n"
                 << tmpM1 << std::endl;
       double argumentsM[][SIZE] = {{1.0, 2.0}, {3.0, 4.0}};
       Matrix tmpM2 = Matrix(argumentsM);
       
       std::cout << "Matrix - konstruktor parametryczny:\n"
                 << tmpM2 << std::endl;

       Rectangle tmpR1;
       
       std::cout << "Rectangle - konstruktor bezparametryczny:\n"
                 << tmpR1 << std::endl;
       double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       }
       Rectangle tmpR2(a1);
       
       std::cout << "Rectangle - konstruktor parametryczny:\n"
                 << tmpR2 << std::endl;

       double tmpargs[2] = {3.0, 4.0};
       Vector tmpV3(tmpargs);
       double length;
       length = tmpV3.get_len();
       
       std::cout << "Dlugosc wektora " << std::endl << tmpV3 << " wynosi " << length << std::endl;

       Vector tmpV3_rotated;
       double z = 180.0;
       tmpV3_rotated = tmpV3.rotate(z);

       std::cout << "Obrocony wektor o " << z << " stopni" << std::endl << tmpV3 << " to " << std::endl << tmpV3_rotated;
       */
       //Rectangle tmpRn = tmpR2.rotation_n_times();

       menu m;

       double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       }
       m.init_menu(a1);


       // Z bazy projektu-wydmuszki Boiler Plate C++:
       // Bring in the dummy class from the example source,
       // just to show that it is accessible from main.cpp.
       Dummy d = Dummy();
       return d.doSomething() ? 0 : -1;
}
