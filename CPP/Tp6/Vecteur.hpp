#ifndef CPP6_VECTEUR_HPP
#define CPP6_VECTEUR_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>

class Vecteur{
    int capacite;
    float *tab;
    public:
        int taille;
        class OutOfRangeException{};

    public:
        Vecteur();
        Vecteur(int cap);
        int capacity() const;
        int size() const;
        void push_back(float a);
        void setSize(int t);
        float &  operator[](int index);
        ~Vecteur();
};

#endif