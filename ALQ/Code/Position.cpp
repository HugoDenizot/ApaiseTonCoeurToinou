#include <iostream>     // Inclusion d'un fichier standard
#include "Position.hpp" // Inclusion d'un fichier du répertoire courant

int Position::getX()
{
  return x;
}

int Position::getY()
{
  return y;
}

void Position::setX(int posX)
{
  x = posX;
}

void Position::setY(int posY)
{
  y = posY;
}

Position::Position() {}

Position::Position(int a, int b) : x{a}, y{b}
{
}