#ifndef BAVARDE_GUARD
#define BAVARDE_GUARD
 
#include<iostream>

using std::cout;
using std::endl;

class Bavarde {
  int n;

  public:
    Bavarde(int a);
    Bavarde();
    int getN();
    void setN(int a);
    ~Bavarde();
    void afficher();
} bizarre(1);  //Variable de type bizare (globale)

Bavarde globale(2);

Bavarde::Bavarde(int a):n{a}{
   
    cout<<"Construction de "<<a<<endl;
}

Bavarde::Bavarde():Bavarde(0)
{    
}

int Bavarde::getN(){
    return n;
}

Bavarde::~Bavarde() {
  std::cout << "Tais-toi " << n << std::endl;
} 

void Bavarde::afficher(){
  cout<<"Affichage de "<<n<<endl;
}
#endif