#ifndef _RECTANGLE
#define _RECTANGLE
#include <iostream>
#include "Forme.hpp"

class Rectangle : public Forme{
    int ordre;

    public:
      Rectangle(int a,int b, int c, int d);
      Rectangle();
      std::string toString();
      int getOrdre();
      void setOrdre(int i);
      ~Rectangle();
};
#endif