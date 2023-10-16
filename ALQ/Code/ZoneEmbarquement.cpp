#include "ZoneEmbarquement.hpp"
#include "Map.hpp"
extern Map m;

int ZoneEmbarquement::getNombrePersonneMax()
{
    return nombrePersonneMax;
}

int ZoneEmbarquement::getNbPersonneActuelle()
{
    return nombrePersonneActuelle;
}

string ZoneEmbarquement::getnomZoneEmarquement()
{
    return nomZoneEmbarquement

        ;
}

ZoneEmbarquement::ZoneEmbarquement()
{
    nombrePersonneMax = 100;
    nombrePersonneActuelle = 0;
    nomZoneEmbarquement = "Boutique";
}

ZoneEmbarquement::ZoneEmbarquement(int nbPersonne, string nom, Position p) : nombrePersonneMax(nbPersonne), nombrePersonneActuelle(0), nomZoneEmbarquement(nom)
{
    m.grille[p.getX()][p.getY()] = 5;
    m.tabZone[m.nbzonne] = this;
    m.nbzonne++;
    pos = p;
}
