#include "matrix.hh"

/******************************************************************************
 *  Konstruktor klasy Matrix.                                                
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \param[out] Matrix jednostkowa                                       
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            if (i==j)
            value[i][j] = 1.0;
            else
            value[i][j] = 0.0;
        }
    }
}


/******************************************************************************
 *  Konstruktor parametryczny klasy Matrix.                                  
 *  Argumenty:                                                               
 *      \param[in] tmp - dwuwymiarowa tablica z elementami typu double.                 
 *  Zwraca:                                                                  
 *      \param[out] Matrix wypelniona wartosciami podanymi w argumencie.                
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}
/******************************************************************************
 *  Destruktor klasy Matrix.                                                 
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \post Usuwa klase                                                          
 */
Matrix::~Matrix(){
    //std::cout<<"Deleting matrix"<<std::endl;
}

/******************************************************************************
 *  Realizuje mnozenie macierzy przez wektor.                                
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik mnozenia,                    
 *      \param[in] tmp - wektor, czyli drugi skladnik mnozenia.                           
 *  Zwraca:                                                                  
 *      \param[out] result - Iloczyn dwoch skladnikow przekazanych jako wektor.                   
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 *  Funktor macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] row - numer wiersza.                                                 
 *      \param[in] column - numer kolumny.                                              
 *  Zwraca:                                                                  
 *      \param[out] value Wartosc macierzy w danym miejscu tablicy.                            
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 *  Funktor macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] row - numer wiersza.                                                 
 *      \param[in] column - numer kolumny.                                              
 *  Zwraca:                                                                  
 *      \param[out] Wartosc macierzy w danym miejscu tablicy jako stala.                 
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 *  Przeciążenie dodawania macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik dodawania,                    
 *      \param[in] v - wektor, czyli drugi skladnik dodawania.                                              
 *  Zwraca:                                                                  
 *      \param[out] Macierz - iloczyn dwóch podanych macierzy.                 
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 *  Przeciazenie operatora >>                                                
 *  Argumenty:                                                               
 *      \param[in] in - strumien wejsciowy,                                             
 *      \param[in] mat - macierz. 
 *  Zwraca:
 *      \param[out] in - strumien wejsciowy                                                       
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 *  Przeciazenie operatora <<                                                
 *  Argumenty:                                                               
 *      \param[in] out - strumien wyjsciowy,                                            
 *      \param[in] mat - macierz.     
 *  Zwraca:
 *      \param[out] out - strumien wyjsciowy                                                  
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    out.precision(10);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            out << "| " <<std::setw(10) << std::fixed << std::setprecision(10) << mat(i, j) << " * "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
/******************************************************************************
 *  Przeciążenie == macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, ktora porownujemy                   
 *      \param[in] tmp - macierz, z ktora porownujemy                                                          
 *  Zwraca:                                                                  
 *      \retval true - jesli sa rowne
 *      \retval false - jesli nie sa                
 */
bool Matrix::operator == (Matrix const &tmp) const{
    int i,j;
    for (i=0;i<SIZE;++i){
        for (j=0;j<SIZE;++j){
            if (!(abs(value[i][j]-tmp.value[i][j])<=0.000001))
                return 0;
        }
    }
    return 1;
}