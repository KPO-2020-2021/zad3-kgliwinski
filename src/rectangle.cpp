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
    double iter[SIZE];
    int i;
    iter[0]=1;iter[1]=1;
    for (i=2;i<SIZE;++i)
        iter[i]=0;
    top[0] = Vector(iter);
    iter[1]=-1; top[1]=Vector(iter);
    iter[0]=-1; top[2]=Vector(iter);
    iter[1]=1; top[3]=Vector(iter);
}
/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      aX, bX, cX, dX - cztery wektory reprezentujace polozenie wierzcholkow |
 |  Zwraca:                                                                   |
 |      Cztery wierzcholki prostokata opisane przez podane wektory            |
 */
Rectangle::Rectangle(Vector const (&tab)[4])
{
    int i;
    for (i=0;i<4; ++i){
        top[i]=tab[i];
    }

    Rectangle a=*this;
    if (!a.check_len_opp()){
        std::cerr << "ERROR: przeciwlegle boki nie sa rowne!" << std::endl;
    }
    if (!a.check_angle_rec()){
        std::cerr << "ERROR: przeciwlegle boki nie sa rownolegle!" << std::endl;
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
    int i;
    for (i=0;i<4;++i){
        translated.top[i] = top[i] + tran;
    }

    return translated;
}
/******************************************************************************
 |  Funkcja zwracajaca wierzcholki prostokata (przypisuje je zmiennym)        |
 |  Argumenty:                                                                |
 |      Referencje wektorow aX,bX,cX,dX                                       |
 |  Zwraca:                                                                   |
 |      Zmienia wartosci wektorow z wejscia                                   |
 */
void Rectangle::get_rect( Vector (&tab)[4]) const
{
    int i;
    for (i=0;i<4;i++){
        tab[i]=top[i];
    }
}
/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      Rec - prostokat.                                                      |
 */
std::ostream &operator<<(std::ostream &out, Rectangle const &Rec)
{
    Vector vecs[4];
    Rec.get_rect( vecs);
    out << "Wierzcholek A: " << std::endl << vecs[0] << std::endl;
    out << "Wierzcholek B: " << std::endl << vecs[1] << std::endl;
    out << "Wierzcholek C: " << std::endl << vecs[2] << std::endl;
    out << "Wierzcholek D: " << std::endl << vecs[3] << std::endl;

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
    
    rotated.top[0] = top[0].rotate(theta);
    rotated.top[1] = top[1].rotate(theta);
    rotated.top[2] = top[2].rotate(theta);
    rotated.top[3] = top[3].rotate(theta);

    return rotated;
}
/******************************************************************************
 | Sprawdza czy przeciwlegle boki prostokata sa rownej dlugosci               |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      Wartosc logiczna: 1 - sa rowne, 0 - nie sa rowne                      |
 */
bool Rectangle::check_len_opp() const{
Vector AB, CD, BC, DA;
int i=1;
AB = top[i]-top[i-1]; i++;
CD = top[i]-top[i-1]; i++;
BC = top[i]-top[i-1]; i++;
DA = top[0]-top[i-1]; i++;

if ((AB.get_len() == CD.get_len()) && (BC.get_len() == DA.get_len()))
    return 1;

else return 0;
}


/******************************************************************************
 | Sprawdza czy wszystkie katy prostokata sa proste                           |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      Wartosc logiczna: 1 - sa , 0 - nie sa                                 |
 */
bool Rectangle::check_angle_rec() const{
int i;
Vector AB, CD, BC, DA;
double angAB,angBC,angCD,angDA;
i=1;
AB = top[i]-top[i-1]; i++;
CD = top[i]-top[i-1]; i++;
BC = top[i]-top[i-1]; i++;
DA = top[0]-top[i-1]; i++;

angAB = AB.get_slope_angle(); angBC = BC.get_slope_angle(); angCD = CD.get_slope_angle(); angDA = DA.get_slope_angle();
/*  zgodnie z definicja atan2 moze zwracac wartosci z przedzialu (-180,180), 
    stad wektory o nachyleniu B oraz 180-B sa rownolegle */
    std::cout<<angAB<<" "<<angBC<<" "<<angCD<<" "<<angDA<<std::endl;
if (!((angAB == angCD) || (angAB == 180-angCD)) || !((angBC == angDA) || (angBC) == 180-angCD))
    return 0;
else
    return 1;
}