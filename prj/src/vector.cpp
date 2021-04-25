#include "vector.hh"
#include "matrix.hh"
/******************************************************************************
 *  Konstruktor klasy Vector.                                                
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \param[out] this -  Wektory wypelniony wartoscia 0.                                      
 */
Vector::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = 0.0;
    }
}

/******************************************************************************
 *  Konstruktor klasy Vector.                                                
 *  Argumenty:                                                               
 *      \param[in] tmp - Jednowymiarowa tablica typu double.                            
 *  Zwraca:                                                                  
 *      \param[in] this - Tablice wypelniona wartosciami podanymi w argumencie.                
 */

Vector::Vector(double tmp[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = tmp[i];
    }
}


/******************************************************************************
 *  Destruktor klasy Vector.                                                 
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \post Usuwa wektor                                                         
 */
Vector::~Vector(){
    //std::cout<<"Deleting vector"<<std::endl;
}
/******************************************************************************
 *  Realizuje dodawanie dwoch wektorow.                                      
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik dodawania,                                  
 *      \param[in] v - drugi skladnik dodawania.                                        
 *  Zwraca:                                                                  
 *      \param[out] result - Sume dwoch skladnikow przekazanych jako wskaznik                     
 *      na parametr.                                                         
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
 *  Realizuje odejmowanie dwoch wektorow.                                    
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik odejmowania,                                
 *      \param[in] v - drugi skladnik odejmowania.                                      
 *  Zwraca:                                                                  
 *      \param[in] result - Roznice dwoch skladnikow przekazanych jako wskaznik                  
 *      na parametr.                                                         
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
 *  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.              
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik mnozenia (wektor),                          
 *      \param[in] v - drugi skladnik mnozenia (liczba typu double).                    
 *  Zwraca:                                                                  
 *      \param[in] result - Iloczyn dwoch skladnikow przekazanych jako wskaznik                  
 *      na parametr.                                                         
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
 *  Realizuje dzielenie dwoch wektorow.                                      
 *  Argumenty:                                                               
 *      \param[in] this - licznik dzielenia,                                            
 *      \param[in] v - mianownik dzielenia.                                             
 *  Zwraca:                                                                  
 *      \param[in] result - Iloraz dwoch skladnikow przekazanych jako wskaznik                   
 *      na parametr.                                                         
 */

Vector Vector::operator/(const double &tmp) const
{
    Vector result;
    if (tmp==0){
        std::cerr << "ERROR: Nie mozna dzielic przez 0" << std::endl;
        return *this;
    }
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}
/******************************************************************************
 *  Sprawdza czy wektory sa rowne                                      
 *  Argumenty:                                                               
 *      \param[in] this - l,                                            
 *      \param[in] v - r.                                             
 *  Zwraca:                                                                  
 *     \retval true - sa rowne
 *     \retval false - nie sa rowne                                                        
 */
bool  Vector::operator == (const Vector &v) const{
    int i;
    for (i=0;i<SIZE;i++){
        if (!((abs(size[i] - v.size[i]) <= 0.000001)))
            return 0;
    }
    return 1;
}

/******************************************************************************
 *  Funktor wektora.                                                         
 *  Argumenty:                                                               
 *      \param[in] index - index wektora.                                               
 *  Zwraca:                                                                  
 *      \param[in] size - Wartosc wektora w danym miejscu tablicy jako stala.                  
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
 *  Funktor wektora.                                                         
 *  Argumenty:                                                               
 *      \param[in] index - index wektora.                                               
 *  Zwraca:                                                                  
 *      \param[in] Vector - Wartosc wektora w danym miejscu tablicy.                             
 */
double &Vector::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}

/******************************************************************************
 *  Przeciazenie operatora <<                                                
 *  Argumenty:                                                               
 *      \param[in] out - strumien wyjsciowy,                                            
 *      \param[in] tmp - wektor.   
 *  Zwraca:
 *      \param[out] out - strumien wyjsciowy                                                     
 */
std::ostream &operator<<(std::ostream &out, Vector const &tmp)
{
    out.precision(10);
    for (int i = 0; i < SIZE; ++i)
    {
        out << "[ " ;
        out << std::setw(10) << std::fixed << std::setprecision(10) << tmp[i];
        out << " ]\n";
    }
    return out;
}

/******************************************************************************
 *  Przeciazenie operatora >>                                                
 *  Argumenty:                                                               
 *      \param[in] in - strumien wejsciowy,                                             
 *      \param[in] tmp - wektor.   
 *  Zwraca:
 *      \param[out] in - strumien wejsciowy                                                     
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
 * Obrot wektora o kat theta wokol srodka ukladu wspolrzednych               
 * Argumenty:                                                                
 *      \param[in] theta - kat obrotu ( w stopniach )                                   
 * Zwraca:                                                                   
 *      \param[out] rotated - obrocony wektor                                                      
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
 * Zwraca kwadrat modulu wektora                                             
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[out] result - kwadrat modulu wektora                                               
 */
double Vector::modulus2() const
{
    int i;
    double result=0;

    for (i = 0; i < SIZE; i++)
    {
        result += pow(size[i], 2);
    }
    return result;
}
/******************************************************************************
 * Zwraca dlugosc wektora                                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[out] len - dlugosc wektora                                                      
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
 * Zwraca kat nachylenia wektora do osi x                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[in] angle - kat nachylenia wektora do osi x                                                      
 */
double Vector::get_slope_angle() const
{
    double angle;
    if (SIZE == 2)
    {
        angle = atan2(size[1], size[0]);
        angle *= 180 / PI;
    }
    else
    {
    std::cerr << 
    "ERROR: Nie zdefiniowano kata nachylenia dla wektorow innych niz dwuwymiarowych."
    << std::endl;
    angle = 0;
    }
    return angle;
}

