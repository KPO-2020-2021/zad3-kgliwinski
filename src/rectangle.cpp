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
    if (!a.check_rec()){
        Rectangle a;    
        *this = a;
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
 |      Wartosc logiczna: 1 - sa rowne, 0 - nie sa rowne oraz komunikat bledu |
 */
bool Rectangle::check_len_opp(Vector const (&vecs)[4]) const{

if (!(vecs[0].get_len() == vecs[2].get_len()) && (vecs[1].get_len() == vecs[3].get_len())){
    std::cerr << "ERROR: przeciwlegle boki nie sa rowne!" << std::endl;
    return 0;
}

return 1;
}

/******************************************************************************
 | Sprawdza czy wszystkie katy prostokata sa proste                           |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      Wartosc logiczna: 1 - sa , 0 - nie sa oraz komunikat bledu            |
 */
bool Rectangle::check_angle_rec(Vector const (&vecs)[4]) const{
    double A,B,C,D;
    A = vecs[0].get_slope_angle() - vecs[3].get_slope_angle();
    B = vecs[1].get_slope_angle() - vecs[0].get_slope_angle();
    C = vecs[2].get_slope_angle() - vecs[1].get_slope_angle();
    D = vecs[3].get_slope_angle() - vecs[2].get_slope_angle();
    //std::cout << A <<" "<< B << " "<< C <<" "<< D <<   std::endl;
    if (!(check_angle_straight(A) && check_angle_straight(B) 
 && check_angle_straight(C) && check_angle_straight(D))){
        std::cerr<<"Error: katy prostokata nie sa proste!"<<std::endl;
             return 0;
    }   
    return 1;
}

/******************************************************************************
 | Sprawdza czy wpojedynczy kat jest prosty                                   |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      Wartosc logiczna: 1 - sa , 0 - nie sa                                 |
 */
bool Rectangle::check_angle_straight(double ang) const{
    double a = abs(ang);
    if (!(a == 90 || a == 270))
        return 0;
    return 1;
}
/******************************************************************************
 | Sprawdza czy przeciwlegle boki prostokata sa oraz czy katy sa proste       |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      Wartosc logiczna: 1 - sa , 0 - nie sa                      |
 */
bool Rectangle::check_rec() const{
Vector sides[4];
//double angA,angB,angC,angD;
int i=1;
sides[0] = top[i]-top[i-1]; i++;
sides[1] = top[i]-top[i-1]; i++;
sides[2] = top[i]-top[i-1]; i++;
sides[3] = top[0]-top[i-1]; i++;

if (!check_len_opp(sides))
    return 0;

if(!check_angle_rec(sides))
    return 0;
return 1;
}


