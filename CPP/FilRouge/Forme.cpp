#include "Forme.hpp"

#include <sstream>
using std::cout;
using std::endl;
using std::string;

int Forme::nbForme=0;

Forme::Forme(int i, int j,Point p, COULEURS c):h{i},w{j},p{p},couleur{c},id{nbForme}{
    nbForme++;
}

Forme::Forme():Forme(0,0,{},COULEURS::BLEU){

}

int Forme::getH(){
    return h;
}

int Forme::getW(){
    return w;
}

void Forme::setH(int i){
    h=i;
}

void Forme::setW(int i){
    w=i;
}

int Forme::getnbForme(){
    return nbForme;
}

Point& Forme::getPoint(){
    return p;
}

COULEURS Forme::getCouleur(){
    return couleur;
}

void Forme::setX(int x){
    p.setX(x);
}

void Forme::setY(int y){
    p.setY(y);
}

void Forme::setCouleur(COULEURS c){
    couleur=c;
}

Forme::Forme(Point p, COULEURS c):Forme(0,0,p,c){

}

int Forme::prochainId(){
    return nbForme;
}

int Forme::getId(){
    return id;
}

string Forme::toString(){
    std::ostringstream oss;
    oss<<p.getX()<<" "<<p.getY()<<" "<<w<<" "<<h;
    return oss.str();
}

Forme::~Forme(){
    
}