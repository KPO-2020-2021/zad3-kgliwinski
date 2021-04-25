#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"../tests/doctest/doctest.h"

#include"../include/menu.hh"

/*********************************************************/
/*  FILE CONTAINS ALL TESTS FOR ALL CLASSES AND METHODS  */
/*********************************************************/

/*
Tests for vector class
*/

TEST_CASE("V 1.01: Vector konstruktor bezparametryczny oraz przeciazenie strumienia wyjsciowego<<"){
Vector a;

    std::ostringstream out;
    out << a; // 

    CHECK("[ 0.0000000000 ]\n[ 0.0000000000 ]\n" == out.str());
}


TEST_CASE("V 1.02: Vector konstruktor parametryczny oraz przeciazenie strumienia #include <cmath>wyjsciowego << i wejsciowego >>"){
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
    Vector a(tab[2]);
    Vector b(tab[0]);
    Vector res(tab[1]);

    Vector sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("V 4.01: Vector mnozenie wektorow przez skalar"){
    double tab[2][2] = {{4,2},{136,68}};
    double tmp;
    Vector a(tab[0]);
    tmp =34;
    Vector b = a*tmp;
    Vector res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 4.02: Vector mnozenie wektorow przez maly skalar"){
    double tab[2][2] = {{4,2},{0.000000004,0.0000000002}};
    double tmp;
    Vector a(tab[0]);
    tmp =0.000000001;
    Vector b = a*tmp;
    Vector res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 4.03: Vector mnozenie wektorow przez 0"){
    double tab[2][2] = {{4,2},{0,0}};
    double tmp;
    Vector a(tab[0]);
    tmp =0;
    Vector b = a*tmp;
    Vector res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 4.04: Vector mnozenie wektora zerowego przez skalar"){
    double tab[2][2] = {{0,0},{0,0}};
    double tmp;
    Vector a(tab[0]);
    tmp =1231234;
    Vector b = a*tmp;
    Vector res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 5.01: Vector dzielenie wektorow przez skalar"){
    double tab[2][2] = {{4,2},{2,1}};
    double tmp;
    Vector a(tab[0]);
    tmp =2;
    Vector b = a/tmp;
    Vector res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 5.02: Vector dzielenie wektorow przez maly skalar"){
    double tab[2][2] = {{4,2},{40000000000,20000000000}};
    double tmp;
    Vector a(tab[0]);
    tmp =0.000000001;
    Vector b = a/tmp;
    Vector res(tab[1]);

        CHECK(!(a == b));

}

TEST_CASE("V 5.03: Vector dzielenie wektorow przez 0"){
    double tab[2][2] = {{4,2},{4,2}};
    double tmp;
    Vector a(tab[0]);
    tmp =0;
    Vector b = a/tmp;
    Vector res(tab[1]);

    CHECK(res == b);    //nothing happened
}

TEST_CASE("V 5.04: Vector dzielenie wektora zerowego przez skalar"){
    double tab[2][2] = {{0,0},{0,0}};
    double tmp;
    Vector a(tab[0]);
    tmp =1231234;
    Vector b = a*tmp;
    Vector res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("V 6.01: Vector::rotate"){
    double tab[2][2] = {{3,4},{-4,3}};
    double ang;
    Vector a(tab[0]);
    ang =90;
    Vector b = a.rotate(ang);
    Vector res(tab[1]);
    
        CHECK((res == b));
}

TEST_CASE("V 6.02: Vector::rotate by 0"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector a(tab[0]);
    ang =0;
    Vector b = a.rotate(ang);
    Vector res(tab[1]);

        CHECK((res == b));
}


TEST_CASE("V 6.03: Vector::rotate by 360 deg"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector a(tab[0]);
    ang =360;
    Vector b = a.rotate(ang);
    Vector res(tab[1]);
    
        CHECK((res == b));
}


TEST_CASE("V 6.04: Vector::rotate by 36000000 deg"){
    double tab[2][2] = {{3,4},{3,4}};
    double ang;
    Vector a(tab[0]);
    ang =36000000;
    Vector b = a.rotate(ang);
    Vector res(tab[1]);
    
        CHECK((res == b));
}

TEST_CASE("V 6.05: Vector::rotate by 180 deg"){
    double tab[2][2] = {{3,4},{-3,-4}};
    double ang;
    Vector a(tab[0]);
    ang =180;
    Vector b = a.rotate(ang);
    Vector res(tab[1]);
    
        CHECK((res == b));
}


TEST_CASE("V 7.01: Vector::modulus2"){
    double tab[2][2] = {{3,4}};
    double res;
    Vector a(tab[0]);
    res = 25;
    
        CHECK((res == a.modulus2()));
}

TEST_CASE("V 7.02: Vector::modulus2 small"){
    double tab[2][2] = {{0.003,0.004}};
    double res;
    Vector a(tab[0]);
    res = 0.000025;

        CHECK((abs(res - a.modulus2())<=0.0001));
}

TEST_CASE("V 7.03: Vector::modulus2 zero"){
    double tab[2][2] = {{0,0}};
    double res;
    Vector a(tab[0]);
    res = 0;
    
        CHECK((res == a.modulus2()));
}

TEST_CASE("V 7.04: Vector::modulus2 neg"){
    double tab[2][2] = {{-3,-4}};
    double res;
    Vector a(tab[0]);
    res = 25;
    
        CHECK((res == a.modulus2()));
}

TEST_CASE("V 8.01: Vector::get_len "){
    double tab[2][2] = {{3,4}};
    double res;
    Vector a(tab[0]);
    res = 5;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 8.02: Vector::get_len small"){
    double tab[2][2] = {{0.003,0.004}};
    double res;
    Vector a(tab[0]);
    res = 0.005;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 8.03: Vector::get_len zero"){
    double tab[2][2] = {{0,0}};
    double res;
    Vector a(tab[0]);
    res = 0;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 8.04: Vector::get_len neg"){
    double tab[2][2] = {{-5,-12}};
    double res;
    Vector a(tab[0]);
    res = 13;
    
        CHECK((res == a.get_len()));
}

TEST_CASE("V 9.01: Vector::get_slope_angle "){
    double tab[2][2] = {{1,1}};
    double res;
    Vector a(tab[0]);
    res = 45.0;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 9.02: Vector::get_slope_angle 0"){
    double tab[2][2] = {{0,0}};
    double res;
    Vector a(tab[0]);
    res = 0;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 9.03: Vector::get_slope_angle 90 deg"){
    double tab[2][2] = {{0,1}};
    double res;
    Vector a(tab[0]);
    res = 90;

    CHECK (abs(res - a.get_slope_angle())<= 0.000001);
}

TEST_CASE("V 10.01: operator []"){
    double tab[2][2] = {{3,1}};
    double res;
    Vector a(tab[0]);
    res = 3;

    CHECK (abs(res - a[0])<= 0.000001);
}

TEST_CASE("V 10.02: operator []"){
    double tab[2][2] = {{3,1}};
    double res;
    Vector a(tab[0]);
    res = 1;

    CHECK (abs(res - a[1])<= 0.000001);
}

TEST_CASE("V 10.03: operator const []"){
    double tab[2][2] = {{3,1}};
    double res;
    Vector a(tab[0]);
    res = 1;

    double b = a[1];
    CHECK (abs(res - b)<= 0.000001);
}

TEST_CASE("M 1.01: konstruktor bezparametryczny i przeciazenie operatorow << >>"){
    //double tab[2][2] = {{3,1}};
    Matrix a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * ");
}

TEST_CASE("M 1.02: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{3,1},{3,1}};
    Matrix a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 3.0000000000 * | 1.0000000000 * | 3.0000000000 * | 1.0000000000 * ");
}

TEST_CASE("M 1.03: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{0.0003,0.0001},{0.0003,0.0001}};
    Matrix a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0003000000 * | 0.0001000000 * | 0.0003000000 * | 0.0001000000 * ");
}

TEST_CASE("M 1.04: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{-0.0003,0.0001},{0.0003,-0.0001}};
    Matrix a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| -0.0003000000 * | 0.0001000000 * | 0.0003000000 * | -0.0001000000 * ");
}

TEST_CASE("M 1.05: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{0,0},{0,0}};
    Matrix a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.06:  przeciazenie operatorow << >>"){
    double tab[2][2] = {{0,0},{0,0}};
    Matrix a(tab);
    std::istringstream in("1 2 3 4");
    in >> a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 2.0000000000 * | 3.0000000000 * | 4.0000000000 * ");
}

TEST_CASE("M 2.01: operator * (vector)"){
    double tab[2][2] = {{1,0},{0,1}};
    double vec[2] = {1,2};
    Matrix a(tab);
    Vector b(vec);

    Vector c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("M 2.02: operator * (vector) zero"){
    double tab[2][2] = {{0,0},{0,0}};
    double vec[2] = {0,0};
    Matrix a(tab);
    Vector b(vec);

    Vector c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("M 2.03: operator * (vector) neg"){
    double tab[2][2] = {{1,2},{3,4}};
    double vec[2] = {1,-1};
    double res[2] = {-1,-1};
    Matrix a(tab);
    Vector b(vec);

    Vector c(res);

    CHECK (c==(a*b));
}

TEST_CASE("M 3.01: operator +"){
    double tab[2][2] = {{1,2},{3,4}};
    double tab2[2][2] = {{4,3},{2,1}};
    double res[2][2] = {{5,5},{5,5}};

    Matrix a(tab);
    Matrix b(tab2);

    Matrix c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 3.02: operator + 0"){
    double tab[2][2] = {{1,2},{3,4}};
    double tab2[2][2] = {{0,0},{0,0}};
    double res[2][2] = {{1,2},{3,4}};

    Matrix a(tab);
    Matrix b(tab2);

    Matrix c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 3.03: operator + small"){
    double tab[2][2] = {{1,2},{3,4}};
    double tab2[2][2] = {{0.0000000001,0.0000000001},{0.0000000001,0.0000000001}};
    double res[2][2] = {{1.0000000001,2.0000000001},{3.0000000001,4.0000000001}};

    Matrix a(tab);
    Matrix b(tab2);

    Matrix c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 4.01: operator ()"){
    double tab[2][2] = {{1,2},{3,4}};
    double res = 1;

    Matrix a(tab);

    CHECK (res == a(0,0));
}

TEST_CASE("M 4.02: operator ()"){
    double tab[2][2] = {{1,0.00002},{3,4}};
    double res = 0.00002;

    Matrix a(tab);

    CHECK (res == a(0,1));
}

TEST_CASE("M 4.03: operator ()"){
    double tab[2][2] = {{1,2},{-3,4}};
    double res = -3;

    Matrix a(tab);

    CHECK (res == a(1,0));
}

TEST_CASE("M 4.04: operator ()"){
    double tab[2][2] = {{1,2},{-3,0}};
    double res = 0;

    Matrix a(tab);

    CHECK (res == a(1,1));
}


TEST_CASE("R 1.01: konstruktor bezparametryczny prostokata i przeciazenie operatorow << >>"){
    //double tab[2][2] = {{3,1}};
    Rectangle a;
    Rectangle b;
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << b; // 

    CHECK (out.str() == out2.str());
}

TEST_CASE("R 1.02: konstruktor parametryczny prostokata i przeciazenie operatorow << >>"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    Rectangle b(a1);
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << b; // 

    CHECK (out.str() == out2.str());
}

TEST_CASE("R 1.03: konstruktor parametryczny prostokata i przeciazenie operatorow << >>"){
    double args[4][2]= {{200.0, 300.0},{300.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    Rectangle b(a1);
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << b; // 

    CHECK (out.str() == out2.str());
}

TEST_CASE("R 2.01: Rectangle::translate"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{200.0, 500.0},{200.0, 400.0},{400.0, 400.0},{400.0, 500.0}};
       Vector a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double tab[2] = {100,100};
    Vector trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("R 2.02: Rectangle::translate neg"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{0, 300.0},{0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double tab[2] = {-100,-100};
    Vector trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("R 2.03: Rectangle::translate diff"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{0, 350.0},{0, 250.0},{200.0, 250.0},{200.0, 350.0}};
       Vector a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double tab[2] = {-100,-50};
    Vector trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("R 3.01: Rectangle::rotate"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{-100.0, -400.0},{-100.0, -300.0},{-300.0, -300.0},{-300.0, -400.0}};
       Vector a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double ang = 180;


    CHECK (a.rotate(ang) == b);
}

TEST_CASE("R 3.02: Rectangle::rotate"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double ang = 360;


    CHECK (a.rotate(ang) == b);
}

TEST_CASE("R 4.01: Rectangle::check true"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    CHECK (a.check_rec()==1);
}

TEST_CASE("R 4.02: Rectangle::check false"){
    double args[4][2]= {{000.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    CHECK (a.check_rec()==1);
}

TEST_CASE("Mod 4.02: Matrix::gauss()"){
    double args[4][2]= {{000.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    CHECK (a.check_rec()==1);
}
/*
    std::istringstream in("(1+10i)");
    in >> x;
    std::ostringstream out;
    out << a; // 
    */