#include "Groupe.hpp"
#include <sstream>
using std::cout;
using std::endl;
using std::string;

Groupe::Groupe(){
    formes =new Forme*[taille];
    compteur=0;
}

int Groupe::getCompteur(){
    return compteur;
}


void Groupe::addForme(Forme* f){
    formes[compteur]=f;
    compteur++;
    
}


string Groupe::toString(){
    int positionGen=0;
    std::ostringstream oss;
    oss<<"GROUPE "<<Forme::toString()<<" ";
    while(positionGen<compteur){
        oss<<formes[positionGen]->toString()<<endl;
        positionGen++;
    }

    return oss.str();  
}

Groupe::~Groupe(){
    delete[] formes;
}