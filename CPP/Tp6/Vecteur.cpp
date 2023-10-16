#include "Vecteur.hpp"

Vecteur::Vecteur(int cap):capacite(cap),taille(0){
    tab=new float[capacite];
}

Vecteur::Vecteur():Vecteur(10){

}

int Vecteur::capacity() const{
    return capacite;
}

int Vecteur::size() const{
    return taille;
}

void Vecteur::push_back(float a){
    tab[taille]=a;
    taille++;
    if(taille==capacite){
        capacite=capacite*2;
        float *tab2=new float[capacite];
        memcpy(tab2,tab,taille*sizeof(float));
        delete[] tab;
        tab=tab2;
    }
    
}

Vecteur::~Vecteur(){
    delete[] tab;
    std::cout<<"Test destruction"<<std::endl;
}

// void Vecteur::push_back(float a) {
//     if (taille >= capacite) {
//         // si la capacité est insuffisante, on double la taille
//         capacite = capacite * 2;
//         float *tab2 = new float[capacite];
//         memcpy(tab2, tab, taille * sizeof(float));
//         delete[] tab;
//         tab = tab2;
//     }
//     tab[taille] = a;
//     taille++;
// }

float &  Vecteur::operator[](int index){
    if(index<0||!tab){
        throw OutOfRangeException();
    }else if(index>=capacite){
        throw std::bad_alloc();
    }
    return tab[index];
}