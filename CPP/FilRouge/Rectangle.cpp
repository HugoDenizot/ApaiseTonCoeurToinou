#include "Rectangle.hpp"
#include <sstream>
using std::cout;
using std::endl;
using std::string;

Rectangle::Rectangle(int a, int b, int c, int d):Forme(c,d,{a,b},COULEURS::BLEU){

}

Rectangle::Rectangle():Rectangle(0,0,1,1){
    
}

string Rectangle::toString(){
    std::ostringstream oss;
    oss<<"RECTANGLE "<<Forme::toString();;
    return oss.str();
}

int Rectangle::getOrdre(){
    return ordre;
}


void Rectangle::setOrdre(int i){
    ordre=i;
}

Rectangle::~Rectangle(){
    
}