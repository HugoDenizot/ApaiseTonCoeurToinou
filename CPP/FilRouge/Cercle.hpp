#ifndef _CERCLE
#define _CERCLE
#include <iostream>
#include "Forme.hpp"

class Cercle : public Forme{
    int ordre;

    public:
      Cercle(int x,int y, int w, int h);
      Cercle(int cx, int cy, int rayon);
      Cercle();
      std::string toString();
      int getRayon();
      void setRayon(int r);
      int getHauteur();
      int getLargeur();
      int getOrdre();
      void setOrdre(int i);
      ~Cercle();
};

#endif