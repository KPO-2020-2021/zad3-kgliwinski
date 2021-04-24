#pragma once

#include"rectangle.hh"
#include <iostream>

class menu{

    private:

    bool open;

    public:
    
    menu();

    void init_menu(Vector const (&tab)[4]);

    void show_menu();

    void switch_menu(char oper);

    
};

