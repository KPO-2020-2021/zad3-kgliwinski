#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"../tests/doctest/doctest.h"

#include"../include/menu.hh"


// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.


TEST_CASE("V 1.01: Vector konstruktor bezparametryczny oraz przeciazenie strumienia wyjsciowego<<"){
Vector a;

    std::ostringstream out;
    out << a; // 

    CHECK("[ 0.0000000000 ]\n[ 0.0000000000 ]\n" == out.str());
}


TEST_CASE("V 1.02: Vector konstruktor parametryczny oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>"){
    Vector a;
    std::istringstream in("1.0 5.0");
    in >> a;
    std::ostringstream out;
    out << a; // 

    CHECK("[ 1.0000000000 ]\n[ 5.0000000000 ]\n" == out.str());
}

TEST_CASE("V 1.03: Vector konstruktor parametryczny dla malych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>"){
    Vector a;
    std::istringstream in("0.0000000001 0.0000000005");
    in >> a;
    std::ostringstream out;
    out << a; // 

    CHECK("[ 0.0000000001 ]\n[ 0.0000000005 ]\n" == out.str());
}

TEST_CASE("V 1.04: Vector konstruktor parametryczny dla duzych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>"){
    Vector a;
    std::istringstream in("12345678 12345678");
    in >> a;
    std::ostringstream out;
    out << a; // 

    CHECK("[ 12345678.0000000000 ]\n[ 12345678.0000000000 ]\n" == out.str());
}

TEST_CASE("V 2.01: Vector dodawanie wektorow"){
    double tab[3][2] = {{4,2},{2,7}, {6,9}};
    Vector a(tab[0]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 2.02: Vector dodawanie wektorow dla malych wartosci"){
    double tab[3][2] = {{0.0000000004,0.0000000002},{0.0000000002,0.0000000007}, {0.0000000006,0.0000000009}};
    Vector a(tab[0]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 2.03: Vector dodawanie wektorow dla malych wartosci (dokladnosc ponizej E-10)"){
    double tab[3][2] = {{0.00000000004,0.00000000002},{0.00000000002,0.00000000007}, {0.00000000006,0.00000000009}};
    Vector a(tab[0]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 2.04: Vector dodawanie wektorow dla duzych wartosci, granicze wartosci"){
    double tab[3][2] = {{99999,99999},{1,1},{100000,100000}};
    Vector a(tab[0]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 3.01: Vector odejmowanie wektorow"){
    double tab[3][2] = {{4,2},{2,7}, {2,-5}};
    Vector a(tab[0]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("V 3.02: Vector odejmowanie wektorow dla malych wartosci"){
    double tab[3][2] = {{0.0000000004,0.0000000002},{0.0000000002,0.0000000007}, {0.0000000002,-0.0000000005}};
    Vector a(tab[0]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("V 3.03: Vector odejmowanie wektorow dla malych wartosci (dokladnosc ponizej E-10)"){
    double tab[3][2] = {{0.00000000004,0.00000000002},{0.00000000002,0.00000000007}, {0.00000000004,-0.00000000005}};
    Vector a(tab[0]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("V 3.04: Vector odejmowanie wektorow dla duzych wartosci, granicze wartosci"){
    double tab[3][2] = {{99999,99999},{1,1},{100000,100000}};
    Vector a(tab[3]);
    Vector b(tab[1]);
    Vector res(tab[2]);

    Vector sum = a-b;
    CHECK(res == sum);
}

/*
    std::istringstream in("(1+10i)");
    in >> x;
    std::ostringstream out;
    out << a; // 
    */