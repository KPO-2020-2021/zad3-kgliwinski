#include "rectangle.hh"
/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Cztery wierzcholki prostokata                                         |
 */
Rectangle::Rectangle()
{
    double args1[2] = {1, 1}, args2[2] = {-1, 1}, args3[2] = {-1, -1}, args4[2] = {1, -1};
    a = Vector(args1);
    b = Vector(args2);
    c = Vector(args3);
    d = Vector(args4);
}
/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      aX, bX, cX, dX - cztery wektory reprezentujace polozenie wierzcholkow |
 |  Zwraca:                                                                   |
 |      Cztery wierzcholki prostokata opisane przez podane wektory            |
 */
Rectangle::Rectangle(Vector const &aX, Vector const &bX, Vector const &cX, Vector const &dX)
{
    a = aX;
    b = bX;
    c = cX;
    d = dX;
}
/******************************************************************************
 |  Funkcja przesuniecia prostokata o wektor                                  |
 |  Argumenty:                                                                |
 |      Wektor przesuniecia                                                   |
 |  Zwraca:                                                                   |
 |      Prostokat z przesunietymi wierzcholkami o zadany wektor               |
 */
Rectangle Rectangle::translation(Vector const &tran)
{
    Rectangle translated;
    translated.a = a + tran;
    translated.b = b + tran;
    translated.c = c + tran;
    translated.d = d + tran;

    return translated;
}

void Rectangle::get_rect( Vector &aX, Vector &bX, Vector &cX, Vector &dX) const
{

    aX = a;
    bX = b;
    cX = c;
    dX = d;

}

std::ostream &operator<<(std::ostream &out, Rectangle const &Rec)
{
    Vector aX, bX, cX, dX;
    Rec.get_rect( aX, bX, cX, dX);
    out << "Wierzcholek A: " << std::endl << aX << std::endl;
    out << "Wierzcholek B: " << std::endl << bX << std::endl;
    out << "Wierzcholek C: " << std::endl << cX << std::endl;
    out << "Wierzcholek D: " << std::endl << dX << std::endl;

    return out;
}