#include <iostream>
#include <sstream>
#include <cstdlib>
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

class Couple{
    Bavarde b1;
    Bavarde b2;

    public:
        Couple(int a,int b);
        Couple();

};

Couple::Couple(int a, int b):b1(a),b2(b){

}

Couple::Couple():b1(0),b2(0){
    
}

class Famille{
  Bavarde *tab;
  int taille;

  public:
    Famille();
    Famille(int size);
    ~Famille();
};

Famille::Famille():tab(nullptr),taille(20){
        tab=new Bavarde[taille];
}

Famille::Famille(int size):tab(nullptr),taille(size){
        tab=new Bavarde[taille];
}

Famille::~Famille(){
  if(tab)
    delete []tab;
}

int main(int, char **) {
  //Couple c1{},c2{},c3{};
  //Famille f();
  Bavarde *b=new Bavarde();
  b->afficher();
  delete b;
  return 0;
}

