#ifndef CPP6_PILE_HPP
#define CPP6_PILE_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;

class Pile{

    int capacite;
    int *tab;
    int taille;

    public:
        Pile(int cap);
        Pile();
        bool empty();
        int size();
        void push(int a);
        void pop();
        int top();
};
#endif