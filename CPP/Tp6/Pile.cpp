#include "Pile.hpp"

Pile::Pile(int cap):capacite(cap),taille(0){
    tab=new int[capacite];
}

Pile::Pile():Pile(10){
}

bool Pile::empty(){
    if(taille==0){
        return true;
    }else{
        return false;
    }
}

int Pile::size(){
    return taille;
}

void Pile::pop(){
    tab[taille-1]=NULL;
    taille-=1;
}

int Pile::top(){
    return tab[taille-1];
}

void Pile::push(int a){
    tab[taille]=a;
    taille++;
}