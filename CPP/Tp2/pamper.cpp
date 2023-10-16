#include <iostream>

class Tableau 
{
   int * tab;
   int taille;

 public:
   Tableau():tab(nullptr), taille(10) 
   {
       tab = new int[taille];
       for(int i=0;i<taille;i++){
        tab[i]=i;
       }
   }
   ~Tableau();
   void Afficher();

};

void Tableau::Afficher(){
    for(int i=0;i<taille;i++){
        std::cout<<tab[i]<<std::endl;
    }
}

Tableau::~Tableau(){
    delete[] tab;
    std::cout<<"Test destruction"<<std::endl;
}

int main(int, char **)
{
   Tableau t;
   t.Afficher();
   return 0;
}