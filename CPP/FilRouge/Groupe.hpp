#ifndef _LISTE
#define _LISTE

#include <iostream>
#include "Cercle.hpp"
#include "Rectangle.hpp"

const int taille=10;

class Groupe:public Forme{
  Forme ** formes;
  int compteur;
  public:
    Groupe();
    int getCompteur();
    std::string toString();
    void addForme(Forme* f);
    ~Groupe();
    
};

#endif
