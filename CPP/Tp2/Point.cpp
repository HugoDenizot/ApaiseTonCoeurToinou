#include "Point.hpp" // Inclusion d'un fichier du répertoire courant

int Point::compteur=0;

Point::Point(){
    setX(1);
    setY(1);
    setTest(0);
    ++compteur;
}

Point::Point(int a, int b){
    setX(a);
    setY(b);
    setTest(0);
    ++compteur;
}

int Point::getX() {
  return x;
}

void Point::setX(int a){
    x=a;
}

int Point::getY() {
  return y;
}

void Point::setY(int a){
    y=a;
}

void Point::DeplacerDe(Point p){
    setX(getX()+p.getX());
    setY(getY()+p.getY());
}

void Point::DeplacerVers(Point p){
    setX(p.getX());
    setY(p.getY());
}

int Point::getCompteur(){
    return compteur;
}

int Point::getTest(){
    return test;
}

void Point::setTest(int a){
    test=a;
}