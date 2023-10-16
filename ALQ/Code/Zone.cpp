#include <iostream> // Inclusion d'un fichier standard
#include "Zone.hpp" // Inclusion d'un fichier du répertoire courant

Position Zone::getPos()
{
    return pos;
}

void Zone::setPos(Position p)
{
    pos = p;
}

Zone::~Zone() {}