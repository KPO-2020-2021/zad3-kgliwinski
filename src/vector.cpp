#include "vector.hh"
#include "matrix.hh"
/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Vector::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = 0;
    }
}

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Vector::Vector(double tmp[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = tmp[i];
    }
}

/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Vector Vector::operator+(const Vector &v) const
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] + v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Vector Vector::operator-(const Vector &v) const
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] - v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

Vector Vector::operator*(const double &tmp) const
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] * tmp;
    }
    return result;
}

/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

Vector Vector::operator/(const double &tmp) const
{
    Vector result;

    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Vector::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
double &Vector::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream &operator<<(std::ostream &out, Vector const &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
std::istream &operator>>(std::istream &in, Vector &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

/******************************************************************************
 | Obrot wektora o kat theta wokol srodka ukladu wspolrzednych                |
 | Argumenty:                                                                 |
 |      theta - kat obrotu ( w stopniach )                                    |
 | Zwraca:                                                                    |
 |      obrocony wektor                                                       |
 */

Vector Vector::rotate(const double &theta) const
{
    Vector rotated;
    double theta_rad = theta * PI / 180;
    if (SIZE == 2)
    {
        double tmp[][SIZE] = {{cos(theta_rad), -sin(theta_rad)}, {sin(theta_rad), cos(theta_rad)}};
        Matrix transformation(tmp);
        rotated = transformation * *this;
    }
    else
    {
        std::cerr << "ERROR: Nie zdefiniowano macierzy obrotu dla przestrzeni innej niz dwuwymiarowa." << std::endl;
    }
    return rotated;
}

/******************************************************************************
 | Zwraca kwadrat modulu wektora                                              |
 | Argumenty:                                                                 |
 |      Brak                                                                  |
 | Zwraca:                                                                    |
 |      kwadrat modulu wektora                                                |
 */
double Vector::modulus2() const
{
    int i;
    double result;

    for (i = 0; i < SIZE; i++)
    {
        result += pow(size[i], 2);
    }
    return result;
}
/******************************************************************************
 | Zwraca dlugosc wektora                                                     |
 | Argumenty:                                                                 |
 |      Brak                                                                  |
 | Zwraca:                                                                    |
 |      dlugosc wektora                                                       |
 */
double Vector::get_len() const
{
    double len, mod2;
    Vector tmp;
    tmp = *this;
    mod2 = tmp.modulus2();
    len = pow(mod2, 1.0 / SIZE);

    return len;
}

/******************************************************************************
 | Zwraca kat nachylenia wektora do osi x                                     |
 | Argumenty:                                                                 |
 |      Brak                                                                  |
 | Zwraca:                                                                    |
 |      kat nachylenia w                                                       |
 */
double Vector::get_slope_angle() const
{
    double angle;
    if (SIZE == 2)
    {
        angle = atan2(size[0], size[1]);
        angle *= 180 / PI;
    }
    else
    {
        std::cerr << "ERROR: Nie zdefiniowano kata nachylenia dla wektorow innych niz dwuwymiarowych." << std::endl;
        angle = 0;
    }
    return angle;
}