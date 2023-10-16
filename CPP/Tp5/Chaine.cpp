#include "Chaine.hpp"
#include <cstring>
#include <sstream>
#include <exception>

Chaine::Chaine():capacite{0},tab{nullptr}{

}

Chaine::Chaine(const char* inCs){
    if(inCs){
        capacite=strlen(inCs)+1;
        tab=new char[capacite];
        strcpy(tab,inCs);
    }else{
        capacite=0;
        tab=nullptr;
    }
}

Chaine::Chaine(const int inCapacite){
    if(inCapacite==0){
        capacite=0;
        tab=nullptr;
    }else{
        capacite=inCapacite+1;
        tab=new char(capacite+1);

    }
}

// Chaine::Chaine(const int inCapacite):capacite{inCapacite+1},tab{new char[capacite+1]}{
//     tab[0]='\0';
// }

Chaine::Chaine(const Chaine &uC){
    capacite=uC.capacite;
    if(capacite){
        tab=new char[capacite];
        strcpy(tab,uC.tab);
    }else{
        tab=nullptr;
    }
    std::cout<<"Constructeur de copie appelé"<<std::endl;
}

std::ostream& operator<<(std::ostream &o, const Chaine &c){
    
    if(c.toCstr())
        o<<c.toCstr();
    return o;
}

// std::ostream& operator<<(const Chaine &c){
//     std::ostream o;
//     if(c.toCstr()){
//         for(int i=0;i<c.getCapacite();i++){
//             o<<c[i]<<std::endl;
//         }
//     }
// }

void Chaine::afficher(std::ostream &o) const{
    if(tab)
        o<<tab;
}

void Chaine::afficher() const{
    
}

int Chaine::getCapacite() const{
    return capacite-1;
}

char* Chaine::c_str() const{
    return tab;
}

const char* Chaine::toCstr() const{
    return tab;
}

Chaine::~Chaine(){
    delete[] tab;
}

Chaine& Chaine::operator=(const Chaine &uc){
    if(&uc!=this){
        delete []tab;
        capacite=uc.capacite;
        if(capacite){
            tab=new char[capacite];
            strcpy(tab,uc.tab);
        }
        else{
            tab=nullptr;
        }
    }
    return *this;
}

char& Chaine::at(int index){
    if(index<0||(index>=capacite)||!tab){
        std::cerr<<"erreur index"<<std::endl;
        std::exit(1);
    }
    return tab[index];
}

// char const &  Chaine::operator[](int index){
//     if(index<0||(index>=capacite)||!tab){
//         std::cerr<<"erreur index"<<std:: endl;
//         std::exit(1);
//     }
//     return tab[index];
// }

char &  Chaine::operator[](int index){
    std::cout<<capacite<<std::endl;
    if(tab==nullptr){
        throw null_pointer();
    }else if(index<0){
        throw std::out_of_range("Trop petit indice");
    }
    else if(index>=capacite){
        throw std::bad_alloc();
    }
    return tab[index];
}


Chaine operator+(const Chaine &a,const Chaine &b){
    char *tab=new char[a.getCapacite()+b.getCapacite()-1];
    strcpy(tab,a.toCstr());
    strcat(tab,b.toCstr());
    Chaine temp(tab);
    delete [] tab;

    return temp;
}