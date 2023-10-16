#ifndef _FORME
#define _FORME
#include <iostream>
#include "Point.hpp"

enum class COULEURS {
  NOIR, BLANC, BLEU, VERT, ROUGE, JAUNE
};

class Forme{


  public:
    int h;
    int w;
    Point p{};
    COULEURS couleur = COULEURS::BLEU;
    static int nbForme;
    int id;
    Forme(int i, int j,Point p, COULEURS c);
    Forme();
    Forme(Point p, COULEURS c);
    int getH();
    int getW();
    int getX();
    Point & getPoint();
    COULEURS getCouleur();
    static int prochainId();
    int getId();
    void setCouleur(COULEURS c);
    void setX(int x);
    int getY();
    void setY(int y);
    void setH(int i);
    void setW(int i);
    static int getnbForme();
    virtual std::string toString();
    virtual ~Forme();
};

#endif