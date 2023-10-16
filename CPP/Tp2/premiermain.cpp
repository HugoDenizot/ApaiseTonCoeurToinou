//#include "Point.hpp"


// int main(int argc, char ** argv) {
//   cout<<"Compteur: "<<Point::getCompteur()<<endl;
//   Point *p=new Point(1,1);
//   cout<<"Compteur: "<<Point::getCompteur()<<endl;
//   Point z{2,5};
//   cout<<"Compteur: "<<Point::getCompteur()<<endl;
//   std::cout<<"pos X: "<<p->getX()<<" et posY: "<<p->getY()<<endl;
//   std::cout<<"pos X: "<<z.getX()<<" et posY: "<<z.getY()<<endl;
//   p->DeplacerDe(z);
//   std::cout<<"pos X: "<<p->getX()<<" et posY: "<<p->getY()<<endl;
//   p->DeplacerVers(z);
//   std::cout<<"pos X: "<<p->getX()<<" et posY: "<<p->getY()<<endl;
  
//   delete(p);
//   return 0;
// }

#include <iostream>
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
} bizarre(1);  //Variable de type bizare (globale)

Bavarde globale(2);

Bavarde::Bavarde(int a):n{a}{
   
    cout<<"Construction de "<<a<<endl;
}

Bavarde::Bavarde():Bavarde(42)
{    
}

int Bavarde::getN(){
    return n;
}

Bavarde::~Bavarde() {
  std::cout << "Tais-toi " << n << std::endl;
} 

int main(int, char **) {
  Bavarde b1(3);
  Bavarde b2(4);
  Bavarde * p = new Bavarde(5);
  std::cout << Bavarde(0).getN() << std::endl;
  delete(p);
  return 0;
}
