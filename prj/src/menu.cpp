#include"menu.hh"
/******************************************************************************
 | Konstruktor bezparametryczny (jedyny) klasy menu                           |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
menu::menu(){
    open=1;
}
/******************************************************************************
 | Inicjuje menu                                                              |
 | Argumenty:                                                                 |
 |      \param[in] tab - tablica 4 wektorow                                   |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
void menu::init_menu(Vector const (&tab)[4]){
    char n;
    Rectangle rect(tab);
    show_menu();
    while(open){
        std::cin>>n;
        this->switch_menu(n, rect);
    }

}
/******************************************************************************
 | Wypisuje menu na standardowym wyjsciu                                      |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
void menu::show_menu(){
std::cout<<"o - obrot prostokata o zadany kat\n" ;
std::cout<<"p - przesuniecie prostokata o zadany wektor\n";
std::cout<<"w - wyswietlenie wspolrzednych wierzcholkow\n";
std::cout<<"m - wyswietl menu\n";
std::cout<<"k - koniec dzialania programu\n";
}
/******************************************************************************
 | Obsluga petli switch dla menu                                              |
 | Argumenty:                                                                 |
 |      \param[in] oper - opcja menu                                                |
 |      \param[in] rec - wczytywany prostokat                                  |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
void menu::switch_menu(const char &oper, Rectangle &rec){
    switch (oper){
        case 'o':
            rec = rec.rotation_n_times();
            rec.PrintRectangle();
            break;
        case 'p':
            rec = rec.translation();
            rec.PrintRectangle();
            break;
        case 'w':
            std::cout<<rec<<std::endl;
            break;
        case 'm':
            this->show_menu();
            break;
        case 'k':
            open=0;
            std::cout<<"Koniec dzialania programu"<<std::endl;
            break;
        default:
            std::cout<<"Bledna opcja"<<std::endl;
            break;
    }
}


