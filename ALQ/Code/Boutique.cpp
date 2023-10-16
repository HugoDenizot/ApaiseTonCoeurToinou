#include "Boutique.hpp"
#include "Map.hpp"
extern Map m;

int Boutique::getNbPersonneMax()
{
    return nombrePersonneMax;
}

int Boutique::getNbPersonneActuelle()
{
    return nombrePersonneActuel;
}

string Boutique::getnomBoutique()
{
    return nomBoutique;
}

Boutique::Boutique(int nbPersonne, string nom, Position p) : nombrePersonneMax(nbPersonne), nomBoutique(nom), nombrePersonneActuel(0)
{
    m.grille[p.getX()][p.getY()] = 3;
    m.tabZone[m.nbzonne] = this;
    m.nbzonne++;
    pos = p;
}

Boutique::Boutique()
{
}