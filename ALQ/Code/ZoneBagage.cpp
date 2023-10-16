#include <iostream>
#include "ZoneBagage.hpp"
#include "Map.hpp"
extern Map m;

ZoneBagage::ZoneBagage()
{
}

ZoneBagage::ZoneBagage(Position p)
{
    m.grille[p.getX()][p.getY()] = 4;
    m.tabZone[m.nbzonne] = this;
    m.nbzonne++;
    pos = p;
}
