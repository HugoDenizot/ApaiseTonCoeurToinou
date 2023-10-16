#include <iostream>
using std::string;

const int taille=10;

class Point{
  int x;
  int y;

  public:
    Point(int i, int j);
    Point();
    int getX();
    int getY();
    void setX(int i);
    void setY(int i);
};

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
    string toString();
};

class Rectangle : public Forme{
    int ordre;

    public:
      Rectangle(int a,int b, int c, int d);
      Rectangle();
      string toString();
      int getOrdre();
      void setOrdre(int i);
};

class Cercle : public Forme{
    int ordre;

    public:
      Cercle(int x,int y, int w, int h);
      Cercle(int cx, int cy, int rayon);
      Cercle();
      string toString();
      int getRayon();
      void setRayon(int r);
      int getHauteur();
      int getLargeur();
      int getOrdre();
      void setOrdre(int i);
};



class Liste{
  Cercle cercles[taille];
  int nb_c;
  Rectangle rectangles[taille];
  int nb_r;
  int compteur;

  public:
    Liste();
    int getCompteur();
    string toString();
    void addRectangle(Rectangle r);
    void addCercle(Cercle c);
};














