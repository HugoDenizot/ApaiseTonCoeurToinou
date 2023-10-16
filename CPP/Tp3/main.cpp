#include <iostream>
#include <sstream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;

class Mere{
    protected:
        static int a;

    public:
        string nom;

    public:
        Mere();
        Mere(string name);
        ~Mere();
        static int getCompteur();
        string getName();
        virtual void afficher();

};

int Mere::a=0;

class Fille:public Mere{

    public:
        Fille();
        Fille(string name);
        ~Fille();
        void afficher();
};

Mere::Mere(string name):nom(name){
    cout<<"Création d'une mere"<<endl;
    ++a;
    cout<<"Compteur : "<<a<<endl;
}

Mere::Mere(){
    cout<<"Création d'une mere"<<endl;
    ++a;
    cout<<"Compteur : "<<a<<endl;
}

Mere::~Mere(){
    cout<<"C'est fini pour la mere"<<endl;
}

string Mere::getName(){
    return nom;
}

Fille::Fille():Mere(){
    cout<<"Création d'une fille"<<endl;
}

Fille::Fille(string name):Mere(name){
    cout<<"Création d'une fille"<<endl;
}

Fille::~Fille(){
    cout<<"Destruction d'une fille"<<endl;
}

void Mere::afficher(){
    cout<<"Type Mere"<<endl;
}

void Fille::afficher(){
    cout<<"Type Fille"<<endl;
}

int Mere::getCompteur(){
    return a;
}

int main(int, char **) {
    Mere  *pm = new Mere("mere_dyn");
    Fille *pf = new Fille("fille_dyn");
    Mere  *pp = new Fille("fille vue comme mere");
    pm->afficher(); // affiche Mere
    pf->afficher(); // affiche Fille
    pp->afficher(); // affiche Fille
  return 0;
}