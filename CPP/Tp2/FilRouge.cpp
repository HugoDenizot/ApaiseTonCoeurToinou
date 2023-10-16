#include "FilRouge.hpp"
#include <sstream>
using std::cout;
using std::endl;

int Forme::nbForme=0;

Point::Point(int i, int j):x{i},y{j}{

}

Point::Point():x{0},y{0}{

}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

void Point::setX(int i){
    x=i;
}

void Point::setY(int i){
    y=i;
}

Rectangle::Rectangle(int a, int b, int c, int d):Forme(c,d,{a,b},COULEURS::BLEU){

}

Rectangle::Rectangle():Rectangle(0,0,1,1){
    
}

string Rectangle::toString(){
    std::ostringstream oss;
    oss<<"RECTANGLE "<<Forme::toString();;
    return oss.str();
}

Cercle::Cercle(int a, int b, int c, int d):Forme(c,d,{a,b},COULEURS::BLEU){

}

Cercle::Cercle(int cx, int cy, int rayon):Cercle(rayon+cx,rayon+cy,rayon*2,rayon*2){

}

Cercle::Cercle():Cercle(0,0,1,1){

}

string Cercle::toString(){
    std::ostringstream oss;
    oss<<"CERCLE "<<Forme::toString();
    return oss.str();
}

int Cercle::getRayon(){
    return w/2;
}

void Cercle::setRayon(int r){
    h=r*2;
    w=r*2;
}

int Cercle::getLargeur(){
    return w;
}

int Cercle::getHauteur(){
    return h;
}

int Cercle::getOrdre(){
    return ordre;
}

int Rectangle::getOrdre(){
    return ordre;
}

Liste::Liste(){

    nb_c=0;
    nb_r=0;
    compteur=0;
}

void Cercle::setOrdre(int i){
    ordre=i;
}

void Rectangle::setOrdre(int i){
    ordre=i;
}

int Liste::getCompteur(){
    return compteur;
}

void Liste::addCercle(Cercle c){
    cercles[nb_c]=c;
    c.setOrdre(compteur);
    nb_c++;
    compteur++;
}

void Liste::addRectangle(Rectangle r){
    rectangles[nb_r]=r;
    r.setOrdre(compteur);
    nb_r++;
    compteur++;
}

string Liste::toString(){
    int positionC=0;
    int positionR=0;
    int positionGen=0;
    std::ostringstream oss;

    while(positionGen<compteur){
        if(cercles[positionC].getOrdre()==positionGen){
            oss<<cercles[positionC].toString()<<endl;        
            positionC++;
        }else{
            oss<<rectangles[positionR].toString()<<endl;        
            positionR++;
        }
        positionGen++;
    }

    return oss.str();
    
}




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