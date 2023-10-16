#include "sms.hpp"
#include <iostream>
Telephone::Telephone(std::string numero):numero(numero){

}

Telephone::Telephone():numero(""){

}

std::string Telephone::getNumero() const{
    return numero;
}

void Telephone::setNumero(std::string num){
    numero=num;
}

Reseau::Reseau():nbTel(0){
    
}

Telephone Reseau::trouveTel(std::string num){
    for(int i=0;i<nbTel;i++){
        if(tel[i]->getNumero()==num){
            return tel[i];
        }
    }
}


std::string Reseau::lister(){
    std::string s="";
    int indice;
    Telephone aux[nbTel];
    for(int i=0;i<nbTel;i++){
        aux[i]=*tel[i];
    }
    std::string mini,aux_s;
    for(int i=0;i<nbTel;i++){
        mini=aux[i].getNumero();
        indice=i;
        for(int j=i+1;j<nbTel;j++){
            if(mini>tel[j]->getNumero()){   
                mini=tel[j]->getNumero();
                indice=j;
            }
        }
        aux_s=aux[i].getNumero();
        if(indice!=i){
            aux[i].setNumero(aux[indice].getNumero());
            aux[indice].setNumero(aux_s);
        }
        
    }
    for(int i=0;i<nbTel;i++){
        s.append(aux[i].getNumero());
        s.append("\n");  
    }
    return s;
}

void Reseau::ajouter(std::string t){
    tel[nbTel]=new Telephone(t);
    nbTel++;
}