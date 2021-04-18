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

    Rectangle a;
    a = *this;
    if (!a.check_len_opp()){
        std::cerr << "ERROR: przeciwlegle boki nie sa rowne!" << std::endl;
    }
}
/******************************************************************************
 |  Funkcja przesuniecia prostokata o wektor                                  |
 |  Argumenty:                                                                |
 |      Wektor przesuniecia                                                   |
 |  Zwraca:                                                                   |
 |      Prostokat z przesunietymi wierzcholkami o zadany wektor               |
 */
Rectangle Rectangle::translation(Vector const &tran) const
{
    Rectangle translated;
    translated.a = a + tran;
    translated.b = b + tran;
    translated.c = c + tran;
    translated.d = d + tran;

    return translated;
}
/******************************************************************************
 |  Funkcja zwracajaca wierzcholki prostokata (przypisuje je zmiennym)        |
 |  Argumenty:                                                                |
 |      Referencje wektorow aX,bX,cX,dX                                       |
 |  Zwraca:                                                                   |
 |      Zmienia wartosci wektorow z wejscia                                   |
 */
void Rectangle::get_rect( Vector &aX, Vector &bX, Vector &cX, Vector &dX) const
{

    aX = a;
    bX = b;
    cX = c;
    dX = d;

}
/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      Rec - prostokat.                                                      |
 */
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

/******************************************************************************
 | Obrot prostokata o kat theta wokol srodka ukladu wspolrzednych             |
 | Argumenty:                                                                 |
 |      theta - kat obrotu                                                    |
 | Zwraca:                                                                    |
 |      obrocony prostokat                                                    |
 */
Rectangle Rectangle::rotate(const double &theta) const{
    Rectangle rotated;
    
    rotated.a = a.rotate(theta);
    rotated.b = b.rotate(theta);
    rotated.c = c.rotate(theta);
    rotated.d = d.rotate(theta);

    return rotated;
}

bool Rectangle::check_len_opp() const{
Vector AB, CD, BC, DA;
AB = b-a;
CD = d-c;
BC = c-b;
DA = a-d;
std::cout << AB.get_len() << " " << CD.get_len() << " " << BC.get_len() << " " << DA.get_len() << std::endl;
if ((AB.get_len() == CD.get_len()) && (BC.get_len() == DA.get_len()))
    return 1;

else return 0;
}



bool Rectangle::check_angle_opp() const{
Vector AB, CD, BC, DA;
AB = b-a;
CD = d-c;
BC = c-b;
DA = a-d;
    return 0;
}