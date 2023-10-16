#include <iostream>

class Exemple {
 public:
  void afficher() {
     std::cout << "hello" << std::endl;
  }
};

int main(int, char **) {
  
  Exemple e;
  
  e.afficher();

  return 0;
}