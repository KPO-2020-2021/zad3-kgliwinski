#include"menu.hh"

menu::menu(){
    open=1;
}

void menu::init_menu(Vector const (&tab)[4]){
    //char n;
    Rectangle rect(tab);
    show_menu();
    while(open){
        
    }

}

void menu::show_menu(){
std::cout<<"o - obrot prostokata o zadany kat\n" ;
std::cout<<"p - przesuniecie prostokata o zadany wektor\n";
std::cout<<"w - wyswietlenie wspolrzednych wierzcholkow\n";
std::cout<<"m - wyswietl menu\n";
std::cout<<"k - koniec dzialania programu\n";
}

void menu::switch_menu(char oper){
    switch (oper){
        case 'o':
            break;
    }
}