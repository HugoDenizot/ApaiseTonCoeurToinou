#include "Cercle.hpp"
#include <sstream>
using std::cout;
using std::endl;
using std::string;

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

void Cercle::setOrdre(int i){
    ordre=i;
}

Cercle::~Cercle(){

}