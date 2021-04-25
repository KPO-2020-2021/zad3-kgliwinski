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
       menu m;

       double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       }
       m.init_menu(a1);


}
